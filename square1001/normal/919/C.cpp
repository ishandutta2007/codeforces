#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;
int n, m, c, a[2009][2009], b[2009][2009]; string s[2009];
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cin >> n >> m >> c;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
		for (int j = 0; j < m; j++) {
			if (s[i][j] == '*') a[i][j] = 1;
		}
	}
	int ret = 0;
	for (int i = 0; i < (c == 1 ? 1 : 2); i++) {
		for (int j = 0; j < n; j++) {
			int sum = 0;
			for (int l = 0; l < c; l++) sum += a[j][l];
			for (int k = 0; k <= m - c; k++) {
				if (sum == 0) ret++;
				sum += a[j][k + c] - a[j][k];
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				b[j][i] = a[i][j];
			}
		}
		swap(n, m);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				a[i][j] = b[i][j];
			}
		}
	}
	cout << ret << endl;
	return 0;
}