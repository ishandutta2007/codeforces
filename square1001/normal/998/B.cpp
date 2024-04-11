#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int n, m, a[109];
int main() {
	cin >> n >> m;
	vector<int> v;
	int d = 0;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	for (int i = 0; i < n; ++i) {
		if (a[i] % 2 == 1) ++d;
		else --d;
		if (d == 0 && i != n - 1) v.push_back(abs(a[i] - a[i + 1]));
	}
	sort(v.begin(), v.end());
	int ret = 0;
	for (int i : v) {
		if (i <= m) ++ret, m -= i;
	}
	cout << ret << '\n';
	return 0;
}