#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int n, a, d = 0;
	cin >> n;
	vector<int> c(n);
	for (int i = 0; i < n; ++i) {
		cin >> a;
		++c[a];
		d = max(d, a);
	}
	int l = 0;
	for (int i = 1; i < n; ++i) {
		if (c[i] != 4 * i) {
			l = i - 1;
			break;
		}
	}
	int ah = -1, aw = -1, ax = -1, ay = -1;
	for (int i = 1; i <= n && ah == -1; ++i) {
		if (n % i != 0) continue;
		int h = i, w = n / i;
		for (int j = 0; j < h && ah == -1; ++j) {
			for (int k = 0; k < w && ah == -1; ++k) {
				if (min({ j, k, h - j - 1, w - k - 1 }) == l && max({ j + k, (h - j - 1) + k, j + (w - k - 1), (h - j - 1) + (w - k - 1) }) == d) {
					vector<int> checkc(n);
					for (int x = 0; x < h; ++x) {
						for (int y = 0; y < w; ++y) {
							++checkc[abs(x - j) + abs(y - k)];
						}
					}
					if(c == checkc) ah = h, aw = w, ax = j + 1, ay = k + 1;
				}
			}
		}
	}
	if (ah == -1) {
		cout << -1 << '\n';
	}
	else {
		cout << ah << ' ' << aw << '\n' << ax << ' ' << ay << '\n';
	}
	return 0;
}