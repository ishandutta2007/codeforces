#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cout.tie(0);
	int t;
	cin >> t;
	while (t --) {
		int n, d;
		cin >> n >> d;
		vector<int> a(n);
		for (int i = 0; i < n; i ++) cin >> a[i];
		vector<bool> vis(n, false);

		vector<int> vec;
		
		bool flag = true;
		int mx = 0;
		for (int i = 0; i < n; i ++) {
			if (not vis[i]) {
				int cur = i;
				vec.clear();
				while (not vis[cur]) {
					vec.emplace_back(a[cur]);
					vis[cur] = 1;
					cur = (cur + d) % n;
				}

				int pos = -1;
				for (int j = 0; j < vec.size(); j ++) {
					if (vec[j] == 0) {
						pos = j; break;
					}
				}
				if (pos == -1) flag = false;
				for (int i = pos, j = pos; i < pos + vec.size(); i = j) {
					if (vec[j%vec.size()] == 0) j++;
					else {
						while (j < pos + vec.size() && vec[j%vec.size()] == 1) j ++;
						mx = max(mx, j - i);
					}
				}
			}
		}
		if (not flag) cout << -1 << "\n"; else cout << mx << "\n";

	}
}