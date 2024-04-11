#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using db = double;
#define pb push_back
#define fir first
#define sec second

const ll mod = 1e9L + 7;

const int N = 40;
ll dp[N][N][2];

void upd(ll &x, ll y) {
	x += y; x %= mod;
}

int main() {
	int m; cin >> m;
	
	if(m == 0) {
		cout << "1\n";
		return 0;
	}
	
	int n = 31 - __builtin_clz(m);
	dp[n][1][1] = dp[n][0][0] = 1;
	for(int i = n; i > 0; i --)
		for(int j = 0; j <= n + 1; j ++) {
			upd(dp[i - 1][j][0], dp[i][j][0] * (1LL << j));
			upd(dp[i - 1][j + 1][0], dp[i][j][0]);
			
			if((m >> (i - 1)) & 1) {
				if(j == 0)
					upd(dp[i - 1][0][0], dp[i][0][1]);
				else {
					upd(dp[i - 1][j][0], dp[i][j][1] * (1LL << (j - 1)));
					upd(dp[i - 1][j][1], dp[i][j][1] * (1LL << (j - 1)));
				}
				upd(dp[i - 1][j + 1][1], dp[i][j][1]);
			} else {
				if(j == 0)
					upd(dp[i - 1][0][1], dp[i][0][1]);
				else
					upd(dp[i - 1][j][1], dp[i][j][1] * (1LL << (j - 1)));
			}
		}
	
	ll ans = 0;
	for(int i = 0; i < N; i ++)
		for(int j : {0, 1})
			ans += dp[0][i][j];
	cout << ans % mod << '\n';
	
	return 0;
}