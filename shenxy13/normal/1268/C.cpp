#include <cstdio>
#include <algorithm>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> os;
struct Fenwick {
	int n;
	long long ft[200001];
	Fenwick(int N) {
		n = N;
		fill_n(ft, n + 1, 0);
	}
	void update(int i, int v) {
		for (; i <= n; i += i & -i) ft[i] += v;
	}
	int query(int a, int b) {
		long long ans = 0;
		for (; b > 0; b -= b & -b) ans += ft[b];
		for (a -= 1; a > 0; a -= a & -a) ans -= ft[a];
		return ans;
	}
};
int main() {
	int n;
	scanf("%d", &n);
	int p[n], id[n];
	for (int i = 0; i < n; ++i) scanf("%d", &p[i]);
	for (int i = 0; i < n; ++i) id[p[i] - 1] = i;
	os why;
	why.insert(id[0]);
	printf("0 ");
	long long ans = 0;
	Fenwick f(n);
	f.update(id[0] + 1, 1);
	for (int i = 1; i < n; ++i) {
		if (i % 2) {
			int x = *why.find_by_order(i / 2);
			ans += max(id[i], x) - min(id[i], x) - f.query(min(id[i] + 1, x + 1), max(id[i] + 1, x + 1));
		} else {
			int x = *why.find_by_order(i / 2 - 1), y = *why.find_by_order(i / 2);
			if (y < id[i]) ans += id[i] - y - f.query(y + 1, id[i] + 1);
			else if (x > id[i]) ans += x - id[i] - f.query(id[i] + 1, x + 1);
		}
		int k = why.order_of_key(id[i]);
		ans -= min(k, i - k);
		ans += i - k;
		why.insert(id[i]);
		f.update(id[i] + 1, 1);
		printf("%lld ", ans);
	}
	return 0;
}