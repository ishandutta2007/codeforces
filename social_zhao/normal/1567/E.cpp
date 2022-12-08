#include<bits/stdc++.h>
#define int long long
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 2e5 + 5;
int n, q, a[N];

struct Node {
	int ans, pre, suf, l, r, len;
	Node() { ans = pre = suf = l = r = len = 0; }
	Node(int x) { ans = pre = suf = len = 1, l = r = x; }
	Node operator +(Node b) const {
		Node res;
		res.ans = ans + b.ans + ((r <= b.l)? suf * b.pre : 0);
		res.pre = pre + ((pre == len && r <= b.l)? b.pre : 0);
		res.suf = b.suf + ((b.suf == b.len && r <= b.l)? suf : 0);
		res.l = l, res.r = b.r, res.len = len + b.len;
		return res;
	}
} t[N << 2];

#define lc (u << 1)
#define rc (u << 1 | 1) 
#define mid ((l + r) >> 1)

void build(int u, int l, int r) {
	if(l == r) return t[u] = Node(a[l]), void();
	build(lc, l, mid), build(rc, mid + 1, r), t[u] = t[lc] + t[rc];
}

void update(int u, int l, int r, int x, int v) {
	if(l == r) return t[u] = Node(v), void();
	if(x <= mid) update(lc, l, mid, x, v);
	else update(rc, mid + 1, r, x, v);
	t[u] = t[lc] + t[rc]; 
}

Node query(int u, int l, int r, int a, int b) {
	if(a == l && r == b) return t[u];
	if(b <= mid) return query(lc, l, mid, a, b);
	else if(a > mid) return query(rc, mid + 1, r, a, b);
	else return query(lc, l, mid, a, mid) + query(rc, mid + 1, r, mid + 1, b);
}

signed main() {
	n = get(), q = get();
	for(int i = 1; i <= n; i++) a[i] = get();
	build(1, 1, n);
	for(int i = 1; i <= q; i++) {
		int op = get(), x = get(), y = get();
		if(op == 1) update(1, 1, n, x, y);
		else printf("%lld\n", query(1, 1, n, x, y).ans);
	}
	return 0;
}