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

int n, a, d;
int t[1000000];
int v[1000000];
ld ans[1000000];
ld calc(ld d, ld a, ld v) {
	ld d0 = v * v / (a * 2);
	ld t0 = v / a;
	if (d0 < d) {
		return t0 + (d - d0) / v;
	} else {
		return sqrt(2 * d / a);
	}
}
int main(){
	#ifdef home
	assert(freopen("a.out","wt",stdout));
	assert(freopen("a.in","rt",stdin));
	#endif 
	scanf("%d %d %d", &n, &a, &d);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &t[i], &v[i]);
	}
	for (int i = 0; i < n; i++) {
		ans[i] = max(i == 0?0:ans[i - 1], t[i] + calc(d, a, v[i]));
		printf("%.18lf\n", (double)ans[i]);
	}
	return 0;
}