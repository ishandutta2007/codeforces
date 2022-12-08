#include <bits/stdc++.h>

using namespace std;

#define maxn 200010
#define pii pair<int, int>

int n, m, k, x, y;
bool isin[maxn]; //starts at all false
int degin[maxn];
int ans[maxn]; //think we should go backwards
vector<vector<int>> adj(maxn);
int xi[maxn], yi[maxn];

int deg[maxn];
int cans;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		xi[i] = x;
		yi[i] = y;
		adj[x].push_back(y);
		adj[y].push_back(x);
		deg[x]++;
		deg[y]++;
	}
	queue<int> qc;
	for (int i = 1; i <= n; i++) {
		isin[i] = true;
		cans++;
		if (deg[i] < k) {
			qc.push(i);
			isin[i] = false;
			cans--;
		}
	}
	while (qc.size()) {
		int val = qc.front(); qc.pop();
		// cout << "initially removed  " << val << endl;
		for (int vv : adj[val]) {
			deg[vv]--;
			if (isin[vv] && deg[vv] < k) {
				cans--;
				isin[vv] = false;
				qc.push(vv);
			}
		}
	}
	set<pii> remo;
	ans[m-1] = cans;
	for (int i = m-2; i >= 0; i--) {


		x = xi[i+1];
		y = yi[i+1];
		remo.insert(pii(x, y));
		if (isin[x] && isin[y]) {
			//now this matters
			deg[x]--;
			deg[y]--;
			if (deg[x] < k) {
				cans--;
				isin[x] = false;
				qc.push(x);
			}
			if (deg[y] < k) {
				cans--;
				isin[y] = false;
				qc.push(y);
			}
			while (qc.size()) {

				int val = qc.front(); qc.pop();
				for (int vv : adj[val]) {
					if (remo.find(pii(vv, val)) != remo.end() || 
						remo.find(pii(val, vv)) != remo.end()) continue;
					deg[vv]--;
					if (isin[vv] && deg[vv] < k) {
						cans--;
						isin[vv] = false;
						qc.push(vv);
					}
				}
			}
		}

		// cout << "doing " << i << endl;
		// for (int j = 1; j <= n; j++) {
		// 	cout << "    " << j << ":   " << deg[j] << endl;
		// }

		ans[i] = cans;
	}
	for (int i = 0; i < m; i++) {
		cout << ans[i] << '\n';
	}
	cout.flush();


}