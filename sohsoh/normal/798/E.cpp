#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define all(x)			(x).begin(),(x).end()
#define X			first
#define Y			second
#define sep			' '
#define endl			'\n'
#define debug(x)		cerr << #x << ": " <<  x << endl;

const ll MAXN = 5e5 + 10;
const ll LOG = 22;

int n, sg[MAXN << 2], m, f[MAXN], t, ord[MAXN << 2], ans[MAXN];
vector<int> adj[MAXN * LOG];
bitset<MAXN * LOG> vis;

void build(int l = 1, int r = n, int v = 1) {
	sg[v] = ++m;
	if (l == r) f[l] = m;
	else {
		int mid = (l + r - 1) >> 1;
		build(l, mid, v << 1);
		build(mid + 1, r, v << 1 | 1);

		adj[sg[v]].push_back(sg[v << 1]);
		adj[sg[v]].push_back(sg[v << 1 | 1]);
		adj[sg[v]].shrink_to_fit();
	}
}

void update(int ind, int l = 1, int r = n, int v = 1) {
	sg[v] = ++m;
	if (l < r) {
		int mid = (l + r - 1) >> 1;
		if (ind <= mid) update(ind, l, mid, v << 1);
		else update(ind, mid + 1, r, v << 1 | 1);

		adj[sg[v]].push_back(sg[v << 1]);
		adj[sg[v]].push_back(sg[v << 1 | 1]);
		adj[sg[v]].shrink_to_fit();
	}
}

void connect(int u, int ql, int qr, int l = 1, int r = n, int v = 1) {
	if (ql > r || qr < l || ql > qr) return;
	if (ql <= l && qr >= r) {
		adj[u].push_back(sg[v]);
		return;
	}

	int mid = (l + r - 1) >> 1;
	connect(u, ql, qr, l, mid, v << 1);
	connect(u, ql, qr, mid + 1, r, v << 1 | 1);
}

void dfs(int v) {
	vis[v] = 1;
	for (int u : adj[v])
		if (!vis[u])
			dfs(u);
	
	++t;
	if (v < (MAXN << 2))
		ord[v] = t;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	build();

	vector<int> vec;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		if (x < 0) {
			connect(f[i], 1, i - 1);
			connect(f[i], i + 1, n);
		} else {
			if (i > x) connect(f[i], 1, x - 1);
			else {
				connect(f[i], 1, i - 1);
				connect(f[i], i + 1, x - 1);
			}
			
			adj[f[x]].push_back(f[i]);
			update(x);
		}

		vec.push_back(i);
	}
	
	for (int i = 1; i <= m; i++)
		if (!vis[i])
			dfs(i);

	sort(all(vec), [] (int i, int j) {
		return ord[f[i]] < ord[f[j]];
	});

	for (int i = 0; i < n; i++)
		ans[vec[i]] = i + 1;
	for (int i = 1; i <= n; i++)
		cout << ans[i] << sep;
	cout << endl;
	return 0;
}