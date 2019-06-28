#include <cstdio>
#include <getopt.h> // to parse long arguments.
#include <string>
#include <cstring>
#include <vector>
#include <iomanip>
#include <fstream>
using std::string;
#include <iostream>
using std::cin;
using std::cout;
using namespace std;

static const char* usage =
"Usage: %s [OPTIONS]...\n"
"Limited clone of uniq.  Supported options:\n\n"
"   -c,--count         prefix lines by their counts.\n"
"   -d,--repeated      only print duplicate lines.\n"
"   -u,--unique        only print lines that are unique.\n"
"   --help             show this message and exit.\n";

int main(int argc, char *argv[]) {
	// define long options
	static int showcount=0, dupsonly=0, uniqonly=0;
	static struct option long_opts[] = {
		{"count",         no_argument, 0, 'c'},
		{"repeated",      no_argument, 0, 'd'},
		{"unique",        no_argument, 0, 'u'},
		{"help",          no_argument, 0, 'h'},
		{0,0,0,0}
	};
	// process options:
	char c;
	int opt_index = 0;
	while ((c = getopt_long(argc, argv, "cduh", long_opts, &opt_index)) != -1) {
		switch (c) {
			case 'c':
				showcount = 1;
				break;
			case 'd':
				dupsonly = 1;
				break;
			case 'u':
				uniqonly = 1;
				break;
			case 'h':
				printf(usage,argv[0]);
				return 0;
			case '?':
				printf(usage,argv[0]);
				return 1;
		}
	}
	/* TODO: write me... */
  vector <string> v;
  string x;
  string y;
  //ifstream readfile(stdin);
  if(cin.fail()){
    cout << "The file could not be opened." << endl;
     }
  else{
    getline(cin, x);
    if((dupsonly == 1 && uniqonly == 1) || (dupsonly == 1 && uniqonly == 1 && showcount == 1)){

    };
    if(dupsonly == 0 && uniqonly == 0 && showcount == 0){
        while (cin.good()){
         getline(cin, y);
          if(x == y){
            v.push_back(y);
          }
          else{
            int count3 = v.size() + 1;
            cout << x << endl;
            v.clear();
            x = y;
          };
        };
    };
    if(showcount == 1 && dupsonly == 1 && uniqonly == 0){
      while (cin.good()){
        getline(cin, y);
        if(x == y){
          v.push_back(y);
        }
        else{
          if(v.size() > 0){
            int count1 = v.size() + 1;
            printf("%7d %s\n", count1, x.c_str());
            v.clear();
            x = y;
          }
          else{
            x = y;
          }
        }
        }
    };
    if(showcount == 1 && uniqonly == 1 && dupsonly == 0){
      while (cin.good()){
        getline(cin, y);
        if(x == y){
          v.push_back(y);
        }
        else{
          if(v.size() > 0){
            x = y;
            v.clear();
          }
          else{
            int count2 = v.size() + 1;
            printf("%7d %s\n", count2, x.c_str());
            x = y;
          }
        }
        }
    };
    if(showcount == 1 && uniqonly == 0 && dupsonly == 0){
       while (cin.good()){
         getline(cin, y);
          if(x == y){
            v.push_back(y);
          }
          else{
            int count3 = v.size() + 1;
            printf("%7d %s\n", count3, x.c_str());
            v.clear();
            x = y;
          };
        };
    };
    if (dupsonly == 1 && uniqonly == 0 && showcount == 0){
      while (cin.good()){
        getline(cin, y);
        if(x == y){
          v.push_back(y);
        }
        else{
          if(v.size() > 0){
            //printf("%7d %s\n", x.c_str());
            cout << x << endl;
            v.clear();
            x = y;
          }
          else{
            x = y;
          }
        }

        }
      };
    if (uniqonly == 1 && dupsonly == 0 && showcount == 0){
      while (cin.good()){
        getline(cin, y);
        if(x == y){
          v.push_back(y);
        }
        else{
          if(v.size() > 0){
            x = y;
            v.clear();
          }
          else{
            //printf("%7d %s\n", x.c_str());
            cout << x << endl;
            x = y;
          }
        }

        }

    }
	};
	return 0;
}