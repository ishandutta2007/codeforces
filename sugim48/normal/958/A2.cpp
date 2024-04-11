#include <bits/stdc++.h>
using namespace std;

#define rep(i, N) for (int i = 0; i < N; i++)
typedef long long ll;

int mod_inv(ll x, int M) {
	int t = M - 2, y = 1;
	for (; t; t>>=1) {
		if (t & 1) y = y * x % M;
		x = x * x % M;
	}
	return y;
}

struct rolling_hash {
	int mod;
	vector<vector<int>> a, b;
	rolling_hash(vector<string> s, int _mod) {
		mod = _mod;
		int N = s.size(), M = s[0].length();
		a = vector<vector<int>>(N + 1, vector<int>(M + 1));
		b = a;
		b[0][0] = 1;
		for (int i = 1; i < N; i++) b[i][0] = (ll)b[i - 1][0] * 256 % mod;
		rep(i, N) for (int j = 1; j < M; j++)
			b[i][j] = (ll)b[i][j - 1] * 12345 % mod;
		rep(i, N) rep(j, M)
			a[i + 1][j + 1] = ((ll)a[i + 1][j] + a[i][j + 1] - a[i][j] + (ll)s[i][j] * b[i][j]) % mod;
		rep(i, N) rep(j, M) b[i][j] = mod_inv(b[i][j], mod);
	}
	int get(int yl, int yr, int xl, int xr) {
		ll ans = ((ll)a[yr][xr] - a[yr][xl] - a[yl][xr] + a[yl][xl]) * b[yl][xl] % mod;
		return (ans + mod) % mod;
	}
};

int main() {
	int N, M; cin >> N >> M;
	vector<string> a(N);
	rep(i, N) cin >> a[i];
	vector<string> b(M);
	rep(j, M) cin >> b[j];
	int mod = 1e9 + 7;
	rolling_hash A(a, mod), B(b, mod);
	for (int i = 0; i + M <= N; i++)
		for (int j = 0; j + M <= N; j++)
			if (A.get(i, i + M, 0, M) == B.get(0, M, j, j + M)) {
				cout << i + 1 << ' ' << j + 1 << endl;
				return 0;
			}
	cout << -1 << ' ' << -1 << endl;
}