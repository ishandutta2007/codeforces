#include <bits/stdc++.h>
#include <random>
using namespace std;

#define rep(i, N) for (int i = 0; i < N; i++)
#define pb push_back

typedef long long ll;
typedef pair<int, int> i_i;
typedef pair<ll, int> ll_i;
struct edge { int v, w; };
const int INF = INT_MAX / 2;
const int MOD = 1e9 + 7;

int pow_mod(ll x, ll n, int M) {
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

int main() {
	int N; cin >> N;
	ll p; cin >> p;
	ll q; cin >> q;
	ll r = p + q;
	ll pi = inv_mod(p, MOD);
	ll qi = inv_mod(q, MOD);
	ll ri = inv_mod(r, MOD);
	vector<vector<ll>> dp(N + 1, vector<ll>(N));
	rep(z, N) dp[N][z] = ((N - 1) + r * qi) % MOD;
	for (int x = N - 1; x >= 1; x--) for (int z = N - 1; z >= 0; z--) {
		dp[x][z] = p * ri % MOD * dp[x + 1][z] % MOD;
		if (z + x < N) dp[x][z] = (dp[x][z] + q * ri % MOD * (dp[x][z + x] + x)) % MOD;
		else dp[x][z] = (dp[x][z] + q * ri % MOD * x) % MOD;
	}
	ll ans = dp[1][0];
	cout << (ans + MOD) % MOD << endl;
}