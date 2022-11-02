#include <bits/stdc++.h>
using namespace std;

const int N = 3e3L + 11;

vector <int> e[N], re[N];
bool vis[N], mem[N];

using ll = long long;

int main() {
	ios :: sync_with_stdio(false);
	int n, m; cin >> n >> m;
	for(int i = 0; i < m; i ++) {
		int u, v; cin >> u >> v;
		e[u].push_back(v);
		re[v].push_back(u);
	}

	ll ans = 0;
	for(int i = 1; i <= n; i ++)
		for(int j = i + 1; j <= n; j ++) {
			int l = 0, r = 0;
			for(int v : e[i]) vis[v] = true;
			for(int v : e[j]) if(vis[v]) {
				l ++;
				mem[v] = true;
			}
			for(int v : e[i]) vis[v] = false;

			for(int v : re[i]) vis[v] = true;
			for(int v : re[j]) if(vis[v]) {
				r ++;
				if(mem[v])
					ans --;
			}
			for(int v : re[i]) vis[v] = false;

			for(int v : e[i]) mem[v] = false;
			
			ans += l * r;
		}
	cout << ans << '\n';
	return 0;
}