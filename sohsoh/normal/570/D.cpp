#include <bits/stdc++.h>
using namespace std;
#define all(x)(x).begin(),(x).end()
const int N = 5e5 + 10,A = 26;

int par[N], n, q, tin[N], tout[N], H[N], T;
vector<int> adj[N];
vector<int> V[N][A];
string s;

void dfs(int v) {
	tin[v] = ++T;
	for (int u : adj[v])
		dfs(u);
	tout[v] = T;
}
 
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> q;
	H[1] = 1;
	for (int i = 2; i <= n; i++) {
		cin >> par[i];
		adj[par[i]].push_back(i);
		H[i] = H[par[i]] + 1;
	}

	cin >> s;
	s = '.' + s;

	dfs(1);
	for (int v = 1; v <= n; v++)
		V[H[v]][s[v] - 'a'].push_back(tin[v]);

	for (int i = 0; i < N; i++)
	       for (int j = 0; j < 26; j++)
	       	       sort(all(V[i][j]));
	while (q--) {
		int v, h, cnt = 0;
		cin >> v >> h;
		if (h <= H[v]) cout << "Yes" << '\n';
		else {
			for (int i = 0; i < 26; i++) {
				int k = lower_bound(all(V[h][i]), tout[v] + 1) - lower_bound(all(V[h][i]), tin[v]);
				cnt += (k & 1);
			}
		
			cout << (cnt < 2 ? "Yes" : "No") << '\n';
		}
	}
	return 0;
}