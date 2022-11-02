#include <bits/stdc++.h>
using namespace std;

int a[1010];

int main() {
	//freopen("r.in", "r", stdin);
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
	sort(a + 1, a + n + 1);
	int tmp = a[n] + m;
	for (int step = 0; step < m; step ++) {
		a[1] ++;
		sort(a + 1, a + n + 1);
	}
	printf("%d %d\n", a[n], tmp);

	return 0;
}