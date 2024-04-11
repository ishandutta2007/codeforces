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

pi p[10000];
int dp[4002][4002];
int n, k, ans;
int main(){
	#ifdef home
	assert(freopen("a.out","wt",stdout));
	assert(freopen("a.in","rt",stdin));
	#endif 
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &p[i].fs, &p[i].sc);
	}
	sort(p, p + n);
	memset(dp, 61, sizeof(dp));
	int inf = dp[0][0];
	dp[0][0] = 0;
	ans = 0;
	p[n].fs = 86401;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= k; j++) if (dp[i][j] != inf) {
			dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j]);
			dp[i + 1][j] = min(dp[i + 1][j], max(dp[i][j], p[i].fs - 1) + p[i].sc);
		}
	}
	for (int i = 0; i <= n; i++) 
		for (int j = 0; j <= k; j++) if (dp[i][j] != inf) {
			int lf = dp[i][j] + 1;
			int rg = p[min(i + k - j, n)].fs - 1;
			lf = max(lf, 1);
			rg = min(rg, 86400);
			ans = max(ans, rg - lf + 1);
		}
	cout<<ans<<endl;
	return 0;
}