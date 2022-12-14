#include <bits/stdc++.h>
using namespace std;

#define N 100010

int n, x[N], y[N], z[N], T, st, en;
char s[N];

int main() {
	gets(s + 1);
	n = strlen(s + 1);
	for (int i = 1; i <= n; i ++) {
		x[i] = x[i-1];
		y[i] = y[i-1];
		z[i] = z[i-1];
		if (s[i] == 'x') x[i] ++;
		if (s[i] == 'y') y[i] ++;
		if (s[i] == 'z') z[i] ++;
	}
	scanf("%d", &T);
	int xx, yy, zz, m, tag;
	while (T --) {
		scanf("%d %d", &st, &en);
		if (en <= st + 1) {
			puts("YES");
			continue;
		}
		xx = x[en] - x[st-1];
		yy = y[en] - y[st-1];
		zz = z[en] - z[st-1];
		m = min(xx, min(yy, zz));
		tag = max(xx - m, max(yy - m, zz - m));
		if (tag <= 1) puts("YES");
		else puts("NO");
	}
	return 0;
}