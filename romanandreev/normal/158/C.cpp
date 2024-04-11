#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstdarg>
#include <cassert>
#include <climits>
#include <cstring>
#include <complex>
#include <cstdio>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <ctime>
#include <set>
#include <map>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pi;
typedef vector<int> vi;


#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()

#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define y1 y1_gdssdfjsdgf
#define y0 y0_fsdjfsdogfs
#define ws ws_fdfsdfsdgfs
#define image(a) {sort(all(a)),a.resize(unique(all(a))-a.begin());}
#define eprintf(...) {fprintf(stderr,__VA_ARGS__),fflush(stderr);}

#define forn(i,n) for( int i = 0 ; i < (n) ; i++ )
#define forit(it,c) for( __typeof((c).begin()) it = (c).begin() ; it != (c).end() ; it++ )


int main(){
	#ifdef home
	assert(freopen("a.out","wt",stdout));
	assert(freopen("a.in","rt",stdin));
	#endif 
	int n;
	string s;
	cin>>n;
	vector<string> st;
	for (int it = 0; it < n; it++) {
		cin>>s;
		if (s == "pwd") {
			printf("/");
			for (int i = 0; i < sz(st); i++) {
				printf("%s/", st[i].c_str());
			}
			printf("\n");
		} else {
			cin>>s;
			int ff = 0;
			if (s[0] == '/') {
				st.clear();
				ff = 1;
			}
			if (s == "/") continue;
			s += "/";
			string tk = "";
			for (int i = ff; i < sz(s); i++) {
				if (s[i] == '/') {
					if (tk == "..") {
						st.pop_back();
					} else {
						st.pb(tk);
					}
					tk = "";
				} else {
					tk += s[i];
				}
			}
		}
	}
	return 0;
}