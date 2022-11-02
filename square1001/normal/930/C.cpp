#include <cstdio>
#include <algorithm>
using namespace std;
int n, m, l, r, a[100009], b[100009], v[2][100009];
int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) scanf("%d %d", &l, &r), a[--l]++, a[r]--;
	for (int i = 0; i < m; i++) a[i + 1] += a[i];
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j <= m; j++) b[j] = 1 << 30;
		for (int j = 0; j < m; j++) {
			*lower_bound(b, b + m, a[j] + 1) = a[j];
			v[i][j] = lower_bound(b, b + m, a[j] + 1) - b;
		}
		reverse(a, a + m);
	}
	reverse(v[1], v[1] + m);
	int ret = 0;
	for (int i = 0; i < m; i++) ret = max(ret, v[0][i] + v[1][i] - 1);
	printf("%d\n", ret);
	return 0;
}