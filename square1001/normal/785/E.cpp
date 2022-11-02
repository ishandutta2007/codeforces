#include <cmath>
#include <cstdio>
#include <algorithm>
#pragma warning(disable : 4996)
using namespace std;
int n, q, b, x, y, a[200009], ptr[200009], bit[455][200009];
void add(int p, int i, int x) {
	for (int k = i; k <= n; k += k & (-k)) bit[p][k] += x;
}
int sum(int p, int r) {
	int ret = 0;
	for (int k = r; k >= 1; k -= k & (-k)) ret += bit[p][k];
	return ret;
}
int query(int r, int x) {
	int ret = 0;
	int d = ptr[r];
	for (int i = 0; i < d; i++) ret += sum(i, x - 1);
	for (int i = n * d / b; i < r; i++) ret += a[i] < x;
	return ret;
}
int main() {
	scanf("%d %d", &n, &q);
	b = sqrt(n) / 5 + 1;
	for (int i = 0; i < b; i++) {
		int pl = i * n / b, pr = (i + 1) * n / b;
		for (int j = pl; j < pr; j++) ptr[j] = i;
	}
	for (int i = 0; i < n; i++) {
		a[i] = i + 1;
		add(ptr[i], a[i], 1);
	}
	long long f = 1LL * n * (n - 1) >> 1, ret = 0;
	for (int i = 0; i < q; i++) {
		scanf("%d %d", &x, &y); x--, y--;
		if (x != y) {
			ret += query(x, a[x]) * 2;
			ret += query(y, a[y]) * 2;
			ret -= query(x, a[y]) * 2;
			ret -= query(y, a[x]) * 2;
			ret--;
			add(ptr[x], a[x], -1);
			add(ptr[y], a[y], -1);
			add(ptr[x], a[y], 1);
			add(ptr[y], a[x], 1);
			swap(a[x], a[y]);
		}
		printf("%lld\n", ret);
	}
	return 0;
}