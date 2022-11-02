#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int n, a[1009][5];
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> a[i][j];
		}
	}
	vector<int> ret;
	for (int i = 0; i < n; i++) {
		bool f = false;
		for (int j = 0; j < n && !f; j++) {
			for (int k = j + 1; k < n && !f; k++) {
				if (j != i && k != i) {
					int r = 0;
					for (int l = 0; l < 5; l++) r += (a[j][l] - a[i][l]) * (a[k][l] - a[i][l]);
					if (r > 0) f = true;
				}
			}
		}
		if (!f) ret.push_back(i + 1);
	}
	cout << ret.size() << endl;
	for (int i : ret) cout << i << endl;
	return 0;
}