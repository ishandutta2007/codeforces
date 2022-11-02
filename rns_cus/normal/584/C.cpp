#include <bits/stdc++.h>
using namespace std;
#define N 100100

int n, t;
char a[N], b[N], c[N];

char dif(char a, char b) {
	for (char c = 'a'; c <= 'z'; c ++) {
		if (c != a && c != b) return c;
	}
}

int main() {
//	freopen("c.in", "r", stdin);
	scanf("%d %d %s %s", &n, &t, a + 1, b + 1);
	int same = 0;
	for (int i = 1; i <= n; i ++) if (a[i] == b[i]) same ++;
	t = n - t;
	if (same + 2 * (t - same) > n) {
		puts("-1"); return 0;
	}
	int x = t, y = t;
	for (int i = 1; i <= n; i ++) {
		if (a[i] != b[i]) continue;
		if (x) c[i] = a[i], x --, y --;
		else c[i] = dif(a[i], b[i]);
	}
	for (int i = 1; i <= n; i ++) {
		if (a[i] == b[i]) continue;
		if (x) c[i] = a[i], x --;
		else if (y) c[i] = b[i], y --;
		else c[i] = dif(a[i], b[i]);
	}
	puts(c + 1);
	return 0;
}