#include <bits/stdc++.h>

using namespace std;
#define ll long long

set<int> lef;
set<ll> out;

int n, m;
int sz;
// vector<int> pc;

void bfs(int u) {
	// cout << "u   " << u << endl;
	// pc.clear();
	// pc.push_back(u);
	sz = 1;
	lef.erase(lef.find(u));
	queue<int> nodes;
	nodes.push(u);
	// cout << "here   " << endl;
	while (!nodes.empty()) {
		int cur = nodes.front(); nodes.pop();
		for (set<int>::iterator it = lef.begin(); it != lef.end(); ) {
			int v = *it;
			if (out.find(min(cur+0LL, v+0LL)*(n+1LL) + max(cur+0LL, v+0LL)) != out.end()) {
				++it;
				continue;
			}
			it = lef.erase(it);
			nodes.push(v);
			sz++;
			// pc.push_back(v);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	// int n, m;
	cin >> n >> m;
	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		out.insert(min(a+0LL, b+0LL)*(n+1LL) + max(a+0LL, b+0LL));
	}
	for (int i = 1; i <= n; i++) {
		lef.insert(i);
	}
	vector<int> ans;
	for (int i = 1; i <= n; i++) {
		if (lef.find(i) != lef.end()) {
			bfs(i);
			ans.push_back(sz);
		}
	}
	sort(ans.begin(), ans.end());
	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}
	cout << endl;
	cin >> n;
}