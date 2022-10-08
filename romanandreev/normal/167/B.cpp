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

int n, l ,k;
int p[1000];
int a[1000];
ld dp[202][202][404];
int main(){
	#ifdef home
	assert(freopen("a.out","wt",stdout));
	assert(freopen("a.in","rt",stdin));
	#endif 
	scanf("%d %d %d", &n, &l, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d", &p[i]);
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	dp[0][0][min(k, n) + n] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= l; j++) {
			for (int fr = 0; fr <= 2 * n; fr++) {
				if (fr + a[i] >= 0)
				dp[i + 1][min(l, j + 1)][min(fr + a[i], 2 * n)] += dp[i][j][fr] * p[i] / 100.;
				dp[i + 1][min(l, j)][min(fr, 2 * n)] += dp[i][j][fr] * (100 - p[i]) / 100.;
			}
		}
	}
	ld ans = 0;
	for (int i = 0; i <= n; i++) {
		ans += dp[n][l][i + n];
	}
	printf("%.18lf\n", (double)ans);
	return 0;
}