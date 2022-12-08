#include <bits/stdc++.h>

using namespace std;
#define maxn 100010
#define ll long long
int n;
int c[maxn];
int subsize[maxn];
ll ans[maxn];
int bf[maxn]; //biggest frequency at this node
vector<vector<int>> adj(maxn);

void getsubsize(int u, int p) {
	subsize[u] = 1;
	for (auto v : adj[u]) {
		if (v != p) {
			getsubsize(v, u);
			subsize[u] += subsize[v];
		}
	}
}

void dfs(int u, int p, map<int,int>& cm) {
	int mx = -1, bigChild = -1;
	for (auto v: adj[u]) {
		if (v != p && subsize[v] >= mx) {
			mx = subsize[v];
			bigChild = v;
		}
	}
	int bigfreq = 0;
	ll sum = 0LL;
	if (mx != -1) {
		dfs(bigChild, u, cm); //do the bigChild recursion
		bigfreq = bf[bigChild];
		sum = ans[bigChild];
	}
	for (auto v: adj[u]) {
		if (v != p && v != bigChild) {
			map<int, int> nm;
			dfs(v, u, nm);
			for (map<int, int>::iterator it = nm.begin(); it != nm.end(); ++it) {
				int val = it->first;
				int fcur = it->second;
				if (cm.count(val) == 0) cm[val] = fcur;
				else cm[val] += fcur;
				if (cm[val] > bigfreq) {
					bigfreq = cm[val];
					sum = val;
				}
				else if (cm[val] == bigfreq) {
					sum += 0LL+val;
				}
			}

		}
	}
	//below adds my own boy to the mix
	if (cm.count(c[u]) == 0) {
		cm[c[u]] = 1;
	}
	else cm[c[u]]++;
	if (cm[c[u]] > bigfreq) {
		bigfreq = cm[c[u]];
		sum = c[u];
	}
	else if (cm[c[u]] == bigfreq) {
		sum += 0LL + c[u];
	}

	bf[u] = bigfreq; //update the answers at the end
	ans[u] = sum;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
	}
	int u, v;
	for (int i = 0; i < n-1; i++) {
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	getsubsize(1, -1);
	map<int, int> nm;
	dfs(1, -1, nm);
	for (int i = 1; i <= n; i++) {
		cout << ans[i] << " ";
	}
	cout << endl;
	cin >> n;
}