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

struct union_find {
	vector<int> v;
	union_find(int n) : v(n, -1) {}
	int find(int x) { return v[x] < 0 ? x : v[x] = find(v[x]); }
	void unite(int x, int y) {
		x = find(x); y = find(y);
		if (x == y) return;
		if (-v[x] < -v[y]) swap(x, y);
		v[x] += v[y]; v[y] = x;
	}
	bool root(int x) { return v[x] < 0; }
	bool same(int x, int y) { return find(x) == find(y); }
	int size(int x) { return -v[find(x)]; }
};

int main() {
	vector<vector<ll>> C(1001, vector<ll>(1001));
	rep(x, 1001) {
		C[x][0] = 1;
		for (int y = 1; y <= x; y++)
			C[x][y] = (C[x - 1][y - 1] + C[x - 1][y]) % MOD;
	}
	vector<ll> dp(1001);
	dp[0] = 1;
	for (int x = 1; x <= 1000; x++) rep(y, x)
		dp[x] = (dp[x] + dp[y] * C[x - 1][y]) % MOD;
	int M, N; cin >> M >> N;
	vector<string> a(N);
	rep(i, N) cin >> a[i];
	vector<bool> used(M);
	rep(j, M) rep(i, N) if (a[i][j] == '1') used[j] = true;
	union_find uf(M);
	rep(j1, M) rep(j2, j1) if (used[j1] && used[j2]) {
		bool ok = true;
		rep(i, N) if (a[i][j1] != a[i][j2]) ok = false;
		if (ok) uf.unite(j1, j2);
	}
	int rest = 0;
	rep(j, M) if (!used[j]) rest++;
	ll ans = dp[rest];
	rep(j, M) if (used[j] && uf.root(j))
		ans = ans * dp[uf.size(j)] % MOD;
	cout << ans << endl;
}