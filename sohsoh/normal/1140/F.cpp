#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pll;

#define all(x)			(x).begin(),(x).end()
#define X			first
#define Y			second
#define sep			' '
#define endl			'\n'
#define debug(x)		cerr << #x << ": " <<  x << endl;

const ll MAXN = 2e6 + 10;
const ll MAXC = 4e5;

int par[MAXN], sz[MAXN], cnt_x[MAXN], cnt_y[MAXN], q;
map<pll, int> mp;
vector<pll> Q[MAXN];
ll ans = 0;
stack<int> hist;

int find(int v) {
	return par[v] == v ? v : find(par[v]);
}

inline bool unite(int u, int v) {
	u = find(u), v = find(v);
	if (u == v) return false;

	if (sz[u] < sz[v]) swap(v, u);
	ans -= 1ll * cnt_x[v] * cnt_y[v];
	ans -= 1ll * cnt_x[u] * cnt_y[u];

	sz[u] += sz[v];
	cnt_x[u] += cnt_x[v];
	cnt_y[u] += cnt_y[v];
	par[v] = u;	
	ans += 1ll * cnt_x[u] * cnt_y[u];

	hist.push(v);
	return true;
}

inline void undo() {
	if (hist.empty()) return;
	int v = hist.top();
	hist.pop();
	int u = par[v];

	ans -= 1ll * cnt_x[u] * cnt_y[u];
	par[v] = v;
	cnt_x[u] -= cnt_x[v];
	cnt_y[u] -= cnt_y[v];
	sz[u] -= sz[v];

	ans += 1ll * cnt_x[v] * cnt_y[v];
	ans += 1ll * cnt_x[u] * cnt_y[u];
}

void add(int ql, int qr, pll e, int l = 1, int r = q, int v = 1) {
	if (ql > r || qr < l || ql > qr) return;
	if (ql <= l && qr >= r) {
		Q[v].push_back(e);
		return;
	}

	int mid = (l + r) >> 1;
	add(ql, qr, e, l, mid, v << 1);
	add(ql, qr, e, mid + 1, r, v << 1 | 1);
}

void solve(int l = 1, int r = q, int v = 1) {
	int cnt = 0;
	for (pll e : Q[v])
		cnt += unite(e.X, e.Y + MAXC);

	if (l == r) cout << ans << endl;
	else {
		int mid = (l + r) >> 1;
		solve(l, mid, v << 1);
		solve(mid + 1, r, v << 1 | 1);
	}

	while (cnt--) undo();
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	for (int i = 0; i < MAXN; i++) {
		par[i] = i;
		if (i < MAXC) cnt_x[i] = 1;
		else cnt_y[i] = 1;
		sz[i] = 1;
	}

	cin >> q;
	for (int i = 1; i <= q; i++) {
		int x, y;
		cin >> x >> y;
		int lst = mp[make_pair(x, y)];

		if (lst) {
			add(lst, i - 1, {x, y});
			mp[make_pair(x, y)] = 0;	
		} else mp[make_pair(x, y)] = i;
	}

	for (auto e : mp)
		if (e.Y)
			add(e.Y, q, e.X);

	solve();
	return 0;
}