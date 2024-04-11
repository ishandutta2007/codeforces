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
#define x first
#define y second
#define y1 y1_gdssdfjsdgf
#define y0 y0_fsdjfsdogfs
#define ws ws_fdfsdfsdgfs
#define image(a) {sort(all(a)),a.resize(unique(all(a))-a.begin());}
#define eprintf(...) {fprintf(stderr,__VA_ARGS__),fflush(stderr);}

#define forn(i,n) for( int i = 0 ; i < (n) ; i++ )
#define forit(it,c) for( __typeof((c).begin()) it = (c).begin() ; it != (c).end() ; it++ )
#define problem_name "a"
const int P = 17239;
char s[1000100];
ll stp[1000];
const int SZ = 9999991;
ll H[SZ];
int C[SZ];
void add(ll h0) {
	int ps = abs(h0) % SZ;
	while (1) {
		if (H[ps] == 0) {
			H[ps] = h0;
			C[ps] = 1;
			return;
		}
		if (H[ps] == h0) {
			C[ps]++;
			return;
		}
		ps++;
		if (ps == SZ) {
			ps = 0;
		}
	}
}
int get(ll h0) {
	int ps = abs(h0) % SZ;
	while (1) {
		if (H[ps] == 0) {			
			return 0;
		}
		if (H[ps] == h0) {
			return C[ps];
		}
		ps++;
		if (ps == SZ) {
			ps = 0;
		}
	}
	return -1;
}

int main(){
	#ifdef home
	assert(freopen(problem_name".out","wt",stdout));
	assert(freopen(problem_name".in","rt",stdin));
	#endif
	gets(s);
	int m = strlen(s);
	string ss;
	stp[0] = 1;
	for (int i = 1; i <= 100; i++) {
		stp[i] = stp[i - 1] * P;
	}
	vector<pair<int, ll> > st;
	int tp = 0;
	for (int i = 0; i < m; i++) {
		if (s[i] == '<') {
			ss = "";
			tp = 1;
		} else
		if (s[i] == '>') {
			if (tp >= 1) {
				ll hh = 0;
				for (int j = sz(ss) - 1; j >= 0; j--) {
					hh = hh * P + ss[j];
				}
				//cerr<<"add "<<ss<<endl;
				st.pb(mp(1, hh));				
			}	
			if (tp != 1) {
				st.pb(mp(-1, -1));
			}
		} else {
			if (s[i] == '/') {
				if (sz(ss) == 0) {
					tp = 0;
				} else {
					tp = 2;
				}
			} else
				ss += s[i];
		}
	}
	int n;
	scanf("%d\n", &n);
//	for (int j = 0; j < sz(st); j++) {
//		cerr<<st[j].x<<" "<<st[j].y<<endl;
//	}
	for (int it = 0; it < n; it++) {
		gets(s);
	//	printf("%s\n", s);
		int m = strlen(s);
		s[m] = ' ';
		m++;
		ss = "";
		vector<ll> ls;
		for (int j = 0; j < m; j++) {
			if (s[j] == ' ') {
				ll hh = 0;
				for (int j = sz(ss) - 1; j >= 0; j--) {
					hh = hh * P + ss[j];
				}
		//		cerr<<ss<<" ";
				ls.pb(hh);
				ss = "";
			} else {
				ss += s[j];
			}
		}
		//cerr<<endl;
		vector<int> cc;
		cc.pb(0);
		int ans = 0;
		for (int j = 0; j < sz(st); j++) {
		//	cerr<<" "<<j<<endl;
			if (st[j].x == -1) {	
				cc.pop_back();
			} else {				
				if (cc[sz(cc) - 1] < sz(ls) - 1 && st[j].y == ls[cc[sz(cc) - 1]]) {
					cc.pb(cc[sz(cc) - 1] + 1);
				} else {
					if (cc[sz(cc) - 1] == sz(ls) - 1 && st[j].y == ls[cc[sz(cc) - 1]]) {					
						ans++;
					}
					cc.pb(cc[sz(cc) - 1]);
				}
			}
		}
		//cerr<<"!"<<endl;
		printf("%d\n", ans);
	}
//	cerr<<clock()*1./CLOCKS_PER_SEC<<endl;
	return 0;
}