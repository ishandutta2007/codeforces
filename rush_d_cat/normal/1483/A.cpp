#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
vector<int> v[N];

int main() {
	ios::sync_with_stdio(false);	
	int t;
	cin >> t;
	
	while (t --) {
		int n, m;
		cin >> n >> m;
		for (int i = 1; i <= m; i ++) {
			int c; cin >> c;
			v[i].clear();
			v[i].resize(c, 0);
			for (int j = 0; j < c; j ++) {
				cin >> v[i][j];
			}
		}
		vector<int> f(n+1, 0);
		for (int i = 1; i <= m; i ++) f[v[i][0]] ++;

		int mx = -1, mxId = -1;
		for (int i = 1; i <= n; i ++) {
			if (f[i] >= mx) {
				mx = f[i], mxId = i;
			}
		}

		int lim = (m + 1) / 2;
		if (mx <= lim) {
			cout << "YES" << endl;
			for (int i = 1; i <= m; i ++) cout << v[i][0] << " ";
			cout << endl;
		} else {
			vector<int> ans;
			for (int i = 1; i <= m; i ++) {
				if (v[i][0] != mxId) ans.push_back(v[i][0]);
				else if (v[i][0] == mxId && mx > lim && v[i].size() >= 2) {
					ans.push_back(v[i][1]); mx --;
				} else {
					ans.push_back(v[i][0]);
				}
			}
			if (mx == lim) {
				cout << "YES" << endl;
				for (auto x: ans) cout << x << " ";
				cout << endl;
			} else {
				cout << "NO" << endl;
			}
		}
	}
}