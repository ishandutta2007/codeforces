#include <bits/stdc++.h>

using namespace std;
#define int long long
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}
const int MAXN = 1e5 + 10;
int n, m;
vector<int> g[MAXN];

void read() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
}

int ans = 0;
int par[MAXN], sz[MAXN];
void make() {
	for (int i = 0; i < n; i++) {
		par[i] = i;
		sz[i] = 1;
	}
}

int get_par(int v) {
	if (v == par[v]) return v;
	return par[v] = get_par(par[v]);
}

void uni(int u, int v) {
	u = get_par(u);
	v = get_par(v);
	if (sz[u] < sz[v]) swap(u, v);
	sz[u] += sz[v];
	par[v] = u;
} 

int cnt[MAXN];

void run() {
	make();
	set<pair<int, int> > q;
	for (auto i : g[0]) {
		cnt[i]++;
	}
	for (int i = 1; i < n; i++) {
		q.insert({cnt[i], i});
	}
	/*cout << "cnt = " << endl;
	for (int i = 0; i < n; i++)
		cout << cnt[i] << " ";
	cout << endl;*/
	for (int i = 1; i < n; i++) {
		auto v = q.begin()->second;
		q.erase(q.begin());
		//cout << "v = " << v << " cnt = " << cnt[v] << endl;
		if (cnt[v] == i) ans++;
		uni(0, v);
		for (auto j : g[v]) {
			if (get_par(j) == get_par(0)) continue;
			q.erase({cnt[j], j});
			cnt[j]++;
			q.insert({cnt[j], j});
		}
	}
}

void write() {
	cout << ans << endl;
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	read();
	run();
	write();
	return 0;
}