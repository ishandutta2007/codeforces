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

int n, k;
int c[555];
int dp[555][555], dp2[555][555];

int main(){
	#ifdef home
		freopen(TASK".in","r",stdin);	
		freopen(TASK".out","w",stdout);
	#endif		
	ios::sync_with_stdio(false);
	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> c[i];

	dp[0][0] = 1;

	for (int it = 0; it < n; it++) {
		int w = c[it];
		for (int i = 0; i <= k; i++) for (int j = 0; j <= k; j++) dp2[i][j] = 0;

		for (int i = 0; i <= k; i++) for (int j = 0; j <= k; j++) if (dp[i][j]) {
			dp2[i][j] = 1;
			if (i + w <= k) {
				dp2[i + w][j] = 1;
				dp2[i + w][j + w] = 1;
			}				
		}
		for (int i = 0; i <= k; i++) for (int j = 0; j <= k; j++) dp[i][j] = dp2[i][j];
	}
	vector<int> ans;
	for (int i = 0; i <= k; i++) if (dp[k][i]) ans.pb(i);
	cout << ans.size() <<endl;
	for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";

	return 0;
}