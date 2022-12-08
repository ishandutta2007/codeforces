#include <bits/stdc++.h>
using namespace std;

int main() {
//	freopen("in.txt", "r", stdin);
	int t, n, i, j;
	map<int, int> m;
	cin >> t;
	while (t--) {
		m.clear();
		cin >> n;
		for (i = 0; i < n; ++i) {
			cin >> j;
			++m[j];
		}
		for (auto &it : m) {
			cout << it.first << ' ';
			--it.second;
		}
		for (auto it : m) {
			for (i = 0; i < it.second; ++i) {
				cout << it.first << ' ';
			}
		}
		cout << endl;
	}
	return 0;
}