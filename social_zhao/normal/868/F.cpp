#include<bits/stdc++.h>
#define int long long
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 1e5 + 5;
int n, k, a[N], f[N][25], l = 1, r, ans, cnt[N], now;

void add(int x) {
	ans -= cnt[a[x]] * (cnt[a[x]] - 1) / 2;
	cnt[a[x]]++;
	ans += cnt[a[x]] * (cnt[a[x]] - 1) / 2;
}

void del(int x) {
	ans -= cnt[a[x]] * (cnt[a[x]] - 1) / 2;
	cnt[a[x]]--;
	ans += cnt[a[x]] * (cnt[a[x]] - 1) / 2;
}

void calc(int x, int y) {
	while(r < y) add(++r);
	while(l > x) add(--l);
	while(r > y) del(r--);
	while(l < x) del(l++);
}

void dfs(int u, int v, int x, int y) {
	if(u > v) return;
	int mid = u + v >> 1;
	int pre = 0;
	for(int i = x; i <= min(y, mid - 1); i++) {
		calc(i + 1, mid);
		if(f[i][now - 1] + ans <= f[mid][now])
			pre = i, f[mid][now] = f[i][now - 1] + ans;
	}
	dfs(u, mid - 1, x, pre), dfs(mid + 1, v, pre, y);
}

signed main() {
	memset(f, 0x3f, sizeof(f));
	n = get(), k = get();
	for(int i = 1; i <= n; i++) a[i] = get();
	for(int i = 1; i <= n; i++) calc(1, i), f[i][1] = ans;
	for(int i = 2; i <= k; i++) now = i, dfs(1, n, 0, n - 1);
	printf("%lld", f[n][k]);
	return 0;
}