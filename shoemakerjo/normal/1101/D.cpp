#include <bits/stdc++.h>

using namespace std;
#define prev ppprev

const int maxn = 200010;
int n;

int nums[maxn];

vector<int> adj[maxn];

int fact[maxn];

int par[maxn];

vector<int> vals[maxn];

void dfs(int u, int p = 0) {
	par[u] = p;
	for (int v : adj[u]) {
		if (v != p) {
			dfs(v, u);
		}
	}
}

vector<int> cadj[maxn];
bool curin[maxn];
bool seen[maxn];
int cdist[maxn];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> nums[i];
	}
	int x, y;
	for (int i = 0; i < n-1; i++) {
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	for (int i = 2; i < maxn; i++) {
		if (fact[i] == 0) {
			fact[i] = i;
			for (int j = i; j < maxn; j += i) {
				if (fact[j] == 0) fact[j] = i;
			}
		}
	}
	dfs(1);

	for (int i = 1; i <= n; i++) {
		int prev = 0;
		int cur = nums[i];
		while (cur > 1) {
			if (fact[cur] != prev) {
				vals[fact[cur]].push_back(i);
			}
			prev = fact[cur];
			cur /= fact[cur];
		}

	}

	int res = 0;
	// vector<int> cv;
	for (int i = 1; i < maxn; i++) {
		if (vals[i].size() == 0) continue;

		for (int v : vals[i]) {
			curin[v] = true;
			cdist[v] = n*2;
		}
		for (int v : vals[i]) {
			if (curin[par[v]]) {
				cadj[v].push_back(par[v]);
				cadj[par[v]].push_back(v);
			}
		}

		for (int v : vals[i]) {
			if (seen[v]) continue;

			queue<int> q;
			cdist[v] = 0;


			vector<int> tmp;
			q.push(v);

			int farnode = v;
			while (q.size()) {
				int cur = q.front(); q.pop();
				seen[cur] = true;

				tmp.push_back(cur);
				for (int u : cadj[cur]) {
					if (cdist[u] > cdist[cur] + 1) {
						cdist[u] = cdist[cur] + 1;
						q.push(u);
						if (cdist[u] > cdist[farnode]) {
							farnode = u;
						}
						// tmp.push_back
					}
				}
			}
			for (int v : tmp) {
				cdist[v] = n*2;
			}
			int og = farnode;
			cdist[farnode] = 0;
			q.push(farnode);
			while (q.size()) {
				int cur = q.front(); q.pop();

				tmp.push_back(cur);
				for (int u : cadj[cur]) {
					if (cdist[u] > cdist[cur] + 1) {
						cdist[u] = cdist[cur] + 1;
						q.push(u);
						if (cdist[u] > cdist[farnode]) {
							farnode = u;
						}
						// tmp.push_back
					}
				}
			}

			res = max(res, cdist[farnode]+1);


		}



		for (int v : vals[i]) {
			seen[v] = false;
			curin[v] = false;
			cadj[v].clear();
		}

	}
	cout << res << endl;

}