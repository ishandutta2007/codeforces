#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t; cin >> t;
	while (t --) {
		int n, k; cin >> n >> k;
		vector<int> h(n);
		for (int i = 0; i < n; i ++) cin >> h[i];
		
		for (int i = 1; i <= k; i ++) {
			int pos = -1;
			for (int j = 0; j + 1 < n; j ++) {
				if (h[j] < h[j+1]) {
					++ h[j]; pos = j; break;
				}
			}
			if (pos == -1) {
				cout << -1 << endl; break;
			}
			if (i == k) {
				cout << pos + 1 << endl; break;
			}
			// for (auto x: h) cout << x << " "; cout << endl;
		}

	}
}