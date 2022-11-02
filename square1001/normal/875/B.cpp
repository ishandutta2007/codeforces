#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int n, p[300009], a[300009], bit[300009];
void add(int p, int x) {
	for (int i = p + 1; i <= n; i += i & (-i)) bit[i] += x;
}
int sum(int r) {
	int ret = 0;
	for (int i = r; i >= 1; i -= i & (-i)) ret += bit[i];
	return ret;
}
int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> p[i], p[i]--, add(i, 1);
	vector<int> ret;
	for (int i = n - 1; i >= 0; i--) {
		a[p[i]] = 1; add(p[i], -1);
		ret.push_back(sum(p[i] + 1) + 1);
		if (ret.size() >= 2) ret.back() = max(ret.back(), ret[ret.size() - 2] - 1);
	}
	for (int i = ret.size() - 1; i >= 0; i--) cout << ret[i] << ' ';
	cout << 1;
	return 0;
}