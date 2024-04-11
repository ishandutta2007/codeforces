#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int n, a[209], g[409][209], par[209];
int root(int x) {
	if (x == par[x]) return x;
	return par[x] = root(par[x]);
}
void unite(int x, int y) {
	par[root(x)] = root(y);
}
bool same(int x, int y) {
	return root(x) == root(y);
}
long long gcd(long long x, long long y) {
	if (y == 0) return x;
	return gcd(y, x % y);
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) par[i] = i;
	for (int i = 0; i < n; i++) cin >> a[i], unite(i, --a[i]), g[0][i] = a[i];
	for (int i = 0; i < 400; i++) {
		bool f = true;
		for (int j = 0; j < n; j++) {
			if (g[i][j] != g[i][g[i][j]]) f = false;
		}
		if (f) {
			cout << i + 1 << endl;
			return 0;
		}
		for (int j = 0; j < n; j++) g[i + 1][j] = g[i][g[0][j]];
	}
	long long ret = 1;
	for (int i = 0; i < n; i++) {
		vector<int> v;
		for (int j = 0; j < n; j++) {
			if (root(j) == i) v.push_back(j), g[0][j] = a[j];
		}
		if (v.size() == 0) continue;
		int z = 0;
		for (int j = 0; ; j++) {
			bool f = true;
			for (int k : v) {
				if (g[j][k] != g[j][g[j][k]]) f = false;
			}
			if (f) {
				if (z != 0) {
					ret = ret / gcd(ret, j - z) * (j - z);
					break;
				}
				else z = j;
			}
			for (int k : v) g[j + 1][k] = g[j][g[0][k]];
		}
	}
	cout << ret << endl;
	return 0;
}