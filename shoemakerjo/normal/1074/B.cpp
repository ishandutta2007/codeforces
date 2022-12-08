#include <bits/stdc++.h>

using namespace std;

#define maxn 1010

int t, n;
vector<int> adj[maxn];
vector<int> mysub;
bool curin[maxn];
vector<int> osub;
int k1, k2;
int par[maxn];

void dfs(int u, int p) {
	par[u] = p;
	for (int v : adj[u]) {
		if (v != p) dfs(v, u);
	}
}

void go() {
	cin >> n;
	mysub.clear();
	osub.clear();
	for (int i = 1; i <= n; i++) {
		adj[i].clear();
		curin[i] = false;
	}
	int a, b;
	for (int i = 0; i < n-1; i++) {
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	cin >> k1;
	int cur;
	for (int i = 0; i < k1; i++) {
		cin >> cur;
		mysub.push_back(cur);
		curin[cur] = true;
	}
	cin >> k2;
	for (int i = 0; i < k2; i++) {
		cin >> cur;
		osub.push_back(cur);
	}
	dfs(mysub[0], -1);
	cout << "B " << osub[0] << endl;
	cout.flush();
	int ans;
	cin >> ans;
	if (curin[ans]) {
		cout << "C " << ans << endl;
		return;
	}
	int sp = ans;
	while (!curin[sp]) sp = par[sp];

	cout << "A " << sp << endl;
	cout.flush();
	cin >> ans;
	for (int v : osub) {
		if (v == ans) {
			cout << "C " << sp << endl;
			return;
		}
	}
	cout << "C " << -1  << endl;
	


}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> t;
	while (t--) {
		cout.flush();
		go();
		cout.flush();
	}
}