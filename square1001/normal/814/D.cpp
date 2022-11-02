#include <vector>
#include <iomanip>
#include <iostream>
#include <algorithm>
using namespace std;
int n, x[1009], y[1009], r[1009]; vector<int> g[1009];
long long solve(int pos, int pre, int id) {
	long long ret = (id == 2 ? -1LL : 1LL) * r[pos] * r[pos];
	for (int i : g[pos]) ret += solve(i, pos, id == 2 ? 1 : id + 1);
	return ret;
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> x[i] >> y[i] >> r[i];
	vector<int> root;
	for (int i = 0; i < n; i++) {
		int p = -1, z = 1012345678;
		for (int j = 0; j < n; j++) {
			if (r[j] > r[i] && r[j] < z && 1LL * (x[i] - x[j]) * (x[i] - x[j]) + 1LL * (y[i] - y[j]) * (y[i] - y[j]) <= 1LL * (r[j] - r[i]) * (r[j] - r[i])) {
				z = r[j]; p = j;
			}
		}
		if (p != -1) g[p].push_back(i);
		else root.push_back(i);
	}
	long long ret = 0;
	for (int i : root) ret += solve(i, -1, 0);
	cout << fixed << setprecision(15) << ret * 3.14159265358979324 << endl;
	return 0;
}