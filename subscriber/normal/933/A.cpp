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
#define N 411111

#define TASK "1"

using namespace std;

int n, a[2222], w[2222][2222];
int pr[2222], suf[2222];

int main(){
	#ifdef home
		freopen(TASK".in","r",stdin);	
		freopen(TASK".out","w",stdout);
	#endif		
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];

	for (int r = 0; r < n; r++) {
		int dp[r + 2][2];
		for (int i = 0; i <= r + 1; i++) for (int j = 0; j < 2; j++) dp[i][j] = 0;

		for (int i = 0; i < r + 1; i++) for (int j = 0; j < 2; j++) {
			if (j == 0) dp[i][j + 1] = max(dp[i][j + 1], dp[i][j]);

			dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + (a[r - i] == (j + 1)));
		}

		for (int i = 1; i <= r + 1; i++) w[r - i + 1][r] = max(dp[i][0], dp[i][1]);
	}

	pr[0] = 0;
	for (int i = 0; i < n; i++) pr[i + 1] = pr[i] + (a[i] == 1);

	suf[n] = 0;
	for (int i = n - 1; i >= 0; i--) suf[i] = suf[i + 1] + (a[i] == 2);

	int ans = 0;
	for (int i = 0; i < n; i++) for (int j = i; j < n; j++) ans = max(ans, pr[i] + suf[j + 1] + w[i][j]);
	cout << ans << endl;


	return 0;
}