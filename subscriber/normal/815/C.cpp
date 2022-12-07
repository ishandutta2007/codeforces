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

int dp[5005][5005][2];
int sz[5005];
int n, B;
int c[5055], d[5055];
vector<int> v[5055];

void calc(int x) {
	sz[x] = 1;

	for (int i = 0; i <= n; i++) dp[x][i][0] = dp[x][i][1] = B + 1;
	dp[x][0][0] = 0;

	dp[x][1][0] = c[x];
	dp[x][1][1] = c[x] - d[x];

	for (int i = 0; i < v[x].size(); i++) {
		int to = v[x][i];

		calc(to);


		for (int j = sz[x]; j >= 0; j--) for (int k = 1; k <= sz[to]; k++) {
			dp[x][j + k][0] = min(dp[x][j + k][0], dp[x][j][0] + dp[to][k][0]);

			dp[x][j + k][1] = min(dp[x][j + k][1], dp[x][j][1] + min(dp[to][k][1], dp[to][k][0]) );
		}
		sz[x] += sz[to];
	}
}

int main(){
	#ifdef home
		freopen(TASK".in","r",stdin);	
		freopen(TASK".out","w",stdout);
	#endif		
	ios::sync_with_stdio(false);
	cin >> n >> B;
	for (int i = 0; i < n; i++) {
		cin >> c[i] >> d[i];
		if (i > 0) {
			int x;
			cin >> x;
			v[x - 1].pb(i);
		}
	}
	calc(0);
	int ans = 0;
	for (int i = 0; i <= n; i++) if (dp[0][i][0] <= B || dp[0][i][1] <= B) ans = max(ans, i);
	cout << ans << endl;

	return 0;
}