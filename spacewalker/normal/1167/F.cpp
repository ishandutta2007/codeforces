#include <bits/stdc++.h>

using namespace std;
using ll = long long;
constexpr ll MOD = 1000000007;

struct fenwick {
	int n;
	vector<ll> tree;
	fenwick(int n) : n(n), tree(n + 1, 0) {}
	int LSB(int x) {return (x&(-x));}
	void add(int i, ll v) {
		for (int ci = i + 1; ci <= n; ci += LSB(ci)) tree[ci] += v;
	}
	ll getPrefix(int i) {
		ll ans = 0;
		for (int ci = i + 1; ci > 0; ci -= LSB(ci)) ans += tree[ci];
		return ans % MOD;
	}
	ll getRange(int i, int j) {
		return (getPrefix(j) - getPrefix(i - 1) + MOD) % MOD;
	}
};

int main() {
	int n; scanf("%d", &n);
	vector<ll> arr(n);
	for (int i = 0; i < n; ++i) scanf("%lld", &arr[i]);
	vector<ll> sortIdx(n);
	for (int i = 0; i < n; ++i) sortIdx[i] = i;
	sort(begin(sortIdx), end(sortIdx), [&arr] (int i, int j) {
		return arr[i] < arr[j];
	});
	fenwick leftFacing(n), rightFacing(n);
	ll ans = 0;
	for (int i = 0; i < n; ++i) {
		ll selfContrib = (sortIdx[i] + 1) * (n - sortIdx[i]) % MOD;
		ll leftContrib = leftFacing.getRange(0, sortIdx[i]) * (n - sortIdx[i]) % MOD;
		ll rightContrib = rightFacing.getRange(sortIdx[i], n - 1) * (sortIdx[i] + 1) % MOD;
		ans += arr[sortIdx[i]] * (selfContrib + leftContrib + rightContrib) % MOD;
		leftFacing.add(sortIdx[i], sortIdx[i] + 1);
		rightFacing.add(sortIdx[i], n - sortIdx[i]);
	}
	printf("%lld\n", ans % MOD);
	return 0;
}