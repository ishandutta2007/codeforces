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
int t[1000000];
int x[1000000];
int ans[1000000];

int main(){
	#ifdef home
	assert(freopen(problem_name".out","wt",stdout));
	assert(freopen(problem_name".in","rt",stdin));
	#endif
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &t[i], &x[i]);
	}
	int pr = -1;
	int t0 = 0;
	for (int i = 0; i < n; i++) {
		if (i == n - 1 || (i + 1) % m == 0) {
			vector<pi> v;
			for (int j = pr + 1; j <= i; j++) {
				v.pb(mp(x[j], j));
			}
			sort(all(v));
			t0 = max(t0, t[i]);
			int pr0 = -1;
			for (int j = 0; j < sz(v); j++) {
				if (j == sz(v) - 1 || v[j].x != v[j + 1].x) {
					t0 = t0 + v[j].x - (pr0 >= 0?v[pr0].x:0);
					for (int k = pr0 + 1; k <= j; k++) {
						ans[v[k].y] = t0;
					}
					t0 += 1 + (j - pr0) / 2;
					pr0 = j;
				}
			}
			t0 += v[sz(v) - 1].x;
			pr = i;
		}
	}
	for (int i = 0; i < n; i++) {
		printf("%d%c", ans[i], " \n"[i == n - 1]);
	}
	return 0;
}