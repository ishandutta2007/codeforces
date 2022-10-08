#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <ctime>
#include <cassert>

#define x first
#define y second
#define pb push_back
#define mp make_pair
#define forn(i, n) for(int i = 0 ; (i) < (n) ; ++i)
#define forit(it,v) for(typeof((v).begin()) it = v.begin() ; it != (v).end() ; ++it)
#define eprintf(...) fprintf(stderr, __VA_ARGS__),fflush(stderr)
#define sz(a) ((int)(a).size())
#define all(a) (a).begin(),a.end()

using namespace std;

typedef long long ll;
typedef double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;

const int inf = (int)1e9;
const ld eps = 1e-9;


#define TASK "a"
char s[1000000];
int main()
{
	#ifdef home
		assert(freopen(TASK".in", "r", stdin));
		assert(freopen(TASK".out", "w", stdout));
	#endif
	gets(s);
	int n = strlen(s);
	s[n++] = ' ';
	bool sk = false;
	string tk = "";
	for (int i = 0; i < n; i++) {
		if (s[i] == '"') {
			if (sk) {
				printf("<%s>\n", tk.c_str());
				sk = false;
				tk = "";
			} else {
				if (sz(tk)) {
					printf("<%s>\n", tk.c_str());				
				}
				tk = "";
				sk = true;
			}
			continue;	
		}
		if (sk) {
			tk += s[i];
			continue;
		}
		if (s[i] == ' ') {
			if (sz(tk)) {
				printf("<%s>\n", tk.c_str());				
			}
			tk = "";
			continue;
		}
		tk += s[i];
	}
	#ifdef home
		eprintf("Time: %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
	#endif
	return 0;
}