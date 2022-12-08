#include<bits/stdc++.h>
#define mid ((l + r) >> 1)
#define lc (u << 1)
#define rc (u << 1 | 1)
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 2e5 + 5;
int n, a[N];
int lst[N], f[N];
int mx[N << 2];

void update(int u, int l, int r, int x, int v) {
	if(l == r) return mx[u] = v, void(); 
	if(x <= mid) update(lc, l, mid, x, v);
	else update(rc, mid + 1, r, x, v);
	mx[u] = max(mx[lc], mx[rc]);
}

int query(int u, int l, int r, int a, int b) {
	if(a == l && r == b) return mx[u];
	if(b <= mid) return query(lc, l, mid, a, b);
	else if(a > mid) return query(rc, mid + 1, r, a, b);
	else return max(query(lc, l, mid, a, mid), query(rc, mid + 1, r, mid + 1, b));
}

void solve() {
	n = get();
	for(int i = 1; i <= n; i++) a[i] = get(), lst[i] = 0;
	for(int i = 1; i <= n; i++) {
		f[i] = f[i - 1];
		if(!lst[a[i]]) { update(1, 1, n, i, f[i] - i), lst[a[i]] = i; continue; }
		f[i] = max(f[i], query(1, 1, n, lst[a[i]], i - 1) + i - 1);
		update(1, 1, n, i, f[i] - i);
	}
	printf("%d\n", f[n]);
}

int main() {
	solve();
	return 0;
}