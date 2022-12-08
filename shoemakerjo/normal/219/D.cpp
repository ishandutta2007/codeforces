#include <bits/stdc++.h>
#define maxn 200001
using namespace std;
#define pii pair<int, int>

vector<vector<pii>> adj;
int up[maxn];
int down[maxn];
int pup[maxn];
int pdown[maxn];
int tdown;
int tup;

void dfs(int u, int p) {
	pup[u] += pup[p];
	pdown[u] += pdown[p];
	for (int i = 0; i < adj[u].size(); i++) {
		pii v = adj[u][i];
		if (v.first == p) continue;
		if (v.second == 1) {
			tdown++;
			down[u]++;
			pdown[v.first]++;
		}
		else {
			tup++;
			up[u]++;
			pup[v.first]++;
		}
		dfs(v.first, u);
		up[u] += up[v.first];
		down[u] += down[v.first];
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i <= n; i++) {
		vector<pii> b;
		adj.push_back(b);
		up[i] = down[i] = pup[i] = pdown[i] = 0;
	}
	int s, t;
	for (int i = 0; i < n-1; i++) {
		cin >> s >> t;
		adj[s].push_back(pii(t, 1));
		adj[t].push_back(pii(s, 0));
	}
	tdown = tup = 0;
	dfs(1, 0);
	int best = n;
	vector<int> ans;
	// cout << "tdown  " << tdown << " " << tup << endl;
	for (int i = 1; i <= n; i++) {
		// cout << "i:  " << down[i] << " " << up[i] << " " << 
		// 	pup[i] << " " << pdown[i] << endl;
		int cur = tup-pup[i] + pdown[i];
		// cur = (n-1)-cur;
		if (cur < best) {
			best = cur;
			ans.clear();
			ans.push_back(i);
		}
		else if (cur ==  best) {
			ans.push_back(i);
		}
	}
	cout << best << endl;
	for (int i = 0; i < ans.size(); i++) {
		if (i > 0) cout << " ";
		cout << ans[i];
	}
	cout << endl;
	// cin >> n;
}