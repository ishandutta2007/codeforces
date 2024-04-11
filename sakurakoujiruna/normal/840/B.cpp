#include <bits/stdc++.h>
using namespace std;

#define pb push_back
const int N = 3e5L + 11;

vector <pair <int, int>> e[N];

int d[N];
bool v[N];

vector <int> ans;

void dfs(int x) {
	v[x] = 1;
	for(auto i : e[x]) if(!v[i.first]) {
		dfs(i.first);
		if(d[i.first] == 1) {
			d[i.first] = 0;
			ans.pb(i.second);
			if(~d[x])
				d[x] = 1 - d[x];
		}
	}
}

int main() {
	int n, m; cin >> n >> m;
	for(int i = 1; i <= n; i ++)
		scanf("%d", d + i);
	for(int i = 1; i <= m; i ++) {
		int u, v; scanf("%d%d", &u, &v);
		e[u].pb({v, i});
		e[v].pb({u, i});
	}
	for(int i = 1; i <= n; i ++)
		if(!~d[i] && !v[i]) dfs(i);
	bool f = 1;
	for(int i = 1; i <= n; i ++)
		if(!v[i]) {
			dfs(i);
			if(d[i]) f = 0;
		}
	if(!f)
		cout << "-1\n";
	else {
		cout << ans.size() << '\n';
		for(int x : ans)
			printf("%d\n", x);
	}
}