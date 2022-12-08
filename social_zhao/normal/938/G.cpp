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

const int N = 4e5 + 5;
int n, m, q, _x[N], _y[N], _w[N], tot;
map<pair<int, int>, pair<int, int>> nw;
struct Query { 
	int id, x, y, w;
	Query(int a = 0, int b = 0, int c = 0, int d = 0) { id = a, x = b, y = c, w = d; }
};
vector<Query> t[N << 2];
stack<Query> st;

namespace LinearBasis {
	const int S = 31;
	int a[S + 1];
	
	int insert(int x) {
		for(int i = S; i >= 0; i--) {
			if(x >> i & 1) {
				if(!a[i]) return a[i] = x, i;
				else x ^= a[i];
			}
		}
		return -1;
	}
	
	int query(int x) {
		for(int i = S; i >= 0; i--) x = min(x, x ^ a[i]);
		return x;
	}
}

int fa[N], sze[N], val[N];
int find(int x) { return x == fa[x]? x : find(fa[x]); }
int GetVal(int x) { return x == fa[x]? val[x] : (val[x] ^ GetVal(fa[x])); }
pair<int, int> mp(int x, int y) { return make_pair(min(x, y), max(x, y)); }

void insert(int u, int l, int r, int a, int b, Query v) {
	if(a == l && r == b) return t[u].push_back(v), void();
	if(b <= mid) insert(lc, l, mid, a, b, v);
	else if(a > mid) insert(rc, mid + 1, r, a, b, v);
	else insert(lc, l, mid, a, mid, v), insert(rc, mid + 1, r, mid + 1, b, v);
}

void merge(int u, int v, int w) {
	int x = find(u), y = find(v);
	if(x == y) 
		return st.push(Query(1, LinearBasis::insert(w ^ GetVal(u) ^ GetVal(v)), 0, 0)), void();
	if(sze[x] < sze[y]) swap(x, y), swap(u, v);
	st.push(Query(2, y, GetVal(u) ^ w ^ GetVal(v), 0)), val[y] ^= GetVal(u) ^ w ^ GetVal(v), fa[y] = x, sze[x] += sze[y];
}

void undo() {
	Query u = st.top(); st.pop();
	if(u.id == 1) { if(u.x >= 0) LinearBasis::a[u.x] = 0; }
	else {
		int x = u.x, w = u.y;
		sze[find(fa[x])] -= sze[x], val[x] ^= w, fa[x] = x;
	}
}

int calc(int x, int y) {
	int w = GetVal(x) ^ GetVal(y);
	return LinearBasis::query(w);
}

void solve(int u, int l, int r) {
	sort(t[u].begin(), t[u].end(), [](Query a, Query b) { return a.id < b.id; });
	int tmp = st.size();
	for(auto v : t[u]) {
		if(v.id == 1) merge(v.x, v.y, v.w);
		else printf("%d\n", calc(v.x, v.y));
	}
	if(l != r) solve(lc, l, mid), solve(rc, mid + 1, r);
	while(st.size() != tmp) undo();
} 

int main() {
	n = get(), m = get();
	for(int i = 1; i <= m; i++) 
		_x[i] = get(), _y[i] = get(), _w[i] = get(), nw[mp(_x[i], _y[i])] = make_pair(_w[i], 1);
	tot = m;
	for(int i = 1; i <= n; i++) fa[i] = i, sze[i] = 1;
	q = get();
	for(int i = 1; i <= q; i++) {
		int opt = get(), x = get(), y = get(), w;
		if(opt == 1) 
			w = get(), nw[mp(x, y)] = make_pair(w, i), _x[++tot] = x, _y[tot] = y, _w[tot] = w;
		else if(opt == 2) 
			insert(1, 1, q, nw[mp(x, y)].second, i, Query(1, x, y, nw[mp(x, y)].first)), 
			nw[mp(x, y)] = make_pair(0, 0);
		else if(opt == 3) 
			insert(1, 1, q, i, i, Query(2, x, y, 0));
	}
	for(int i = 1; i <= tot; i++) if(nw[mp(_x[i], _y[i])].second) 
		insert(1, 1, q, nw[mp(_x[i], _y[i])].second, q, Query(1, _x[i], _y[i], nw[mp(_x[i], _y[i])].first)), 
		nw[mp(_x[i], _y[i])] = make_pair(0, 0);
	solve(1, 1, q);
	return 0;
}

/*
5 6
1 2 1
2 3 4
2 4 0
3 5 9
4 5 9
1 5 2
2
2 5 3
3 2 3
*/