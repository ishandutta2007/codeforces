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

ll a[1000000];
int n , l, v1 ,v2;
vector<pair<ld, int> > vv;
ld ans[1000000];
int main(){
	#ifdef home
	assert(freopen("a.out","wt",stdout));
	assert(freopen("a.in","rt",stdin));
	#endif 
	scanf("%d %d %d %d", &n, &l, &v1, &v2);
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		a[i] = x;
		a[i + n] = a[i] + 2 * l;
	}
	ld len = ((ld)l * v2)/(v1 + v2);
	for (int i = 0; i < 2 * n; i++) {
		vv.pb(mp(a[i] - len, 1));
		vv.pb(mp(a[i], -1));
	}   
	vv.pb(mp(0, -2));
	vv.pb(mp(2 * l, 2));
	sort(all(vv));
	int tk = 0;
	bool bl = false;
	for (int i = 0; i < sz(vv); i++) {
		if (vv[i].sc == 1) {
			tk++;
		}
		if (vv[i].sc == -1) {
			tk--;
		}
		if (vv[i].sc == -2) bl = true;
		if (vv[i].sc == 2) break;
		if (bl) {
			ans[tk] += vv[i + 1].fs - vv[i].fs;
		}
	}
	for (int i = 0; i <= n; i++) {
		printf("%.18lf\n", (double)(ans[i] / (2 * l)));
	}
	return 0;
}