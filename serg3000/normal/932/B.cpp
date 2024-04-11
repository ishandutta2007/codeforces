#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int b[9][1000001];
int main() {
	int q, l, r, k;
	cin >> q;
	vector<int> a(1000001);
	for (int i = 1; i < 10; i++) {
		a[i] = i;
	}
	int os = 0;
	for (int i = 0; i < 1000001; i++) {
		int i2 = i;
		int c = 1;
		while (i2 > 0) {
			if (i2 % 10 != 0) {
				c *= (i2 % 10);
			}
			i2 /= 10;
		}
		a[i] = a[c];
	}
	for (int i = 1; i < 1000001; i++) {
		for (int j = 0; j < 9; j++) {
			if (a[i] == j + 1) {
				b[j][i] = b[j][i - 1] + 1;
			}
			else {
				b[j][i] = b[j][i - 1];
			}
		}
	}
	for (int po = 0; po < q; po++) {
		cin >> l >> r >> k;
		k -= 1;
		l -= 1;
		r -= 1;
		cout << (b[k][r + 1] - b[k][l]) << '\n';
	}

	return 0;
}