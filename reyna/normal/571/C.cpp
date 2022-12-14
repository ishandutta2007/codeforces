//In the name of God
#include <bits/stdc++.h>
using namespace std;
const int N = 4e5 + 9;
vector<int> cl[N];
vector<pair<int,int> > e[N];
vector<pair<int,int> > ng[N],ps[N];
int deg[N];
int vis[N],mark[N];
set<pair<int,int> > st;
int ans[N];
int main() {
	ios_base::sync_with_stdio(0);
	memset(ans,-1,sizeof ans);
	int n,m; cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		int k; cin >> k;
		for (int j = 0; j < k; ++j) {
			int p; cin >> p;
			if (p < 0) cl[-p].push_back(-(i + 1));
			else cl[p].push_back(i + 1);
		}
	}
	for (int i = 1; i <= m; ++i) {
		int f = -1;
		for (auto x : cl[i]) {
			if (x < 0 && f == 1 || x > 0 && f == 0) {
				f = 2;
				if (x < 0) {
					ng[-x].push_back({cl[i][0],i});
					ps[cl[i][0]].push_back({-x,i});
					e[i].push_back({-x,cl[i][0]});
					deg[-x]++;
					deg[cl[i][0]]++;
				} else {
					ps[x].push_back({-cl[i][0],i});
					e[i].push_back({-cl[i][0],x});
					ng[-cl[i][0]].push_back({x,i});
					deg[x]++;
					deg[-cl[i][0]]++;
				}
			} else if (x < 0) f = 0;
			else if (x > 0) f = 1;
		}
		if (f != 2)
			for (auto x : cl[i]) {
				if (x < 0) ng[-x].push_back({x,i}),e[i].push_back({-x,-x}),deg[-x]+=10;
				else ps[x].push_back({x,i}),e[i].push_back({x,x}),deg[x]+=10;
			}
	}
	for (int i = 1; i <= n; ++i) {
		st.insert({deg[i],i});
	}
	while (st.size()) {
		pair<int,int> cur = *(st.begin()); st.erase(cur);
		int v = cur.second; vis[v] = 1;
		int id = -1e9,dg = 0;
		for (auto u : ng[v]) {
			if (mark[u.second]) continue;
			if (deg[u.first] >= dg)
				dg = deg[u.first],id = -u.second;
		}
		for (auto u : ps[v]) {
			if (mark[u.second]) continue;
			if (deg[u.first] >= dg) 
				dg = deg[u.first],id = u.second;
		}
		if (id == -1e9) {
			cout << "NO\n";
			return 0;
		}
		mark[abs(id)] = 1;
		if (id < 0) ans[(-id) - 1] = 0;
		else ans[id - 1] = 1;
		for (auto x : cl[abs(id)]) {
			if ((long long)x * id > 0) {
				vis[abs(x)] = 1;
			}
		}
		for (auto ed : e[abs(id)]) {
			int x = ed.first,y = ed.second;
			st.erase({deg[x],x});
			st.erase({deg[y],y});
			deg[x]--; deg[y]--;
			if (!vis[x]) st.insert({deg[x],x});
			if (!vis[y]) st.insert({deg[y],y});
		}
	}
	cout << "YES\n";
	for (int i = 0; i < m; ++i) cout << (ans[i] == -1 ? 0 : ans[i]);
	return 0;
}