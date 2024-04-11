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

int n, m , x, y;
pi a[1000000];
pi b[1000000];

int main(){
	#ifdef home
	assert(freopen("a.out","wt",stdout));
	assert(freopen("a.in","rt",stdin));
	#endif 
	scanf("%d %d %d %d", &n, &m, &x, &y);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i].x);
		a[i].y = i + 1;
	}
	for (int i = 0; i < m; i++) {
		scanf("%d", &b[i].x);
		b[i].y = i + 1;
	}
	sort(a, a + n);
	sort(b, b + m);
	int tk = 0;
	vector<pi> ans;
	for (int i = 0; i < n; i++) {
		while (tk < m && b[tk].x < a[i].x - x) {
			tk++;
		}
		if (tk < m && b[tk].x >= a[i].x - x && b[tk].x <= a[i].x + y) {
			ans.pb(mp(a[i].y, b[tk].y));
			tk++;
		} 
	}
	printf("%d\n", sz(ans));
	for (int i = 0; i < sz(ans); i++) {
		printf("%d %d\n", ans[i].x, ans[i].y);
	}
	return 0;
}