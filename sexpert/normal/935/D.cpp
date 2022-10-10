#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 1e5 + 5;
ll dp[MAXN][3];
const ll MOD = 1e9 + 7;
const ll I2 = (MOD + 1)/2;

ll inv(ll b) {
	ll e = MOD - 2, res = 1;
	for(ll k = 1; k <= e; k *= 2) {
		if(k & e) res = (res * b) % MOD;
		b = (b * b) % MOD;
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	ll im = inv(m);
	vector<int> a(n), b(n);
	for(auto &x : a)
		cin >> x;
	for(auto &x : b)
		cin >> x;
	dp[0][0] = 1;
	for(int i = 1; i <= n; i++) {
		int x = a[i - 1], y = b[i - 1];
		ll pg, ps, pe;
		if(x == 0 && y == 0) {
			pg = (((m - 1) * im) % MOD * I2) % MOD;
			ps = pg;
			pe = im;
		}
		if(x == 0 && y > 0) {
			pg = ((m - y) * im) % MOD;
			pe = im;
			ps = (1 - pg - pe) % MOD;
		}
		if(x > 0 && y == 0) {
			ps = ((m - x) * im) % MOD;
			pe = im;
			pg = (1 - pe - ps) % MOD;
		}
		if(x > 0 && y > 0) {
			pg = (x > y);
			pe = (x == y);
			ps = (x < y);
		}
		dp[i][0] = (dp[i - 1][0] * pe) % MOD;
		dp[i][1] = (dp[i - 1][0] * pg + dp[i - 1][1]) % MOD;
		dp[i][2] = (dp[i - 1][0] * ps + dp[i - 1][2]) % MOD;
	}
	cout << (dp[n][1] + MOD) % MOD << '\n';
}