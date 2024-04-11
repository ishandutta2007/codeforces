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

const ll MAXN = 5e5 + 10;
const ll INF = 1e9;

int n;

struct segment {
	pll sg[MAXN << 2];
	int lz[MAXN << 2];
	
	inline pll merge(pll a, pll b) {
		if (a.X == b.X) return {a.X, a.Y + b.Y};
		return max(a, b);
	}

	inline void push(int v) {
		sg[v].X += lz[v];
		if ((v << 1 | 1) < (MAXN << 2))
			lz[v << 1] += lz[v], lz[v << 1 | 1] += lz[v];
		lz[v] = 0;
	}

	void build(int l = 1, int r = n, int v = 1) {
		if (l == r) sg[v] = {0, 1};
		else {
			int mid = (l + r) >> 1;
			build(l, mid, v << 1);
			build(mid + 1, r, v << 1 | 1);
			sg[v] = merge(sg[v << 1], sg[v << 1 | 1]);
		}
	}

	segment() {}

	void update(int ql, int qr, int val, int l = 1, int r = n, int v = 1) {
		push(v);
		if (ql > r || qr < l) return;
		if (ql <= l && qr >= r) {
			lz[v] += val;
			push(v);
			return;
		}

		int mid = (l + r) >> 1;
		update(ql, qr, val, l, mid, v << 1);
		update(ql, qr, val, mid + 1, r, v << 1 | 1);
		sg[v] = merge(sg[v << 1], sg[v << 1 | 1]);
	}

	pll query(int ql, int qr, int l = 1, int r = n, int v = 1) {
		push(v);
		if (ql > r || qr < l) return {-INF, -INF};
		if (ql <= l && qr >= r) return sg[v];

		int mid = (l + r) >> 1;
		return merge(query(ql, qr, l, mid, v << 1),
				query(ql, qr, mid + 1, r, v << 1 | 1));
	}
} sg1, sg2;
// odd - even, valid roots

int cnt, tin[MAXN], tout[MAXN], t, sz[MAXN], odd_cnt[MAXN];
vector<int> adj[MAXN];
bool match;
ll ans;

int pre_dfs(int v, int p) {
	sz[v] = 1;
	tin[v] = ++t;
	for (int u : adj[v]) {
		if (u != p) {
			sz[v] += pre_dfs(u, v);
			odd_cnt[v] += odd_cnt[u];
		}
	}

	tout[v] = t;
	sg1.update(tin[v], tout[v], (sz[v] & 1) ? 1 : -1);
	cnt += (sz[v] & 1);
	odd_cnt[v] += (sz[v] & 1);
	return sz[v];
}

void dfs(int v, int p) {	
	sg1.update(tin[v], tout[v], (sz[v] & 1) ? -2 : 2);	
	cnt += ((sz[v] & 1) ? -1 : 1);

	for (int u : adj[v]) {
		if (u == p) continue;	
		dfs(u, v);
		
		if (!(sz[u] & 1)) ans += 1ll * sz[u] * (n - sz[u]) * int(match);
		else {
			pll e1 = sg1.merge(sg1.query(1, tin[u] - 1),
					sg1.query(tout[u] + 1, n));
			pll e2 = sg2.query(tin[u], tout[u]);
			
			if (cnt - e1.X - e2.X == n / 2) ans += 1ll * e1.Y * e2.Y;
		}

	}

	if (!(sz[v] & 1)) {
		sg2.update(tin[v], tin[v], -INF);
		if (tin[v] < tout[v]) sg2.update(tin[v] + 1, tout[v], -1);
	} else if (tin[v] < tout[v]) sg2.update(tin[v] + 1, tout[v], 1);

	sg1.update(tin[v], tout[v], (sz[v] & 1) ? 2 : -2);	
	cnt += ((sz[v] & 1) ? 1 : -1);	
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	if (n & 1) return cout << 0 << endl, 0;

	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	sg1.build();
	sg2.build();
	pre_dfs(1, 0);
	match = (cnt == n / 2);
	dfs(1, 0);

	cout << ans << endl;
	return 0;
}