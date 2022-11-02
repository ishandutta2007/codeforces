#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int n, m; long long x;
	cin >> n >> m;
	vector<int> a(n), b(m);
	for (int i = 0; i < n; ++i) cin >> a[i];
	for (int i = 0; i < m; ++i) cin >> b[i];
	cin >> x;
	vector<int> ma(n + 1, 1 << 30), mb(m + 1, 1 << 30);
	for (int i = 0; i < n; ++i) {
		int s = 0;
		for (int j = i; j < n; ++j) {
			s += a[j];
			ma[j - i + 1] = min(ma[j - i + 1], s);
		}
	}
	for (int i = 0; i < m; ++i) {
		int s = 0;
		for (int j = i; j < m; ++j) {
			s += b[j];
			mb[j - i + 1] = min(mb[j - i + 1], s);
		}
	}
	int ret = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (1LL * ma[i] * mb[j] <= x) {
				ret = max(ret, i * j);
			}
		}
	}
	cout << ret << '\n';
	return 0;
}