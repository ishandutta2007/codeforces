#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr ll MOD = 1000000007;

struct fenwick {
	int n; vector<ll> tree;
	bool modOut;
	fenwick(int n) : n(n), tree(n + 1) {}
	fenwick(vector<ll> init, bool modOut) : n(init.size()), tree(init.size() + 1), modOut(modOut) {
		for (int i = 0; i < n; ++i) add(i, init[i]);
	}
	int LSB(int i) {return (i & (-i));}
	void add(int i, ll v) {
		for (int ci = i + 1; ci <= n; ci += LSB(ci)) { 
			tree[ci] = (tree[ci] + v);
			if (modOut) tree[ci] %= MOD;
		}
	}
	ll getPrefix(int i) {
		ll ans = 0;
		for (int ci = i + 1; ci > 0; ci -= LSB(ci)) {
			ans += tree[ci];
			if (modOut) ans %= MOD;
		}
//		printf("getPrefix %d has ans %lld mo %d\n", i, ans, modOut);
		return ans;
	}
	ll getRange(int i, int j) {
		ll ans = getPrefix(j) - getPrefix(i - 1);
		if (modOut) ans = (ans + MOD) % MOD;
		return ans;
	}
};

int main() {
	int n, q; scanf("%d %d", &n, &q);
	vector<ll> boxPos(n);
	for (int i = 0; i < n; ++i) scanf("%lld", &boxPos[i]);
	for (int i = 0; i < n; ++i) boxPos[i] -= i;
	vector<ll> weights(n);
	for (int i = 0; i < n; ++i) scanf("%lld", &weights[i]);
	vector<ll> weightedSum(n);
	for (int i = 0; i < n; ++i) {
		weightedSum[i] = (boxPos[i] * weights[i]) % MOD;	
	}
	fenwick sWeights(weights, false), wbProd(weightedSum, true);
	for (int qta = 0; qta < q; ++qta) {
		int x, y; scanf("%d %d", &x, &y);
		if (x < 0) {
			x = -(x + 1);
			sWeights.add(x, -weights[x]);
			wbProd.add(x, (MOD - boxPos[x] * weights[x] % MOD) % MOD);
			weights[x] = y;
			sWeights.add(x, weights[x]);
			wbProd.add(x, boxPos[x] * weights[x] % MOD);
		} else {
			--x; --y;
			int lo = x, hi = y;
			ll rangewSum = sWeights.getRange(x, y);
			while (lo < hi) {
				int mid = (lo + hi) / 2;
//				printf("need %lld, range has %lld * 2 = %lld\n", rangewSum, sWeights.getRange(x, mid), sWeights.getRange(x, mid) * 2);
				if (sWeights.getRange(x, mid) * 2 >= rangewSum) hi = mid;
				else lo = mid + 1;
			}
//			printf("converging at %d\n", lo);
			ll centerPoint = boxPos[lo];
			ll ans = (sWeights.getRange(x, lo) % MOD * centerPoint % MOD - wbProd.getRange(x, lo) + MOD) % MOD;
			if (lo < y) {
				ans = (ans + (wbProd.getRange(lo + 1, y) - sWeights.getRange(lo + 1, y) % MOD * centerPoint % MOD + MOD) % MOD) % MOD;
			}
			printf("%lld\n", ans);
		}
	}
	return 0;
}