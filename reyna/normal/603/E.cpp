//In the name of God



#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, e) for(int i = (s); i < (e); i++)
#define x first
#define y second

typedef long long ll;
typedef pair<int, int> pii;

template<class P, class Q> inline P smin (P &a, Q b) { if (b < a) a = b; return a; }
template<class P, class Q> inline P smax (P &a, Q b) { if (a < b) a = b; return a; }


int pw(int a, int b, int mod) { return (b? pw(1LL * a * a % mod, b >> 1, mod) * 1LL * (b & 1? a : 1) % mod: 1); }


const int maxN = 2e6 + 49;
const int mod = 0;
const int base = 1000 * 1000 + 3;
const int oo = 1e9 + 49;

int cv, n, m, seen;

int ans[maxN], vs[maxN], vt[maxN], vw[maxN], sz[maxN], par[maxN], dsucnt;
pii ed[maxN];
vector<int> seg[maxN];
vector<pii> his;

int find(int v) {
	return (v == par[v]? v: find(par[v]));	
}

void unite(int u, int v) {
	u = find(u), v = find(v);
	if (u == v) {
		his.push_back({-1, -1});
		return;	
	}
	if (sz[u] > sz[v])
		swap(u, v);
	dsucnt -= (sz[v] & 1);
	dsucnt -= (sz[u] & 1);
	par[u] = v;
	sz[v] += sz[u];
	dsucnt += (sz[v] & 1);
	his.push_back({u, v});	
}

void undo() {
	assert((int) his.size());
	pii cur = his.back(); his.pop_back();
	if (cur.x == -1)
		return;
	int u = cur.x, v = cur.y;
	dsucnt -= (sz[v] & 1);
	par[u] = u;
	sz[v] -= sz[u];
	dsucnt += (sz[u] & 1);
	dsucnt += (sz[v] & 1);
}

int read() { int x; cin >> x; return x; }

void push(int i, int j, int x, int v = 1, int b = 0, int e = m) {
	if (i >= e || b >= j) return;
	int mid = (b + e) >> 1, l = v << 1, r = l | 1;
	if (i <= b && e <= j) {
		if (b + 1 != e && b <= cv && cv <= e) {
			push(i, j, x, l, b, mid);
			push(i, j, x, r, mid, e);
		} else {
			seg[v].push_back(x);
		}
		return;
	}
	push(i, j, x, l, b, mid);
	push(i, j, x, r, mid, e);
}

void dfs(int v = 1, int b = 0, int e = m) { cv = b;
	int p = 0;
	while (p < (int) seg[v].size()) {
		int i = seg[v][p];
		unite(vs[i], vt[i]);
		p++;
	}
	if (b + 1 == e) {
		while (dsucnt) {
			if (seen == m)
				break;
			if (m - ed[seen].y > b) {
				push(b, m - ed[seen].y, ed[seen].y);
			}
			while (p < (int) seg[v].size()) {
				int i = seg[v][p];
				unite(vs[i], vt[i]);
				p++;
			}
			seen++;
		}
		if (!dsucnt)
			ans[b] = ed[seen - 1].x;
		else
			ans[b] = -1;
	}
	int mid = (b + e) >> 1, l = v << 1, r = l | 1;
	if (b + 1 != e) {
		dfs(l, b, mid);
		dfs(r, mid, e);
	}
	for (int i = 0; i < (int) seg[v].size(); i++)
		undo();
}

int32_t main() {
	ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
	n = read(), m = read(); dsucnt = n;
	for (int i = 0; i < n; i++)
		par[i] = i, sz[i] = 1;
	for (int i = 0; i < m; i++) {
		vs[i] = read() - 1, vt[i] = read() - 1, vw[i] = read();
		ed[i] = {vw[i], i};
	}
	sort(ed, ed + m);
	dfs(1);
	for (int i = m - 1; ~i; --i)
		cout << ans[i] << '\n';
}