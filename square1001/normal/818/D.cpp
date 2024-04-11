#include <vector>
#include <iostream>
using namespace std;
int n, a, c[100009], s[100009]; vector<int> v[1000009];
int main() {
	ios::sync_with_stdio(false);
	cin >> n >> a;
	for (int i = 0; i < n; i++) {
		cin >> c[i]; s[i + 1] = s[i];
		if (c[i] == a) s[i + 1]++;
		v[c[i]].push_back(i);
	}
	bool flag = false;
	for (int i = 1; i <= 1000000; i++) {
		if (a == i || s[n] > v[i].size()) continue;
		bool f = true;
		for (int j = 0; j < v[i].size(); j++) {
			if (s[v[i][j]] > j) {
				f = false; break;
			}
		}
		if (f) {
			cout << i << endl;
			flag = true;
			break;
		}
	}
	if (!flag) cout << -1 << endl;
	return 0;
}