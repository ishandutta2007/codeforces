#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 2e5 + 5;
int n, l, r;
int a[N], b[N], bel[N], vis[N], f[N], g[N], t1, t2;

void match(int *a, int *b, int l, int r) {
	sort(a + 1, a + 1 + l), sort(b + 1, b + 1 + r);
	for(int i = 1, j = 1; i <= l; i++) {
		while(j <= r && b[j] < a[i]) ++j;
		if(j <= n && b[j] == a[i]) bel[i] = j, ++j;
		else bel[i] = 0;
	}
}

void clear(int n) {
	for(int i = 1; i <= n; i++) a[i] = b[i] = bel[i] = vis[i] = f[i] = g[i] = 0;
	t1 = t2 = 0;
}

void solve() {
	n = get(), l = get(), r = get();
	clear(n);
	for(int i = 1; i <= l; i++) a[i] = get();
	for(int i = 1; i <= r; i++) b[i] = get();
	if(l < r) swap(l, r), swap(a, b);
	match(a, b, l, r);
	int cnt = (l - r) / 2, ans = cnt;
	for(int i = 1; i <= l && cnt; i++) if(!bel[i] && !bel[i - 1] && a[i] == a[i - 1] && !vis[i - 1]) vis[i] = 1, bel[i - 1] = i, cnt--;
	for(int i = 1; i <= l && cnt; i++) if(!vis[i] && !bel[i]) vis[i] = 1, cnt--;
	for(int i = 1; i <= l && cnt; i++) if(!vis[i]) vis[i] = 1, cnt--;
	t1 = t2 = 0;
	for(int i = 1; i <= l; i++) if(vis[i]) g[++t2] = a[i]; else f[++t1] = a[i];
	for(int i = 1; i <= r; i++) g[++t2] = b[i];
	match(f, g, t1, t2);
	for(int i = 1; i <= n / 2; i++) ans += !bel[i];
	printf("%d\n", ans);
}

int main() {
	int T = get();
	while(T--) solve();
	return 0;
}

/*
1
6 2 4
1 1 2 2 2 2
*/