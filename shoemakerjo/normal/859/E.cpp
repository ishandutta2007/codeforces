#include <bits/stdc++.h>
#define ll long long
#define maxn 150000
using namespace std;
vector<vector<int>> adj;
// bool seen[maxn];
// bool visited[maxn];
ll seg[maxn*4];
int nc[maxn];
ll mod = 1000000007;

int leaves;
bool cyc;
set<int> seen;
bool ok[maxn*2+1];
ll ans = 1LL;
void bfs(int u, int par) {
	seen.insert(u);
	// if (adj[u].size() == 1) leaves++;
	leaves++;
	int pc = 0;
	for (int i = 0; i < adj[u].size(); i++) {
		int v = adj[u][i];
		if (v == par) {
			if (pc == 1) cyc = true;
			pc++;
			continue;
		}
		if (seen.find(v) != seen.end()) {
			cyc = true;
		}
		else {
			seen.insert(v);
			bfs(v, u);
		}
	}
}

int main() {
	int N;
	cin >> N;
	ll pows[N+1];
	pows[0] = 1LL;
	
	for (int i = 1; i <= N; i++) {
		pows[i] = (2LL*pows[i-1])%mod;
		nc[i] = 0;
		// ok[i] = true;
	}
	for (int i = 0; i <= 2*N; i++) {
		vector<int> b;
		adj.push_back(b);
		ok[i] = true;
	}
	int x, y;
	queue<int> q;
	for (int i = 0; i < N; i++) {
		cin >> x >> y;
		adj[x].push_back(y);
		nc[x]++;
		nc[y]++;
		adj[y].push_back(x);
		if (x == y) {
			ok[x] = false;
			q.push(x);
		}
	}
	while (!q.empty()) {
		int cur = q.front(); q.pop();
		for (int i = 0; i < adj[cur].size(); i++) {
			int v = adj[cur][i];
			if (ok[v]) {
				ok[v] = false;
				q.push(v);
			}
		}
	}

	for (int i = 0; i <= 2*N; i++) {
		if (adj[i].size() > 0 && ok[i] && seen.find(i) == seen.end()) {
			// cout << i << endl;
			leaves = 0;
			// seen.clear();
			cyc = false;
			bfs(i, -1);
			if (cyc) {
				ans  = (ans*2LL)%mod;
			}
			else {
				ans = (ans*leaves)%mod;
			}
		}
	}
	cout << ans << endl;
	// cin >> ans;
}