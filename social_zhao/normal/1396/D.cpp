#pragma GCC optimize(3,"Ofast","inline")
#pragma GCC target("avx")
#include<bits/stdc++.h>
#define ll long long
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 2e3 + 5, P = 1e9 + 7;
int n, k, L;
int _x[N], _y[N], _c[N], bx[N], by[N], lenx, leny;
int col[N][N], vis[N][N];
vector<pair<int, int>> bin[N];
vector<int> tmp[N];
multiset<int> pos[N];
set<int>::iterator it;

int len[N << 2], tag[N << 2], mn[N << 2];
ll sum[N << 2];

void inc(ll &x, ll y) { x = (x + y) % P; }
void dec(ll &x, ll y) { x = ((x - y) % P + P) % P; }

#define mid ((l + r) >> 1)
#define lc (u << 1)
#define rc (u << 1 | 1)

void pushup(int u) { len[u] = len[lc] + len[rc], sum[u] = (sum[lc] + sum[rc]), mn[u] = min(mn[lc], mn[rc]); }
void pusht(int u, int v) { sum[u] = 1ll * len[u] * v % P, mn[u] = tag[u] = v; }
void pushdown(int u) { if(tag[u]) pusht(lc, tag[u]), pusht(rc, tag[u]), tag[u] = 0; }

void build(int u, int l, int r) {
	tag[u] = sum[u] = mn[u] = 0;
	if(l == r) 
		return len[u] = by[l] - by[l - 1], void();
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

int query(int u, int l, int r, int x) {
	if(l == r) {
		if(mn[u] >= x) return 0;
		else return l;
	}
	pushdown(u);
	if(mn[rc] < x) return query(rc, mid + 1, r, x);
	else return query(lc, l, mid, x);
}

int GetSuf(int c, int x) {
	it = pos[c].lower_bound(x);
	if(it == pos[c].end()) return L + 1;
	else return by[*it];
}

int GetPre(int c, int x) {
	it = pos[c].lower_bound(x);
	if(it == pos[c].begin()) return 1;
	--it;
	return (*it) + 1;
}

void erase(int c, int x) {
	pos[c].erase(pos[c].find(x));
	int suf = GetSuf(c, x);
	int pre = GetPre(c, x);
	int nxt = query(1, 1, leny, suf);
	if(nxt >= pre) update(1, 1, leny, pre, nxt, suf);
}

ll solve(int st) {
	for(int i = 1; i <= k; i++) pos[i].clear();
	for(int i = 1; i <= leny; i++) tmp[i].clear();
	for(int i = st; i <= lenx; i++)
		for(auto v : bin[i]) {
			pos[v.second].insert(v.first), tmp[v.first].emplace_back(v.second);
		}
	build(1, 1, leny);
	int nw = 0;
	for(int i = 1; i <= k; i++) 
		nw = max(nw, GetSuf(i, 1));
	for(int i = 1; i <= leny; i++) {
		update(1, 1, leny, i, i, nw);
		for(auto v : tmp[i]) 
			nw = max(nw, GetSuf(v, i + 1));
	}
	ll res = 0;
	for(int i = lenx; i >= st; i--) {
//		cout << "SegmentTree: "; debug(1, 1, leny); cout << endl;
		inc(res, (1ll * L * (L + 1) - sum[1]) % P * (bx[i + 1] - bx[i]));
		for(auto v : bin[i]) 
			erase(v.second, v.first);
	}
	return res * (bx[st] - bx[st - 1]);
}

main() {
	n = get(), k = get(), L = get();
	for(int i = 1; i <= n; i++) _x[i] = get() + 1, _y[i] = get() + 1, _c[i] = get(), bx[i] = _x[i], by[i] = _y[i];
	sort(bx + 1, bx + 1 + n), sort(by + 1, by + 1 + n), lenx = leny = n + 1, bx[n + 1] = by[n + 1] = L;
	lenx = unique(bx + 1, bx + 1 + lenx) - bx - 1, leny = unique(by + 1, by + 1 + leny) - by - 1;
	bx[lenx + 1] = L + 1;
	for(int i = 1; i <= n; i++)
		_x[i] = lower_bound(bx + 1, bx + 1 + lenx, _x[i]) - bx,
		_y[i] = lower_bound(by + 1, by + 1 + leny, _y[i]) - by,
		col[_x[i]][_y[i]] = _c[i], bin[_x[i]].emplace_back(make_pair(_y[i], _c[i]));
	ll ans = 0;
	for(int i = 1; i <= lenx; i++) 
		inc(ans, solve(i));
	cout << (ans + P) % P << endl;
	return 0;
}