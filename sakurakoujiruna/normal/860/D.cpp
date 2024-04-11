#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using db = double;
#define pb push_back
#define fir first
#define sec second

const int N = 2e5L + 11;
vector <int> e[N], a[N];

set <pair <int, int>> st;

bool v[N];
void dfs1(int x, int p) {
	v[x] = 1;
	for(int i : e[x])
		if(!v[i])
			dfs1(i, x);
		else if(i != p) {
			int s = min(i, x), t = max(i, x);
			if(st.count({s, t})) {
				a[i].pb(x);
				st.erase({s, t});
			}
		}
}

void dfs2(int x, int p) {
	v[x] = 1;
	for(int i : e[x])
		if(!v[i]) {
			dfs2(i, x);
			if(a[i].size() & 1)
				a[i].pb(x);
			else
				a[x].pb(i);
		}
}

int main() {
	ios :: sync_with_stdio(0);
	
	int n, m; cin >> n >> m;
	for(int i = 0; i < m; i ++) {
		int u, v; cin >> u >> v;
		st.insert({min(u, v), max(u, v)});
		e[u].pb(v); e[v].pb(u);
	}
	
	for(int i = 1; i <= n; i ++) if(!v[i]) dfs1(i, 0);
	fill(v, v + n + 1, 0);
	for(int i = 1; i <= n; i ++) if(!v[i]) dfs2(i, 0);
	
	vector <vi> ans;
	for(int i = 1; i <= n; i ++) {
		for(int j = 0; j * 2 + 2 <= a[i].size(); j ++)
			ans.pb({a[i][2 * j], i, a[i][2 * j + 1]});
	}
	
	cout << ans.size() << '\n';
	for(auto i : ans)
		cout << i[0] << ' ' << i[1] << ' ' << i[2] << '\n';
	
	return 0;
}