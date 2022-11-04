#include <bits/stdc++.h>
using namespace std;

template<typename hd, typename tl> void chkmin(hd& a, tl b) { if(b < a) a = b; }
template<typename hd, typename tl> void chkmax(hd& a, tl b) { if(a < b) a = b; }
#define pb push_back
#define pob pop_back
#define sz(x) (int)(x.size())
#define F first
#define S second
#define endl '\n'
#define all(x) x.begin(), x.end()
using LL = long long;
using PI = pair<int, int>;
const int N = 1000005;

int a[N];
vector <int> vertix[N], adj[N];
map <int, LL> C[N];

#define mod 998244353

LL cnt[N];
LL sum[N];
LL tot[N];

int dep[N];

void dfs (int u, int p) {
	dep[u] = dep[p] + 1;
	for (int j = 2; j * j <= a[u]; j ++) {
		if (a[u] % j) continue;
		while (a[u] % j == 0) {
			a[u] /= j;
		}
		C[u][j] = 1;
		cnt[j] += dep[u];
		sum[j] += dep[u];
		tot[j] ++;
	}
	if (a[u] > 1) C[u][a[u]] = 1, cnt[a[u]] += dep[u], sum[a[u]] += dep[u], tot[a[u]] ++;
	for (auto v : adj[u]) {
		if (v == p) continue;
		dfs (v, u);
		if (C[v].size() > C[u].size()) swap(C[v], C[u]);
		for (auto val : C[v]) {
			sum[val.first] -= (C[u][val.first] * C[u][val.first] % mod) * dep[u] % mod;
			sum[val.first] -= (val.second * val.second  % mod) * dep[u] % mod;
			C[u][val.first] += val.second;
			sum[val.first] += (C[u][val.first] * C[u][val.first] % mod) * dep[u] % mod;
		}
	}
}

LL modexp(LL a, LL n) {
	LL rlt = 1;
	for (; n; n /= 2) {
		if (n & 1) rlt = rlt * a % mod;
		a = a * a % mod;
	}
	return rlt;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif

	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
	}
	for (int i = 1; i < n; i ++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs (1, 0);
	LL rlt = 0;
	for (int i = 2; i < N; i ++) {
		if (tot[i] < 3) continue;
		LL val = (cnt[i] * tot[i] % mod - sum[i]) % mod;
		val = val * (tot[i] - 2) % mod;
		val = val * modexp(2, mod - 2) % mod;
		rlt += val;
	}
	rlt = (rlt % mod + mod) % mod;
	cout << rlt << endl;
	return 0;
}