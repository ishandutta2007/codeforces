#include <bits/stdc++.h>

using namespace std;

const int maxn = 300010;

int n, m;

int p[maxn];

set<int> aft[maxn];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> p[i];
	}

	int u, v;
	for (int i = 0; i < m; i++) {
		cin >> u>> v;
		aft[u].insert(v);
	}

	vector<int> mustpass;
	int res = 0;

	mustpass.push_back(p[n]);

	for (int i = n-1; i >= 1; i--) {
		bool ok = true;
		for (int v : mustpass) {
			if (aft[p[i]].count(v) == 0) {
				ok = false;
				break;
			}
		}
		if (ok) {
			res++;
		}
		else {
			mustpass.push_back(p[i]);
		}
	}
	cout << res << endl;
}