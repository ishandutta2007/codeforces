#include <bits/stdc++.h>
using namespace std;
#define N 300300

int n, a[N], T, b[N], c[N];
map <int, int> vis;

int main() {
//	freopen("c.in", "r", stdin);
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
	int st = 1;
	T = 1;
	for (int i = 1; i <= n; i ++) {
		if (vis[a[i]] == T) {
			b[++T] = st, c[T] = i;
			st = i + 1;
		}
		else vis[a[i]] = T;
	}
	if (T == 1) {
		puts("-1"); return 0;
	}
	if (c[T] != n) c[T] = n;
	printf("%d\n", T - 1);
	for (int i = 2; i <= T; i ++) {
		printf("%d %d\n", b[i], c[i]);
	}
	return 0;
}