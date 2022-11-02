#include <cstdio>
#include <algorithm>
#pragma warning(disable : 4996)
using namespace std;
int n, p[100009], inv[100009]; long long l, r, a[100009], b[100009];
int main() {
	scanf("%d%lld%lld", &n, &l, &r);
	for (int i = 0; i < n; i++) scanf("%lld", &a[i]);
	for (int i = 0; i < n; i++) scanf("%d", &p[i]), p[i]--, inv[p[i]] = i;
	b[inv[0]] = l;
	long long lb = b[inv[0]] - a[inv[0]]; bool flag = true;
	for (int i = 1; i < n; i++) {
		b[inv[i]] = max(l, a[inv[i]] + lb + 1);
		lb = b[inv[i]] - a[inv[i]];
		if (b[inv[i]] > r) flag = false;
	}
	if (!flag) puts("-1");
	else {
		for (int i = 0; i < n; i++) {
			if (i) printf(" ");
			printf("%d", b[i]);
		}
		printf("\n");
	}
	return 0;
}