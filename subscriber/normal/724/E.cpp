#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back      
#define F first
#define S second
#define SS stringstream
#define sqr(x) ((x)*(x))
#define m0(x) memset(x,0,sizeof(x))
#define m1(x) memset(x,63,sizeof(x))
#define CC(x) cout << (x) << endl
#define pw(x) (1ll<<(x))
#define buli(x) __builtin_popcountll(x)
#define forn(i, n) for(int i = 0 ; (i) < (n) ; ++i)
#define M 1000000007
#define N 22111

#define TASK "1"

using namespace std;

long long inf = (long long)1e18 + 1;

long long dp[N], dp2[N];
int q1[N], q2[N];

int n, c;

int main(){
	#ifdef home
		freopen(TASK".in","r",stdin);	
		freopen(TASK".out","w",stdout);
	#endif		
	ios::sync_with_stdio(false);
	cin >> n >> c;
	for (int i = 0; i < n; i++) cin >> q1[i];
	for (int i = 0; i < n; i++) cin >> q2[i];

	for (int i = 0; i <= n; i++) dp[i] = inf;
	dp[0] = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= n; j++) dp2[j] = inf;

		for (int j = 0; j <= n; j++) if (dp[j] < inf) {
			{
				int cost = q1[i] + q2[i];
				dp2[j] = min(dp2[j], dp[j] + cost + j * 1ll * c);
				dp2[j + 1] = min(dp2[j + 1], dp[j] + cost);
			}
			{
				int cost = q2[i];
				dp2[j + 1] = min(dp2[j + 1], dp[j] + cost);
			}
			{
				int cost = q1[i];
				dp2[j] = min(dp2[j], dp[j] + cost + j * 1ll * c);
			}
		}
		for (int j = 0; j <= n; j++) dp[j] = dp2[j];
	}
	long long ans = inf;
	for (int i = 0; i <= n; i++) ans = min(ans, dp[i]);
	cout << ans << endl;
	return 0;
}