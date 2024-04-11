#include <bits/stdc++.h>
using namespace std;
#define N 200200

char s[N], t[N];
int f[N], g[N], bf[N][27];

int main() {
//	freopen("d.in", "r", stdin);
	scanf("%s %s", s + 1, t + 1);
	int n = strlen(s + 1), m = strlen(t + 1);
	f[0] = 0;
	for (int i = 1, j = 0; i <= n; i ++) {
		if (s[i] == t[j+1]) j ++;
		f[i] = j;
	}
	g[n+1] = m + 1;
	for (int i = n, j = m + 1; i >= 1; i --) {
		if (s[i] == t[j-1]) j --;
		g[i] = j;
	}

	for (int j = 0; j < 26; j ++) bf[0][j] = -1;
	for (int i = 1; i <= m; i ++) {
		for (int j = 0; j < 26; j ++) bf[i][j] = bf[i-1][j];
		bf[i][t[i]-'a'] = i;
	}
	for (int j = 0; j < 26; j ++) bf[m+1][j] = bf[m][j];

	for (int i = 1; i <= n; i ++) {
		int a = f[i-1] + 1, b = g[i+1] - 1;
		if (bf[a][s[i]-'a'] < b) {
			puts("No"); return 0;
		}
	}
	puts("Yes");
	return 0;
}