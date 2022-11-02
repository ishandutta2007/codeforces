#include <set>
#include <cstdio>
#pragma warning(disable : 4996)
using namespace std;
int n, m, a[200009]; bool f[200009];
int main() {
	scanf("%d %d", &n, &m);
	set<int> s; int c0 = 0, c1 = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		if (s.count(a[i])) f[i] = true;
		else {
			if (a[i] % 2 == 0) c0++;
			else c1++;
			s.insert(a[i]);
		}
	}
	int d0 = 2, d1 = 1, ret = 0; bool ok = true;
	for (int i = 0; i < n; i++) {
		if (f[i]) {
			while (s.count(d0)) d0 += 2;
			while (s.count(d1)) d1 += 2;
			if (c0 * 2 < n && d0 <= m) {
				c0++; a[i] = d0; d0 += 2;
			}
			else if (c1 * 2 < n && d1 <= m) {
				c1++; a[i] = d1; d1 += 2;
			}
			else ok = false;
			ret++;
		}
	}
	if (!ok) printf("-1\n");
	else {
		for (int i = 0; i < n; i++) {
			while (s.count(d0)) d0 += 2;
			while (s.count(d1)) d1 += 2;
			if (c0 > c1 && a[i] % 2 == 0 && d1 <= m) {
				c0--; c1++; a[i] = d1; d1 += 2; ret++;
			}
			else if (c0 < c1 && a[i] % 2 == 1 && d0 <= m) {
				c0++; c1--; a[i] = d0; d0 += 2; ret++;
			}
		}
		if (c0 != c1) printf("-1\n");
		else {
			printf("%d\n", ret);
			for (int i = 0; i < n; i++) printf("%d ", a[i]);
		}
	}
	return 0;
}