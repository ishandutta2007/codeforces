#include <bits/stdc++.h>
using namespace std;

template<typename hd, typename tl> void chkmin(hd& a, tl b) { if(b < a) a = b; }
template<typename hd, typename tl> void chkmax(hd& a, tl b) { if(a < b) a = b; }
#define pb push_back
#define pob pop_back
#define endl '\n'
using LL = long long;
using PI = pair<int, int>;
const int N = 1000005;

vector<int> adj[N];
int rlt[N], uu[N], vv[N];
bool vis[N];
unordered_map<int, int> mp[N];

void dfs(int u, int p) {
	for (auto v : adj[u]) {
		if (vis[v]) continue;
		vis[v] = 1;
		dfs(v, u);
		rlt[mp[u][v]] = 1;
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif

	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int Tc; cin >> Tc;
	while (Tc --) {
		int n, m; cin >> n >> m;
		for (int i = 1; i <= n; i ++) adj[i].clear(), mp[i].clear();
		for (int i = 0; i <= n + 43; i ++) vis[i] = rlt[i] = 0;
		for (int i = 0; i < m; i ++) {
			int u, v; cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
			mp[u][v] = i;
			mp[v][u] = i;
			uu[i] = u;
			vv[i] = v;
		}
		vis[1] = 1;
		dfs(1, 0);
		if (m < n + 2) {
			for (int i = 0; i < m; i ++) cout << rlt[i];
			cout << endl;
			continue;
		}
		set<int> s;
		s.clear();
		for (int i = 0; i < m; i ++) {
			if (rlt[i]) continue;
			s.insert(uu[i]);
			s.insert(vv[i]);
		}
		if (s.size() > 3) {
			for (int i = 0; i < m; i ++) cout << rlt[i];
			cout << endl;
			continue;
		}
		int u = *s.begin();
		bool f = 0;
		for (auto v : adj[u]) {
			if (rlt[mp[u][v]]) rlt[mp[u][v]] = 0;
			else if (!f) {
				f = 1;
				rlt[mp[u][v]] = 1;
			}
		}
		for (int i = 0; i < m; i ++) cout << rlt[i];
		cout << endl;
	}
	return 0;
}