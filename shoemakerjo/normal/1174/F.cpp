#include <bits/stdc++.h>

using namespace std;

const int maxn = 200010;
int dep[maxn];
int n;

vector<int> adj[maxn];
vector<int> ch[maxn];

void dfs(int u, int p = -1) {
	dep[u] = p == -1 ? 0 : dep[p]+1;
	for (int v : adj[u]) {
		if (v == p) continue;
		ch[u].push_back(v);
		dfs(v, u);
	}
}

int getdist(int u) {
	cout << "d " << u << endl;
	int res;
	cin >> res;
	return res;
}

int getnext(int u) {
	cout << "s " << u << endl;
	int res;
	cin >> res;
	return res;
}

bool marked[maxn];
int cd; //goal distance
int subsize[maxn];

void go(int u) {
	subsize[u] = 0;
	if (marked[u]) return;
	if (dep[u] == cd) {
		subsize[u] = 1;
		return;
	}
	for (int v : ch[u]) {
		go(v);
		subsize[u] += subsize[v];
	}
}

int main() {
	cin >> n;
	int u, v;
	for (int i = 0; i < n-1; i++) {
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1);
	cd = getdist(1);
	int cp = 1;
	if (cd == 0) {
		cout << "! " << 1 << endl;
		return 0;
	}

	while (true) {
		// cout << " here: " << cp << endl;
		if (dep[cp] == cd) {
			cout << "! " << cp << endl;
			return 0;
		}
		go(cp);
		int nd = subsize[cp];
		int cur = cp;
		while (true) {
			bool fin = false;
			for (int v : ch[cur]) {
				if (subsize[v]*2 >= nd) {
					cur = v;
					fin = true;
					break;
				}
			}
			if (!fin) break;
		}
		if (cur == cp) {
			int nx = getnext(cp);
			cp = nx;
			continue;
		}
		int md = getdist(cur);
		if (md == cd - dep[cur]) {
			cp = cur;
			continue;
		}
		else {
			marked[cur] = true;
			cp = getnext(cp);
		}
	}
}