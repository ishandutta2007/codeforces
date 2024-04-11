#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<pair<int, int>> a(n * 2);
	for (int i = 0; i < n; i++) {
		cin >> a[i * 2].first >> a[i * 2 + 1].first;
		a[i * 2].second = -1;
		a[i * 2 + 1].second = 1;
	}
	sort(a.begin(), a.end());
	int x = 0;
	for (auto p : a) {
		x -= p.second;
		if (x > 2) {
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
}