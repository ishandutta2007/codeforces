#include <bits/stdc++.h>

using namespace std;
using ll = long long;
constexpr ll MOD = 998244353;

// unbound, weakly bound, strongly bound, wb + sb, ub + sb
vector<ll> ub, wb, sb, bound, direct;
vector<vector<int>> tree;

ll modexp(ll b, ll e) {
	if (e == 0) return 1;
	else return (e & 1 ? b : 1) * modexp(b * b % MOD, e / 2) % MOD;
}

ll modinv(ll x) {return modexp(x, MOD - 2);}

void magCompute(int v, int p) {
	vector<int> ch;
	for (int nxt : tree[v]) {
		if (nxt != p) {
			ch.push_back(nxt);
			magCompute(nxt, v);
		}
	}
	if (ch.empty()) {
		ub[v] = wb[v] = 1;
//		printf("%d %lld %lld %lld\n", v, ub[v], wb[v], sb[v]);
	} else { 
		ub[v] = sb[v] = 1;
		for (int x : ch) ub[v] = ub[v] * direct[x] % MOD;
		ll termBasis = 1;
		for (int x : ch) termBasis = (termBasis * direct[x]) % MOD;
		for (int x : ch) wb[v] = (wb[v] + (termBasis * modinv(direct[x]) % MOD * bound[x] % MOD)) % MOD;
		for (int x : ch) sb[v] = sb[v] * ((direct[x] + bound[x]) % MOD) % MOD;
		sb[v] = (sb[v] - wb[v] + MOD - ub[v] + MOD) % MOD;
	}
	bound[v] = (wb[v] + sb[v]) % MOD;
	direct[v] = (sb[v] + ub[v]) % MOD;
//	printf("%d %lld %lld %lld\n", v, ub[v], wb[v], sb[v]);
}

int main() {
	int n; scanf("%d", &n);
	tree = vector<vector<int>>(n);
	ub = wb = sb = bound = direct = vector<ll>(n);
	for (int i = 0; i < n - 1; ++i) {
		int u, v = i + 2; scanf("%d", &u);
		tree[--u].push_back(--v);
		tree[v].push_back(u);
	}
	if (n == 2) {
		printf("1\n"); return 0;
	}
	int ROOT = 0;
	magCompute(ROOT, -1);
	printf("%lld\n", direct[ROOT]);
	return 0;
}