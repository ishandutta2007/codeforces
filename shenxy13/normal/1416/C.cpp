#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int, int> ii;
struct Fenwick {
	vector<int> ft;
	Fenwick(int N) {
		for (int i = 0; i <= N; ++i) ft.push_back(0);
	}
	void update(int i, int v) {
		for (; i < ft.size(); i += i & -i) ft[i] += v;
	}
	int query(int a) {
		int ans = 0;
		for (; a > 0; a -= a & -a) ans += ft[a];
		return ans;
	}
};
int main() {
	int n;
	scanf("%d", &n);
	int a[n], x = 0;
	long long ans = 0, inv = 0;
	for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
	ii b[n];
	for (int i = 0; i < n; ++i) b[i] = ii(a[i], i + 1);
	sort(b, b + n);
	Fenwick fw(n);
	for (int i = 0; i < n; ++i) inv += fw.query(n) - fw.query(b[i].second), fw.update(b[i].second, 1);
	ans = inv;
	for (int i = 29; i >= 0; --i) {
		long long ak = 0;
		for (int j = 0; j < n; ++j) b[j] = ii(a[j] ^ (1 << i), j + 1);
		for (int j = 0; j <= n; ++j) fw.ft[j] = 0;
		sort(b, b + n);
		for (int i = 0; i < n; ++i) ak += fw.query(n) - fw.query(b[i].second), fw.update(b[i].second, 1);
		if (ak < inv) ans += ak - inv, x += 1 << i;
	}
	printf("%lld %d", ans, x);
	return 0;
}