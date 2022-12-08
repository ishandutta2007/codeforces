#include<bits/stdc++.h>
#define mid ((l + r) >> 1)
#define ll long long
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 3e5 + 5, M = N * 40;
int n, q;
int st[N], top, mat[N];
int dfn[N], tim, fa[N], out[N];
int T[N], lc[M], rc[M], tot, sum[M];
char s[N];

ll S(int n) { return 1ll * n * (n + 1) / 2; }

void update(int &u, int l, int r, int x, int v) {
	if(!u) u = ++tot;
	sum[u] += v;
	if(l == r) return;
	if(x <= mid) update(lc[u], l, mid, x, v);
	else if(x > mid) update(rc[u], mid + 1, r, x, v);
}

int query(int u, int l, int r, int a, int b) {
	if(a == l && r == b) return sum[u];
	if(b <= mid) return query(lc[u], l, mid, a, b);
	else if(a > mid) return query(rc[u], mid + 1, r, a, b);
	else return query(lc[u], l, mid, a, mid) + query(rc[u], mid + 1, r, mid + 1, b);
}

namespace BIT {
	ll sum[N];
	int lowbit(int x) { return x & -x; }
	void add(int x, ll v) { while(x <= n) sum[x] += v, x += lowbit(x); }
	ll ask(int x) { ll r(0); while(x) r += sum[x], x -= lowbit(x); return r; }
	ll ask(int l, int r) { return ask(r) - ask(l - 1); }
}

void build(int r) {
	int l = mat[r];
	dfn[l] = dfn[r] = ++tim;
	if(l + 1 == r) return;
	for(int i = r - 1; mat[i]; i = mat[i] - 1) 
		build(i), fa[i] = r, update(T[r], 1, n, dfn[i], 1);
	BIT::add(dfn[r], S(sum[T[r]])), dfn[l] = tim;
}

main() {
	n = get(), q = get();
	scanf("%s", s + 1);
	for(int i = 1; i <= n; i++) {
		if(s[i] == ')') {
			if(top) mat[i] = st[top], --top;
		}
		else if(s[i] == '(') st[++top] = i;
	}
	for(int i = n; i >= 1; i--) if(mat[i] && !dfn[i]) build(i);
	for(int i = n; i >= 1; i--) if(mat[i] && !fa[i]) update(T[0], 1, n, dfn[i], 1);
	assert(tim <= n);
	for(int i = 1; i <= q; i++) {
		int op = get(), l = get(), r = get();
		if(op == 1) {
			BIT::add(dfn[r], -1);
			if(fa[r]) BIT::add(dfn[fa[r]], -S(sum[T[fa[r]]]));
			update(T[fa[r]], 1, n, dfn[r], -1);
			if(fa[r]) BIT::add(dfn[fa[r]], S(sum[T[fa[r]]]));
		}
		else {
			assert(dfn[r] <= dfn[l]);
			ll res = BIT::ask(dfn[r], dfn[l]);
			res += S(query(T[fa[r]], 1, n, dfn[r], dfn[l]));
			printf("%lld\n", res);
		}
	}
	return 0;
}

/*
20 1
((()(())(()))()(()))
2 1 20
*/