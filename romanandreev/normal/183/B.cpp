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
int n, m;
int x[1000];
int y[1000];
int ff[1010000];
int main(){
	#ifdef home
	assert(freopen(problem_name".out","wt",stdout));
	assert(freopen(problem_name".in","rt",stdin));
	#endif
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &x[i], &y[i]);
	}        
	for (int i = 0; i < m; i++) {
		for (int j = i + 1; j < m; j++) {
			int cnt = 0;
			for (int k = 0; k < m; k++) {
				if ((ll)(x[k] - x[i]) * (y[j] - y[i]) - (ll)(y[k] - y[i]) * (x[j] - x[i]) == 0) {
					cnt++;
				}
			}
			if (y[i] != y[j]) {
		//		c = - y[i] / (y[j] - y[i]);
				if (((ll)(x[j] - x[i]) * y[i]) % (y[j] - y[i]) == 0) {
					ll xx = x[i] - (ll)(x[j] - x[i]) * y[i] / (y[j] - y[i]);
					if (xx >= 1 && xx <= n) {
						ff[xx] = max(ff[xx], cnt);
					}
				}
			}
		}
	}
	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		ans += max(1, ff[i]);
//		cerr<<max(1, ff[i])<<endl;
	}
	cout<<ans<<endl;
	return 0;
}