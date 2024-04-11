#include <bits/stdc++.h>
using namespace std;

int n, x, cnt, a[1001001];

int main() {
//	freopen("a.in", "r", stdin);
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) {
		bool good = 1;
		for (int j = 1; j <= n; j ++) {
			scanf("%d", &x);
			if (x < 0) continue;
			if (x & 1) good = 0;
		}
		if (good) a[++cnt] = i;
	}
	printf("%d\n", cnt);
	for (int i = 1; i <= cnt; i ++) printf("%d%c", a[i], i < cnt ? ' ' : '\n');
	return 0;
}