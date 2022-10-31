#include <iostream>
#include <set>

using namespace std;

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		int n, m;
		cin >> n >> m;
		set<int> a;
		for (int c = 0; c < n; ++c) {
			int x;
			cin >> x;
			a.insert(x);
		}
		bool norm = false;
		for (int c = 0; c < m; ++c) {
			int x;
			cin >> x;
			if (!norm && a.find(x) != a.end()) {
				cout << "YES\n" << 1 << " " << x << endl;
				norm = true;
			}
		}
		if (!norm) {
			cout << "NO" << endl;
		}
	}
	return 0;
}