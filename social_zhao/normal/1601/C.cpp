#include<bits/stdc++.h>
#define int long long 
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 1e6 + 5;
int n, m, a[N], b[N];
pair<int, int> bin[N];

struct Node {
	int mx, mp;
	Node operator +(Node b) {
		Node res;
		if(mx < b.mx) res.mx = mx, res.mp = mp;
		else res.mx = b.mx, res.mp = b.mp;
		return res;
	}
} t[N << 2];
int tag[N << 2];

namespace BIT {
	int sum[N];
	void clear() { for(int i = 1; i <= n; i++) sum[i] = 0; }
	int lowbit(int x) { return x & (-x); }
	void add(int x, int v) { while(x <= n) sum[x] += v, x += lowbit(x); }
	int ask(int x) { int r(0); while(x) r += sum[x], x -= lowbit(x); return r; }
}

int tmp[N], len;

int calc() {
	BIT::clear();
	for(int i = 1; i <= n; i++) tmp[i] = a[i];
	sort(tmp + 1, tmp + 1 + n), len = unique(tmp + 1, tmp + 1 + n) - tmp - 1;
	for(int i = 1; i <= n; i++) a[i] = lower_bound(tmp + 1, tmp + 1 + len, a[i]) - tmp;
	int res = 0;
	for(int i = n; i >= 1; i--) {
		res += BIT::ask(a[i] - 1);
		BIT::add(a[i], 1);
	}
	return res;
} 

#define lc (u << 1)
#define rc (u << 1 | 1)
#define mid ((l + r) >> 1) 
void pusht(int u, int v) { tag[u] += v, t[u].mx += v; }
void pushdown(int u) { if(tag[u]) pusht(lc, tag[u]), pusht(rc, tag[u]), tag[u] = 0; }
void pushup(int u) { t[u] = t[lc] + t[rc]; }

void build(int u, int l, int r) {
	tag[u] = 0;
	if(l == r) return t[u].mx = 0, t[u].mp = l, void();
	build(lc, l, mid), build(rc, mid + 1, r);
	pushup(u);
}

void update(int u, int l, int r, int a, int b, int v) {
	if(a == l && r == b) return pusht(u, v);
	pushdown(u);
	if(b <= mid) update(lc, l, mid, a, b, v);
	else if(a > mid) update(rc, mid + 1, r, a, b, v);
	else update(lc, l, mid, a, mid, v), update(rc, mid + 1, r, mid + 1, b, v);
	pushup(u); 
}

Node query(int u, int l, int r, int a, int b) {
	if(a == l && r == b) return t[u];
	pushdown(u);
	if(b <= mid) return query(lc, l, mid, a, b);
	else if(a > mid) return query(rc, mid + 1, r, a, b);
	else return query(lc, l, mid, a, mid) + query(rc, mid + 1, r, mid + 1, b); 
}

void debug(int u, int l, int r) {
	if(l == r){ cout << t[u].mx << " "; return; }
	pushdown(u); 
	debug(lc, l, mid), debug(rc, mid + 1, r);
}

void solve() {
	n = get(), m = get();
	for(int i = 1; i <= n; i++) a[i] = get(), bin[i] = { a[i], i };
	for(int i = 1; i <= m; i++) b[i] = get();
	sort(b + 1, b + 1 + m), sort(bin + 1, bin + 1 + n);
	build(1, 1, n + 1);
	for(int i = 1; i <= n; i++) update(1, 1, n + 1, i + 1, n + 1, 1);
	int l = 1, r = 0, now = 1, ans = 0;
//	debug(1, 1, n + 1), cout << endl;
	for(int i = 1; i <= m; i++) {
		while(r + 1 <= n && bin[r + 1].first <= b[i]) {
			update(1, 1, n + 1, bin[r + 1].second + 1, n + 1, -1);
			++r;
		}
		while(l <= n && bin[l].first < b[i]) {
			update(1, 1, n + 1, 1, bin[l].second, 1);
			++l;
		}
		Node res = query(1, 1, n + 1, now, n + 1);
		ans += res.mx, now = res.mp;
//		debug(1, 1, n + 1), cout << endl;
	}
	cout << ans + calc() << endl;
}

main() {
	int T = get();
	while(T--) solve();
	return 0;
}

/*
1
3 3
3 2 1
1 2 3
*/