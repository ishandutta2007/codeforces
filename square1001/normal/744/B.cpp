#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int n, a[20][1024];
int main() {
	cin >> n;
	for (int i = 0; i < 10; i++) {
		for (int t = 0; t <= 1; t++) {
			vector<int> x;
			for (int j = 0; j < n; j++) {
				if ((t ? j : ~j) & (1 << i)) x.push_back(j + 1);
			}
			fill(a[i * 2 + t], a[i * 2 + t] + n, 1999999999);
			if (x.size() == 0) continue;
			cout << x.size() << endl;
			for (int j = 0; j < x.size(); j++) {
				if (j) cout << ' ';
				cout << x[j];
			}
			cout << endl;
			for (int j = 0; j < n; j++) cin >> a[i * 2 + t][j];
		}
	}
	cout << -1 << endl;
	for (int i = 0; i < n; i++) {
		if (i) cout << ' ';
		int ret = 1999999999;
		for (int j = 0; j < 10; j++) {
			if (i & (1 << j)) ret = min(ret, a[j * 2][i]);
			else ret = min(ret, a[j * 2 + 1][i]);
		}
		cout << ret;
	}
	cout << endl;
	return 0;
}