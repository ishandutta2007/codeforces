#include <vector>
#include <iostream>
#include <algorithm>
#pragma warning(disable : 4996)
using namespace std;
const int inf = 1012345678;
int n, a[20][200009], b[20][200009], cl[200009];
int q1(int l, int r) { return l == r ? -inf : max(a[cl[r - l]][l], a[cl[r - l]][r - (1 << cl[r - l])]); }
int q2(int l, int r) { return l == r ? inf : min(b[cl[r - l]][l], b[cl[r - l]][r - (1 << cl[r - l])]); }
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &a[0][i]);
	for (int i = 0; i < n; i++) scanf("%d", &b[0][i]);
	for (int i = 1; i <= n; i++) {
		while (1 << cl[i] <= i) cl[i]++; cl[i]--;
	}
	for (int i = 0; i < 18; i++) {
		for (int j = 0; j < n; j++) {
			a[i + 1][j] = max(a[i][j], a[i][j + (1 << i)]);
			b[i + 1][j] = min(b[i][j], b[i][j + (1 << i)]);
		}
	}
	long long ret = 0;
	for (int i = 0; i < n; i++) {
		int l1 = i, r1 = n + 1;
		while (r1 - l1 > 1) {
			int m = (l1 + r1) >> 1;
			if (q1(i, m) < q2(i, m)) l1 = m;
			else r1 = m;
		}
		int l2 = i, r2 = n + 1;
		while (r2 - l2 > 1) {
			int m = (l2 + r2) >> 1;
			if (q1(i, m) <= q2(i, m)) l2 = m;
			else r2 = m;
		}
		ret += l2 - l1;
	}
	printf("%lld\n", ret);
	return 0;
}