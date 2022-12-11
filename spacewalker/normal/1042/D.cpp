#include <cstdio>
#include <vector>
#include <algorithm>
#define LSB(i) ((i)&(-i))

using namespace std;
typedef long long ll;

struct fenwick {
	vector<ll> tree;
	int n;
	fenwick() {}
	fenwick(int n) : tree(n+1), n(n) {}
	void add(int i, int v) {
		for (int ci = i + 1; ci <= n; ci += LSB(ci)) tree[ci] += v;
	}
	ll sum(int i) {
		ll ans = 0;
		for (int ci = i + 1; ci > 0; ci -= LSB(ci)) ans += tree[ci];
		return ans;
	}
	ll sum(int i, int j) {
		return sum(j) - sum(i-1);
	}
};

/*
we do a sweep.
S[R] - S[L-1] < t
- S[L-1] < t - S[R]
S[L-1] > S[R] - t
*/

int main() {
	int n; ll t; scanf("%d %lld", &n, &t);
	vector<int> arr(n);
	for (int i = 0; i < n; ++i) scanf("%d", &arr[i]);
	vector<ll> ps(n + 1);
	for (int i = 1; i <= n; ++i) ps[i] = ps[i-1] + arr[i-1];
	++n;
	vector<int> sortOrder(n);
	for (int i = 0; i < n; ++i) sortOrder[i] = i;
	sort(sortOrder.begin(), sortOrder.end(), [&ps] (int i, int j) {return ps[i] < ps[j];});
	vector<int> placeInSort(n);
	vector<ll> sortValue(n);
	for (int i = 0; i < n; ++i) placeInSort[sortOrder[i]] = i;
	for (int i = 0; i < n; ++i) sortValue[i] = ps[sortOrder[i]];
	fenwick ftree(n);
	ll ans = 0;
	for (int i = 0; i < n; ++i) {
		// first we check the sum contrib
		int placeToCheck = distance(sortValue.begin(), upper_bound(sortValue.begin(), sortValue.end(), ps[i] - t));
		if (placeToCheck < n) {
			ans += ftree.sum(placeToCheck, n - 1);
		}
		ftree.add(placeInSort[i], 1);
	}
	printf("%lld\n", ans);
	return 0;
}