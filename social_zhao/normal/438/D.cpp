#include<bits/stdc++.h>
#define int long long
#define lc (u << 1)
#define rc (u << 1 | 1)
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 1e5 + 5;
int n, m;
int sum[N << 2], mx[N << 2];

void pushup(int u) { sum[u] = sum[lc] + sum[rc], mx[u] = max(mx[lc], mx[rc]); }
void build(int u, int l, int r) {
	if(l == r) return void(sum[u] = mx[u] = get());
	int mid = l + r >> 1;
	build(lc, l, mid), build(rc, mid + 1, r);
	pushup(u);
}
void update(int u, int l, int r, int x, int v) {
	if(l == r) return void(sum[u] = mx[u] = v);
	int mid = l + r >> 1;
	if(x <= mid) update(lc, l, mid, x, v);
	else update(rc, mid + 1, r, x, v);
	pushup(u);
}
void mod(int u, int l, int r, int a, int b, int p) {
	if(l > b || r < a || mx[u] < p) return;
	if(l == r) return void((sum[u] %= p, mx[u] %= p));
	int mid = l + r >> 1;
	if(a <= mid) mod(lc, l, mid, a, b, p);
	if(b > mid) mod(rc, mid + 1, r, a, b, p);
	pushup(u);
}
int query(int u, int l, int r, int a, int b) {
	if(a == l && r == b) return sum[u];
	int mid = l + r >> 1;
	if(b <= mid) return query(lc, l, mid, a, b);
	else if(a > mid) return query(rc, mid + 1, r, a, b);
	else return query(lc, l, mid, a, mid) + query(rc, mid + 1, r, mid + 1, b);
}

signed main() {
	n = get(), m = get();
	build(1, 1, n);
	for(int i = 1; i <= m; i++) {
		int opt = get(), x = get(), y = get(), z;
		if(opt == 1) printf("%lld\n", query(1, 1, n, x, y));
		if(opt == 2) z = get(), mod(1, 1, n, x, y, z);
		if(opt == 3) update(1, 1, n, x, y);
	}
	return 0;
}