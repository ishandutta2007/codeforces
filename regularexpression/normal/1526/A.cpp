#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> a(2 * n);
		for (int i = 0; i < 2 * n; ++i) {
			cin >> a[i];
		}
		sort(a.begin(), a.end());
		vector<int> res;
		for (int i = 0; i < n; ++i) {
			res.push_back(a[i]);
			res.push_back(a[2 * n - i - 1]);
		}
		for (int i = 0; i < 2 * n; ++i) {
			if (i != 0) {
				cout << " ";
			}
			cout << res[i];
		}
		cout << "\n";
	}
	return 0;
}