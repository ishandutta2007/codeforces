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
int n, m, q, cnt[32], a[N];

struct Map {
	int f[32];
	Map() { memset(f, 0, sizeof(f)); }
	Map(int x) {
		memset(f, 0, sizeof(f));
		if(!x) for(int i = 0; i < 1 << m; i++) f[i] = (i >> 1) | (1 << (m - 1));
		else for(int i = 0; i < 1 << m; i++) 
			f[i] = (i >> 1) | ((cnt[i] != m) << (m - 1));
	}
	Map operator *(Map b) {
		Map res;
		for(int i = 0; i < 1 << m; i++) res.f[i] = f[b.f[i]];
		return res;
	}
} t[N << 2], rev[N << 2];
int tag[N << 2];

void pushup(int u) { t[u] = t[lc] * t[rc], rev[u] = rev[lc] * rev[rc]; }
void pusht(int u) { tag[u] ^= 1, swap(t[u], rev[u]); }
void pushdown(int u) { if(tag[u]) pusht(lc), pusht(rc); tag[u] = 0; }

void build(int u, int l, int r) {
	if(l == r) return t[u] = Map(a[l] & 1), rev[u] = Map(!(a[l] & 1)), void();
	build(lc, l, mid), build(rc, mid + 1, r), pushup(u);
}

void update(int u, int l, int r, int a, int b) {
	if(a == l && r == b) return pusht(u);
	pushdown(u);
	if(b <= mid) update(lc, l, mid, a, b);
	else if(a > mid) update(rc, mid + 1, r, a, b);
	else update(lc, l, mid, a, mid), update(rc, mid + 1, r, mid + 1, b);
	pushup(u);
}

Map query(int u, int l, int r, int a, int b) {
	if(a == l && r == b) return t[u];
	pushdown(u);
	if(b <= mid) return query(lc, l, mid, a, b);
	else if(a > mid) return query(rc, mid + 1, r, a, b);
	else return query(lc, l, mid, a, mid) * query(rc, mid + 1, r, mid + 1, b); 
}

int main() {
	n = get(), m = get(), q = get();
	for(int i = 1; i < 1 << m; i++) cnt[i] = cnt[i >> 1] + (i & 1);
	for(int i = 1; i <= n; i++) a[i] = get();
	build(1, 1, n);
	for(int i = 1; i <= q; i++) {
		int op = get(), l = get(), r = get(), d;
		if(op == 1) {
			d = get();
			if(d & 1) update(1, 1, n, l, r);
		}
		else {
			int res = query(1, 1, n, l, r).f[(1 << m) - 1];
			printf("%d\n", 2 - (res >> (m - 1)));
		}
	}
	return 0;
}


/*
2 1 1
1 1
2 1 2
*/