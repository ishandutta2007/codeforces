#include <bits/stdc++.h>
using namespace std;

using pii = pair <int, int>;
#define pb push_back
#define fi first
#define se second

const int N = 2e5L + 11;
const int inf = 2e9L;

vector <pii> e[N];
int f[N][51];

set <pair <int, pii>> st;

void upd(int x, int y, int w) {
	if(f[x][y] > w) {
		st.erase({w, {x, y}});
		f[x][y] = w;
		st.insert({w, {x, y}});
	}
}

int sqr(int x) {
	return x * x;
}

void dijkstra(int n) {
	st.insert({0, {1, 0}});
	for(int i = 2; i <= n; i ++) {
		st.insert({inf, {i, 0}});
		f[i][0] = inf;
	}
	for(int i = 1; i <= n; i ++)
		for(pii j : e[i]) {
			st.insert({inf, {i, j.se}});
			f[i][j.se] = inf;
		}
	
	while(!st.empty()) {
		auto p = *st.begin();
		st.erase(st.begin());
		
		//~ cout << p.fi << ' ' << p.se.fi << ' ' << p.se.se << '\n';
		
		if(p.se.se == 0) {
			for(auto i : e[p.se.fi])
				upd(i.fi, i.se, p.fi);
		} else {
			for(auto i : e[p.se.fi])
				upd(i.fi, 0, p.fi + sqr(p.se.se + i.se));
		}
	}
}

int main() {
	ios :: sync_with_stdio(0);
	int n, m; cin >> n >> m;
	for(int i = 0; i < m; i ++) {
		int u, v, w;
		cin >> u >> v >> w;
		e[u].pb({v, w});
		e[v].pb({u, w});
	}
	f[1][0] = 0;

	dijkstra(n);
	
	for(int i = 1; i <= n; i ++)
		cout << (f[i][0] == inf ? -1 : f[i][0]) << ' ';
	cout << '\n';
}