#include <bits/stdc++.h>
using namespace std;

#define N 5050

int n, m, rmh[N][N], h[N];
char s[N][N];

int main() {
	scanf("%d %d\n", &n, &m);
	for (int i = 1; i <= n; i ++) gets(s[i] + 1);
    for (int i = 1; i <= n; i ++) {
		if (s[i][m] == '1') rmh[i][m] = m + 1;
		else rmh[i][m] = m;
    }
    for (int i = 1; i <= n; i ++) {
		for (int j = m - 1; j >= 1; j --) {
			if (s[i][j] == '1') rmh[i][j] = rmh[i][j+1];
			else rmh[i][j] = j;
		}
    }
    int ans = 0;
    for (int j = 1; j <= m; j ++) {
		for (int i = 1; i <= n; i ++) h[i] = rmh[i][j] - j;
		sort (h + 1, h + n + 1);
		for (int i = 1; i <= n; i ++) ans = max(ans, h[i] * (n - i + 1));
    }
    printf("%d\n", ans);
	return 0;
}