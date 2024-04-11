#include <bits/stdc++.h>

using namespace std;

#define maxn 200010
int n;
vector<vector<int>> adj(maxn);
int seq[maxn];
int par[maxn];

queue<set<int>> qs;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	int x, y;
	for (int i = 0; i < n-1; i++) {
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	for (int i = 0; i  < n; i++) {
		cin >> seq[i];
	}
	bool ok = true;
	par[1] = -1;
	set<int> cs;
	cs.insert(1);
	qs.push(cs);
	for (int i = 0; i < n; i++) {
		int val = seq[i];
		if (qs.size() == 0) {
			ok = false;
			break;
		}
		if (qs.front().find(val) == qs.front().end()) {
			ok = false;
			break;
		}
		else {
			qs.front().erase(qs.front().find(val));
			set<int> nx;
			for (int vv : adj[val]) {
				if (vv != par[val]) {
					nx.insert(vv);
					par[vv] = val;
				}
			}
			if (nx.size() != 0) qs.push(nx);
			if (qs.front().size() == 0) qs.pop();
		}
	}
	if (ok) cout << "Yes" << endl;
	else cout << "No" << endl;

}