#include <bits/stdc++.h>
using namespace std;
const int N = 100000 + 10;
const int inf = 1e9;
int main() {
	ios::sync_with_stdio(false);
	cout.tie(0);
	int t;
	cin >> t;
	while (t --) {
		int n, k;
		cin >> n >> k;
		vector<int> a(n);
		int ans = 0;
		map<int, vector<int> > v;

		for (int i = 0; i < n; i ++) {
			cin >> a[i];
			v[a[i]].push_back(i);
		}
		if (k == n) {
			cout << 1000000000 << "\n"; continue;
		}

		int need = 0;
		for (const auto& [i, vec]: v) {
			if (k < need) break;
			int rem = k - need;
			ans = max(ans, i);
			if (rem >= 2) {
				if (n - vec[0] >= 3 or vec.back() + 1 >= 3) 
					ans = max(ans, min(2 * i, inf));
			} else if (rem == 1) {
				for (int x = 0; x + 1 < n; x ++) {
					if (a[x] > i and a[x+1] > i) {
						ans = max(ans, min( max(a[x], a[x+1]), 2 * i) );
					}	
				}
				if (vec.size() > 1) {
					for (int x = 0; x + 1 < n; x ++) {
						if (a[x] > i and a[x+1] > i) {
							ans = max(ans, min( max(a[x], a[x+1]), 2 * i) );
						}	
						if (a[x] == i and a[x+1] > i and vec.size() > 1) {
							ans = max(ans, min( max(a[x], a[x+1]), 2 * i) );
						}
						if (a[x] > i and a[x+1] == i and vec.size() > 1) {
							ans = max(ans, min( max(a[x], a[x+1]), 2 * i) );
						}
					}					
				}
			} else {
				for (int x = 0; x + 1 < n; x ++) {
					if (a[x] > i and a[x+1] > i) {
						ans = max(ans, min( min(a[x], a[x+1]), 2 * i) );
					}
				}
			}
			for (auto p: vec) a[p] = inf;
			need += vec.size();
		}
		cout << ans << "\n";

	}

}