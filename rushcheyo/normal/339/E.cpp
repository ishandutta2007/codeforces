#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
int n, a[N], l[3], r[3];

void dfs(int k) {
	bool flag = true;
	for (int i = 1; i <= n && flag; i++)
		if (a[i] != i) flag = false;
	if (flag) {
		printf("%d\n", k);
		for (int i = k - 1; i >= 0; i--)
			printf("%d %d\n", l[i], r[i]);
		exit(0);
	}
	if (k == 3) return;
	for (int i = 1; i < n; i++)
		if (a[i] != i && (abs(a[i] - a[i + 1]) != 1 || abs(a[i] - a[i - 1]) != 1))
			for (int j = i + 1; j <= n; j++)
				if (a[j] != j && (abs(a[j] - a[j + 1]) != 1 || abs(a[j] - a[j - 1]) != 1)) {
					reverse(a + i, a + j + 1);
					l[k] = i, r[k] = j;
					dfs(k + 1);
					reverse(a + i, a + j + 1);
				}
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", a + i);
	a[0] = a[n + 1] = -1;
	dfs(0);
}