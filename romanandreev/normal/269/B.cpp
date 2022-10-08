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
int t[10000];
double x[10000];
int dp[5010][5010];
const int inf = 1e9;
int main(){
	#ifdef home
	assert(freopen(problem_name".out","wt",stdout));
	assert(freopen(problem_name".in","rt",stdin));
	#endif
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d %lf", &t[i], &x[i]);
	}
	for (int i = 0; i <= n; i++) 
		for (int j = 0; j <= m; j++)
			dp[i][j] = inf;
	dp[0][0] = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= m; j++) if (dp[i][j] != inf) {
			dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + 1);
			if (t[i] >= j) {
				dp[i + 1][t[i]] = min(dp[i + 1][t[i]], dp[i][j]);
			}
			if (t[i] == j) {
				dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
			}
			if (t[i] == j + 1) {
				dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j]);
			}					
		}
	}
	int ans = inf;
	for (int i = 0; i <= m; i++) {
		ans = min(ans, dp[n][i]);
	}
	cout<<ans<<endl;
	return 0;
}