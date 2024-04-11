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

pair<ld, ld> dp[1010][1600];
int n, T;
int ss[1010];
int sl[1010];
int ts[1010];
int tl[1010];
ld p[1010];
const ld eps = 1e-9;
pair<ld, ld> max1(pair<ld, ld> a, pair<ld, ld> b) {
	if (a.x + eps < b.x) return b;
	if (a.x > b.x + eps) return a;
	if (a.y + eps < b.y) return b;
	return a;
}
bool cmp(int x, int y) {
	return tl[x] * p[x] * (1 - p[y]) < tl[y] * p[y] * (1 - p[x]);
}
int main(){
	#ifdef home
	assert(freopen(problem_name".out","wt",stdout));
	assert(freopen(problem_name".in","rt",stdin));
	#endif
	scanf("%d %d", &n, &T);
	for (int i = 0; i < n; i++) {
		double xx;
		scanf("%d %d %d %d %lf", &ss[i], &sl[i], &ts[i], &tl[i], &xx);
		p[i] = xx;
	}
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (!cmp(i, j)) {
				swap(ss[i], ss[j]);
				swap(sl[i], sl[j]);
				swap(ts[i], ts[j]);
				swap(tl[i], tl[j]);
				swap(p[i], p[j]);
			}
		}
	}
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= T; j++) {
			dp[i][j] = mp(0, 0);
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= T; j++) {
			if (ts[i] + j <= T) {
				dp[i + 1][ts[i] + j] = max1(dp[i + 1][ts[i] + j], mp(dp[i][j].x + ss[i], dp[i][j].y));
			}
			if (ts[i] + tl[i] + j <= T) {
				dp[i + 1][ts[i] + tl[i] + j] = max1(dp[i + 1][ts[i] + tl[i] + j], mp(dp[i][j].x + ss[i] + sl[i] * (1 - p[i]), (tl[i] + dp[i][j].y) * p[i]));
			}
			dp[i + 1][j] = max1(dp[i + 1][j], dp[i][j]);
		}
	}
	pair<ld, ld> ans = mp(0, 0);
	for (int i = 0; i <= T; i++) {
		if (ans.x + eps < dp[n][i].x) {
			ans = mp(dp[n][i].x, i - dp[n][i].y);
		} else 
		if (fabs(ans.x - dp[n][i].x) <= eps) {
			ans = mp(ans.x, min(i - dp[n][i].y, ans.y));
		}
	}
	printf("%.18lf %.18lf\n", (double)ans.x, (double)ans.y);
	return 0;
}