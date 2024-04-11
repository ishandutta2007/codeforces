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

int n, k;
vi r[100000];
int was[100000];
int dp[50002][502];
ll ans1, ans2;
void dfs(int v) {
	was[v] = 1;
	dp[v][0] = 1;
	vi ls;
	for (int i = 0; i < sz(r[v]); i++) {
		int e = r[v][i];
		if (was[e] == 0) {
			ls.pb(e);
			dfs(e);
			for (int j = 0; j < k; j++) {
				dp[v][j + 1] += dp[e][j];
			}
		}
	}
	ans1 += dp[v][k];
	for (int i = 0; i < sz(ls); i++) {
		for (int j = 1; j < k; j++) {
			ans2 += (ll)dp[ls[i]][j - 1] * (dp[v][k - j] - dp[ls[i]][k - j - 1]);
		}
	}
}
int main(){
	#ifdef home
	assert(freopen("a.out","wt",stdout));
	assert(freopen("a.in","rt",stdin));
	#endif 
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n - 1; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		x--, y--;
		r[x].pb(y);
		r[y].pb(x);
	}
	ans1 = 0;
	ans2 = 0;
	dfs(0);
	cout<<ans1 + ans2 / 2 << endl;
	return 0;
}