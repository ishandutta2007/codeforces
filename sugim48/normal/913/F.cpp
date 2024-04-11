#include <bits/stdc++.h>
#include <random>
using namespace std;

#define rep(i, N) for (int i = 0; i < N; i++)
#define pb push_back

typedef long long ll;
typedef pair<int, int> i_i;
typedef pair<ll, int> ll_i;
typedef pair<ll, ll> ll_ll;
struct edge { int v, w; };
const ll INF = LLONG_MAX / 2;
const int MOD = 998244353;
const ll e18 = 1e18;

ll pow_mod(ll x, ll n, int M) {
	ll ans = 1;
	for (; n; n>>=1) {
		if (n & 1) ans = ans * x % M;
		x = x * x % M;
	}
	return ans;
}

int inv_mod(int x, int p) {
	return pow_mod(x, p - 2, p);
}

void show(ll z) {
	z = (z + MOD) % MOD;
	for (int x = 0; x <= 1000; x++)
		for (int y = 1; y <= 1000; y++)
			if ((ll)x * inv_mod(y, MOD) % MOD == z) {
				cout << x << '/' << y << endl;
				return;
			}
}

int main() {
	int N; ll px, py; cin >> N >> px >> py;
	ll p = px * inv_mod(py, MOD) % MOD;
	ll q = (1 - p + MOD) % MOD;
	ll r = p * inv_mod(q, MOD) % MOD;
	vector<ll> P(N * N + 1), Q(N * N + 1), R(N * N + 1);
	P[0] = Q[0] = R[0] = 1;
	rep(x, N * N) {
		P[x + 1] = P[x] * p % MOD;
		Q[x + 1] = Q[x] * q % MOD;
		R[x + 1] = R[x] * r % MOD;
	}
	vector<vector<ll>> dp(N + 1, vector<ll>(N + 1));
	dp[0][0] = 1;
	rep(x, N + 1) rep(y, N + 1) if (x + y + 1 <= N) {
		dp[x + 1][y] = (dp[x + 1][y] + dp[x][y] * R[y]) % MOD;
		dp[x][y + 1] = (dp[x][y + 1] + dp[x][y]) % MOD;
	}
	rep(x, N + 1) rep(y, N + 1) if (x + y <= N)
		dp[x][y] = dp[x][y] * Q[x * y] % MOD;
	vector<ll> unko(N + 1);
	unko[1] = 1;
	for (int x = 2; x <= N; x++) {
		unko[x] = 1;
		for (int y = 1; y <= x - 1; y++) {
			ll z = dp[y][x - y] * unko[y] % MOD;
			unko[x] = (unko[x] - z) % MOD;
		}
		unko[x] = (unko[x] + MOD) % MOD;
	}
	vector<ll> ans(N + 1);
	ans[1] = 0;
	for (int x = 2; x <= N; x++) {
		ll hoge = inv_mod(1 - unko[x], MOD);
		ans[x] = (hoge - 1) * (x*(x-1)/2) % MOD;
		for (int y = 1; y <= x - 1; y++) {
			ll z = dp[y][x - y] * unko[y] % MOD * hoge % MOD;
			ans[x] = (ans[x] + z * ((x-y)*y + y*(y-1)/2 + ans[y] + ans[x - y])) % MOD;
		}
	}
	/*
	for (int x = 1; x <= N; x++) {
		cout << '#' << x << endl;
		show((unko[x] + MOD) % MOD);
	}
	*/
	/*
	for (int x = 1; x <= N; x++) {
		cout << '#' << x << endl;
		show((ans[x] + MOD) % MOD);
		cout << (ans[x] + MOD) % MOD << endl;
	}
	*/
	cout << (ans[N] + MOD) % MOD << endl;
}