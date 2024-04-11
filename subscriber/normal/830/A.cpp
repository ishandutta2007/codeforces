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
#define N 211111

#define TASK "1"

using namespace std;

int n, k, p;
int a[2022], b[2022];
int dp[2022][2022];

int main(){
	#ifdef home
		freopen(TASK".in","r",stdin);	
		freopen(TASK".out","w",stdout);
	#endif		
	ios::sync_with_stdio(false);
	cin >> n >> k >> p;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < k; i++) cin >> b[i];
	sort(a,a + n);
	sort(b, b + k);

	for (int i = 0; i <= n; i++) for (int j = 0; j <= k; j++) dp[i][j] = 2e9 + 1;

	dp[0][0] = 0;

	for (int i = 0; i < n; i++) for (int j = 0; j < k; j++) {
		dp[i + 1][j + 1] = min(dp[i + 1][j + 1], max(dp[i][j], abs(a[i] - b[j]) + abs(b[j] - p)));
		dp[i][j + 1] = min(dp[i][j + 1], dp[i][j]);
	}
	int ans = 2e9 + 1;
	for (int i = 0; i <= k; i++) ans = min(ans, dp[n][i]);
	cout << ans << endl;
	return 0;
}