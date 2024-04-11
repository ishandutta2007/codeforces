#include <bits/stdc++.h>
using namespace std;

#define N 111

int n, m, a[N], k;
char s[N][N];
bool vis[N], tag[3], flag[2];

int main() {
	scanf("%d %d %d\n", &n, &m, &k);
	k ++;
	for (int i = 1, b, c; i <= n; i ++) {
		gets(s[i] + 1);
		tag[0] = tag[1] = tag[2] = 0;
        for (int j = 1; j <= m; j ++) {
			if (s[i][j] == 'G') tag[0] = 1, b = j;
			else if (s[i][j] == 'R') tag[1] = 1, c = j;
			else tag[2] = 1;
        }
        a[i] = abs(b - c) - 1;
        if (tag[0] && tag[1]) vis[i] = 1;
        else if (tag[0] && tag[2]) flag[0] = 1;
        else if (tag[1] && tag[2]) flag[1] = 1;
	}
	if (flag[0] && flag[1]) {
		puts("Draw");
		return 0;
	}
	if (flag[0]) {
		puts("First");
		return 0;
	}
	if (flag[1]) {
		puts("Second");
		return 0;
	}
	bool tag = 0;
	for (int t = 1, now; t < N && !tag; t <<= 1) {
		now = 0;
		for (int i = 1; i <= n; i ++) if (vis[i]) if (t & a[i]) now ++;
		if (now % k) tag = 1;
	}
	if (tag) puts("First");
	else puts("Second");
	return 0;
}