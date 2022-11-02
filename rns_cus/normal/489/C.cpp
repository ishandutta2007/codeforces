#include <bits/stdc++.h>
using namespace std;

int s, m, a[111], b[111];

int main() {
//	freopen("c.in", "r", stdin);
	scanf("%d %d", &m, &s);
	if (m > 1 && !s || s > m * 9) {
		puts("-1 -1"); return 0;
	}
	int sum = s;
	for (int i = 0; i < m; i ++) {
		a[i] = min(9, sum);
		sum -= a[i];
	}
	sum = s;
	for (int i = m - 1; i; i --) {
		b[i] = min(9, sum - 1);
		sum -= b[i];
	}
	b[0] = sum;
	for (int i = 0; i < m; i ++) printf("%d", b[i]);
	printf(" ");
	for (int i = 0; i < m; i ++) printf("%d", a[i]);
	puts("");
	return 0;
}