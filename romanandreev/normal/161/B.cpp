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
#define x first
#define y second
#define y1 y1_gdssdfjsdgf
#define y0 y0_fsdjfsdogfs
#define ws ws_fdfsdfsdgfs
#define image(a) {sort(all(a)),a.resize(unique(all(a))-a.begin());}
#define eprintf(...) {fprintf(stderr,__VA_ARGS__),fflush(stderr);}

#define forn(i,n) for( int i = 0 ; i < (n) ; i++ )
#define forit(it,c) for( __typeof((c).begin()) it = (c).begin() ; it != (c).end() ; it++ )

vector<pi> ans[10000];
int tt[20000];
int main(){
	#ifdef home
	assert(freopen("a.out","wt",stdout));
	assert(freopen("a.in","rt",stdin));
	#endif 
	int n, k;
	vector<pi> v1, v2;
	scanf("%d %d", &n, &k);
	ld an = 0;
	for (int i = 0; i < n; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		tt[i + 1] = y;
		an += x;
		if (y == 1) {
			v1.pb(mp(x, i + 1));
		} else {
			v2.pb(mp(x, i + 1));
		}
	}
	sort(all(v1));
	sort(all(v2));
	reverse(all(v1));
	reverse(all(v2));
	if (sz(v1) >= k) {
		for (int i = 0; i < sz(v1); i++) {
			ans[min(i, k - 1)].pb(v1[i]);
		}
		for (int i = 0; i < sz(v2); i++) {
			if (ans[min(i, k - 1)][sz(ans[min(i, k - 1)]) - 1].x <= v2[i].x) {
				ans[min(i, k - 1)].pb(v2[i]);
			} else {
				ans[k - 1].pb(v2[i]);
			}
		}
	} else {
		for (int i = 0; i < sz(v1); i++) {
			ans[min(i, k - 1)].pb(v1[i]);
		}
		for (int i = 0; i < k - sz(v1); i++) {
			ans[k - i - 1].pb(v2[i + sz(v2) - (k - sz(v1))]);
		}
		for (int i = 0; i < sz(v2) - (k - sz(v1)); i++) {
			if (ans[min(i, k - 1)][sz(ans[min(i, k - 1)]) - 1].x <= v2[i].x) {
				ans[min(i, k - 1)].pb(v2[i]);
			} else {
				ans[k - 1].pb(v2[i]);
			}
		}
	}
	for (int i = 0; i < k; i++) {
		sort(all(ans[i]));
		bool ff = false;
		for (int j = 0; j < sz(ans[i]); j++) {
			if (tt[ans[i][j].y] == 1) {
				ff = true;
			}
		}
		if (ff)
		an -= ans[i][0].x / 2.;
	}
	printf("%.1lf\n", (double)an);
	for (int i = 0; i < k; i++) {
		printf("%d", sz(ans[i]));
		for (int j = 0; j < sz(ans[i]); j++) {
			printf(" %d", ans[i][j].y);
		}
		printf("\n");
	}
	return 0;
}