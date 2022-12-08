#include <bits/stdc++.h>

using namespace std;
#define pii pair<int, int>

int n, m, k;

set<pii> banned;

bool checkedge(int u, int v) {
	//is this edge ok

	if (banned.count(pii(u, v))) return false;
	if (banned.count(pii(v, u))) return false;
	return true;
}

set<int> vals; //what is left
vector<vector<int>> ccs;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m >> k;

	int u, v;
	for (int i = 0; i < m; i++) {
		cin >> u >> v;
		banned.insert(pii(u, v));
		banned.insert(pii(v, u));

	}
	for (int i = 2; i <= n; i++) {
		vals.insert(i);
	}

	while (vals.size()) {
		u = *vals.begin();
		vals.erase(vals.begin());

		vector<int> curcc;
		curcc.push_back(u);

		stack<int> proc;
		proc.push(u);

		while (proc.size()) {
			u = proc.top(); proc.pop();

			for (auto it = vals.begin(); it != vals.end(); ){
				v = *it;
				if (checkedge(v, u)) {
					curcc.push_back(v);
					proc.push(v);
					it = vals.erase(it);
				}
				else ++it;
			}
		}
		ccs.push_back(curcc);
	}

	if (ccs.size() > k) {
		cout << "impossible" << endl;
		return 0;
	}

	int ct = 0;

	for (int i = 0; i < ccs.size(); i++) {
		bool ok = false;
		for (int vv : ccs[i]) {
			if (checkedge(vv, 1) == true) {
				ok = true;
				ct++;
			}
		}
		if (!ok) {
			cout << "impossible" << endl;
			return 0;
		}
	}

	if (ct >= k) cout << "possible" << endl;
	else cout << "impossible" << endl;


}