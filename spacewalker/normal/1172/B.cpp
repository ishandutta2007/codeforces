#include <bits/stdc++.h>

using namespace std;
using ll = long long;
constexpr ll MOD = 998244353;
constexpr int NMAX = 200010;
ll fact[NMAX];

vector<vector<int>> tree;

ll countWays(int v, int p) {
	// printf("countways %d %d\n", v, p);
	ll ans = 1;
	int stc = 0;
	for (int child : tree[v]) {
		if (child != p) {
			ans = (ans * countWays(child, v)) % MOD;
			stc++;
		}
	}
	if (p != -1) {
		return (ans * fact[stc + 1]) % MOD;
	} else {
		return (ans * fact[stc]) % MOD;
	}
}

int main() {
	fact[0] = 1;
	for (int i = 1; i < NMAX; ++i) {
		fact[i] = (fact[i-1] * i) % MOD;
	}
		// printf("pp loop\n");
	int n; scanf("%d", &n);
	tree = vector<vector<int>>(n);
	for (int i = 0; i < n - 1; ++i) {
		int a, b; scanf("%d %d", &a, &b);
		tree[--a].push_back(--b);
		tree[b].push_back(a);
	}
	printf("%lld\n", (n * countWays(0, -1)) % MOD);
	return 0;
}