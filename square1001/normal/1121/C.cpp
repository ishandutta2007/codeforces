#include <vector>
#include <iostream>
using namespace std;
int main() {
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) cin >> a[i];
	vector<int> used(m, -1);
	vector<int> running(n, 0);
	vector<bool> interesting(n, false);
	int comp = 0;
	while (comp < n) {
		for (int i = 0; i < m; ++i) {
			if (used[i] != -1) ++running[used[i]];
		}
		for (int i = 0; i < m; ++i) {
			if (used[i] != -1 && running[used[i]] == a[used[i]] + 1) {
				++comp;
				used[i] = -1;
			}
		}
		for (int i = 0; i < m; ++i) {
			if (used[i] == -1) {
				for (int j = 0; j < n; ++j) {
					if (running[j] == 0) {
						running[j] = 1;
						used[i] = j;
						break;
					}
				}
			}
		}
		int percent = (100 * (comp * 2) + n) / (2 * n);
		for (int i = 0; i < n; ++i) {
			if (running[i] != 0 && running[i] <= a[i] && running[i] == percent) {
				interesting[i] = true;
			}
		}
	}
	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		if (interesting[i]) ++cnt;
	}
	cout << cnt << endl;
	return 0;
}