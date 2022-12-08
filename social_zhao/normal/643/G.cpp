#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 2e5 + 5;
int n, m, p, k, bin[10], top, a[N];

struct Node {
	int val[5], cnt[5];
	Node() { memset(val, 0, sizeof(val)), memset(cnt, 0, sizeof(cnt)); }
	Node(int x, int c) { memset(val, 0, sizeof(val)), memset(cnt, 0, sizeof(cnt)), val[0] = x, cnt[0] = c; }
	void insert(int v, int c) {
		for(int i = 0; i < k; i++) if(val[i] == v) return cnt[i] += c, void();
		for(int i = 0; i < k; i++) if(!val[i]) return val[i] = v, cnt[i] = c, void();
		int mn = c;
		for(int i = 0; i < k; i++) mn = min(mn, cnt[i]);
		for(int i = 0; i < k; i++) { cnt[i] -= mn; if(!cnt[i]) val[i] = 0; }
		c -= mn;
		if(c) for(int i = 0; i < k; i++) if(!val[i]) return val[i] = v, cnt[i] = c, void();
	}
	Node operator +(Node b) {
		Node res = *this;
		for(int i = 0; i < k; i++) if(b.val[i]) res.insert(b.val[i], b.cnt[i]);
		return res;
	}
} t[N << 2];
int tag[N << 2], len[N << 2];

#define mid ((l + r) >> 1)
#define lc (u << 1)
#define rc (u << 1 | 1)

void pushup(int u) { t[u] = t[lc] + t[rc], len[u] = len[lc] + len[rc]; }
void pusht(int u, int v) { tag[u] = v, t[u] = Node(v, len[u]); }
void pushdown(int u) { if(tag[u]) pusht(lc, tag[u]), pusht(rc, tag[u]), tag[u] = 0; }

void build(int u, int l, int r) {
	if(l == r) return t[u] = Node(a[l], 1), len[u] = 1, void();
	build(lc, l, mid), build(rc, mid + 1, r), pushup(u); 
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

int main() {
	n = get(), m = get(), p = get(), k = 100 / p;
	for(int i = 1; i <= n; i++) a[i] = get();
	build(1, 1, n);
	for(int i = 1; i <= m; i++) {
		int op = get(), l = get(), r = get();
		if(op == 1) update(1, 1, n, l, r, get());
		else {
			Node res = query(1, 1, n, l, r); top = 0;
			for(int i = 0; i < k; i++) if(res.val[i]) bin[++top] = res.val[i];
			printf("%d ", top); for(int i = 1; i <= top; i++) printf("%d ", bin[i]); printf("\n");
		}
	}
	return 0;
}