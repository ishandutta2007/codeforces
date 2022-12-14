#include <bits/stdc++.h>
using namespace std;

#define N 42

int f[N][N][N][N], n, m, T, a, b, c, d;
bool h[N][N][N];
char s[N][N];

void prep() {
	for (int a = 1; a <= n; a ++) for (int c = 1; c <= m; c ++) h[a][a][c] = (s[a][c] == '0');
    for (int a = 1; a < n; a ++) for (int b = a + 1; b <= n; b ++) for (int c = 1; c <= m; c ++) {
        h[a][b][c] = h[a][b-1][c] & h[b][b][c];
    }
    for (int a = 1, k, b, c, d; a <= n; a ++) for (c = a; c <= n; c ++) for (b = 1; b <= m; b ++) for (d = b; d <= m; d ++) {
        if (b == d) {
            f[a][c][b][d] = h[a][c][b];
			continue;
        }
        f[a][c][b][d] = f[a][c][b][d-1];
        k = d;
        while (k >= b && h[a][c][k]) k --;
        f[a][c][b][d] += d - k;
    }
}

int main() {
	scanf("%d %d %d\n", &n, &m, &T);
	for (int i = 1; i <= n; i ++) gets(s[i] + 1);
	prep();
	while (T --) {
		scanf("%d %d %d %d", &a, &b, &c, &d);
        int ans = 0;
        for (int aa = a; aa <= c; aa ++) for (int cc = aa; cc <= c; cc ++) ans += f[aa][cc][b][d];
		printf("%d\n", ans);
	}
	return 0;
}