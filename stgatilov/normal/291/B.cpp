//#pragma comment(linker, "/STACK:20000000")
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cassert>
#include <cstdlib>
#include <ctime>

using namespace std;
typedef long long int64;
#ifdef HOME
	#define E(c) cerr<<#c
	#define Eo(x) cerr<<#x<<" = "<<(x)<<endl
	#define Ef(...) fprintf(stderr, __VA_ARGS__)
#else
	#define E(c) ((void)0)
	#define Eo(x) ((void)0)
	#define Ef(...) ((void)0)
#endif

char str[1<<20];
vector<string> all;
string curr;

bool isQuote(char c) { return c == '"'; }
bool isSpace(char c) { return c == ' '; }
bool isLetter(char c) { return !isQuote(c) && !isSpace(c); }

int main() {
#ifdef HOME
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif	
	gets(str);
	int n = strlen(str);

	for (int i = 0; i<n; i++) {
		if (isLetter(str[i])) {
			curr += str[i];
			continue;
		}
		if (!curr.empty()) {
			all.push_back(curr);
			curr = "";
		}

    	if (isQuote(str[i])) {
			int r;
			for (r = i+1; !isQuote(str[r]); r++);
			string inq(str+i+1, str+r);
			all.push_back(inq);
			i = r;
			continue;
    	}
    }

    if (!curr.empty()) all.push_back(curr);
    for (int i = 0; i<all.size(); i++)
    	printf("<%s>\n", all[i].c_str());

	return 0;
}