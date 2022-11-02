#include <bits/stdc++.h>
using namespace std;
#define N 100100

int a[N], nxt[N][5], f[N], g[N];
char s[N];

int main() {
//	freopen("c.in", "r", stdin);
	scanf("%s", s + 1);
	int n = strlen(s + 1);
	for (int i = 1; i <= n; i ++) {
		if (s[i] == '[') a[i] = 0;
		else if (s[i] == ']') a[i] = 1;
		else if (s[i] == '(') a[i] = 2;
		else a[i] = 3;
	}
	for (int j = 0; j < 4; j ++) nxt[n+1][j] = n + 1;
	for (int i = n; i >= 1; i --) {
		for (int j = 0; j < 4; j ++) nxt[i][j] = nxt[i+1][j];
		nxt[i][a[i]] = i;
	}

	int num = 0;
	for (int i = 1; i <= n + 1; i ++) f[i] = i - 1;
	for (int i = n; i >= 1; i --) {
		if (a[i] & 1) continue;
		int x = f[i+1] + 1;
		if (x == n + 1 || a[x] != a[i] + 1) continue;
		f[i] = f[x+1];
		g[i] = g[i+1] + g[x+1];
		if (a[i] == 0) g[i] ++;
		if (g[i] > g[num]) num = i;
	}
	if (num == 0) {
		puts("0"); return 0;
	}
	printf("%d\n", g[num]);
	for (int i = num; i <= f[num]; i ++) printf("%c", s[i]); puts("");
	return 0;
}