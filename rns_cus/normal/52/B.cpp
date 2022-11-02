#include <bits/stdc++.h>
using namespace std;
#define N 1010

int n, m, a[N], b[N];
char s[N][N];

int main() {
//	freopen("b.in", "r", stdin);
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i ++) scanf("%s", s[i]);
	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < m; j ++) {
			if (s[i][j] == '*') a[i] ++, b[j] ++;
		}
	}
	long long ans = 0;
	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < m; j ++) if (s[i][j] == '*') {
			ans += (a[i] - 1) * (b[j] - 1);
		}
	}
	printf("%I64d\n", ans);
	return 0;
}