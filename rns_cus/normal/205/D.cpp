#include <bits/stdc++.h>
using namespace std;
#define N 200200

int n, a[N], b[N], x[N], cnt, f[N];
map <int, int> mp;

int calc(int m) {
	int rlt = 0;
	for (int i = 1; i <= n; i ++) {
		if (a[i] == m) rlt ++;
	}
	return max(0, (n + 1) / 2 - rlt);
}

int main() {
//	freopen("d.in", "r", stdin);
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) scanf("%d %d", &a[i], &b[i]);
	for (int i = 1; i <= n; i ++) {
		x[cnt++] = a[i];
		x[cnt++] = b[i];
	}
	sort(x, x + cnt);
	cnt = unique(x, x + cnt) - x;
	for (int i = 0; i < cnt; i ++) mp[x[i]] = i;
	for (int i = 1; i <= n; i ++) a[i] = mp[a[i]], b[i] = mp[b[i]];
	for (int i = 1; i <= n; i ++) {
		f[a[i]] ++;
		if (b[i] != a[i]) f[b[i]] ++;
	}
	int ans = n + 1;
    for (int i = 0; i < cnt; i ++) if (f[i] * 2 >= n) ans = min(ans, calc(i));
    if (ans == n + 1) ans = -1;
    printf("%d\n", ans);
	return 0;
}