#include <bits/stdc++.h>
#define maxn 200000
using namespace std;

int par[maxn];
int dist[maxn];

int findset(int u) {
	int pa = par[u];
	if (pa == u) return u;
	else pa = findset(pa);
	par[u] = pa;
	return pa;
}

void unionset(int u, int v) {
	if (findset(u) != findset(v)) {
		int x = findset(u);
		int y = findset(v);
		if (dist[x] > dist[y]) {
			par[y] = x;
		}
		else {
			par[x] = y;
			if (dist[x] == dist[y]) {
				dist[y]++;
			}
		}
	}
}

int main() {
	int n;
	cin >> n;
	int nums[n];
	map<int, int> index;
	vector<int> sn;
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
		sn.push_back(nums[i]);
	}
	sort(sn.begin(), sn.end());
	for (int i = 0; i < n; i++) {
		int in = lower_bound(sn.begin(), sn.end(), nums[i])-sn.begin();
		index[i] = in;
	}
	for (int i = 0; i < n; i++) {
		par[i] = i;
		dist[i] = 1;
	}
	vector<vector<int>> ans;
	for (int i = 0; i < n; i++) {
		unionset(i, index[i]);
		vector<int> b;
		ans.push_back(b);
	}
	int ct = 0;
	for (int i = 0; i < n; i++) {
		ans[findset(i)].push_back(i+1);
	}
	for (int i = 0; i < n; i++) {
		if (findset(i) == i) ct++;
	}
	cout << ct << endl;
	for (int i = 0; i < n; i++) {
		if (ans[i].size() == 0) continue;
		cout << ans[i].size();
		for (int j = 0; j < ans[i].size(); j++) {
			cout << " ";
			cout << ans[i][j];
		}
		cout << "\n";
	}
	// cin >> ct;
}