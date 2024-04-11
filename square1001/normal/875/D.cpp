#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int n, bits, a[200009], lvl[200009], rm[19][200009], ro[19][200009];
int rangemax(int l, int r) {
	return max(rm[lvl[r - l]][l], rm[lvl[r - l]][r - (1 << lvl[r - l])]);
}
int rangeor(int l, int r) {
	return ro[lvl[r - l]][l] | ro[lvl[r - l]][r - (1 << lvl[r - l])];
}
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		rm[0][i] = a[i];
		ro[0][i] = a[i];
	}
	for (int i = 1; i <= n; ++i) {
		while ((2 << lvl[i]) < i) ++lvl[i];
	}
	bits = lvl[n];
	for (int i = 0; i < bits; ++i) {
		for (int j = 0; j <= n - (1 << i); ++j) {
			rm[i + 1][j] = max(rm[i][j], rm[i][j + (1 << i)]);
			ro[i + 1][j] = ro[i][j] | ro[i][j + (1 << i)];
		}
	}
	long long ans = 0;
	for (int i = 0; i < n; ++i) {
		int cur = a[i], pos = i + 1;
		while (pos != n + 1) {
			int L = pos, R = n + 1;
			while (R - L > 1) {
				int M = (L + R) >> 1;
				if (rangeor(i, M) != cur) R = M;
				else L = M;
			}
			int l = pos - 1, r = R;
			while (r - l > 1) {
				int m = (l + r) >> 1;
				if (rangemax(i, m) < cur) l = m;
				else r = m;
			}
			ans += r - pos;
			pos = R;
			cur = rangeor(i, pos);
		}
	}
	cout << ans << endl;
	return 0;
}