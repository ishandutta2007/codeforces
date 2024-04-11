#include <iostream>
using namespace std;
int n, a[200009], b[200009], c[200009], d[32];
int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	long long s = 0;
	for (int i = 0; i < n; i++) cin >> b[i], s += b[i];
	for (int i = 0; i < n; i++) cin >> c[i], s += c[i];
	if (s % (2 * n) != 0) cout << -1 << endl;
	else {
		s /= 2 * n;
		bool f = true;
		for (int i = 0; i < n; i++) {
			if ((b[i] + c[i] - s) % n != 0) f = false;
			a[i] = (b[i] + c[i] - s) / n;
		}
		if (!f) cout << -1 << endl;
		else {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < 30; j++) {
					if (a[i] & (1 << j)) d[j]++;
				}
			}
			bool flag = true;
			for (int i = 0; i < n; i++) {
				long long p = 0, q = 0;
				for (int j = 0; j < 30; j++) {
					p += ((a[i] & (1 << j)) ? d[j] : 0) << j;
					q += ((a[i] & (1 << j)) ? n : d[j]) << j;
				}
				if (b[i] != p && c[i] != q) flag = false;
			}
			if (!flag) cout << -1 << endl;
			else {
				for (int i = 0; i < n; i++) {
					if (i) cout << ' ';
					cout << a[i];
				}
				cout << endl;
			}
		}
	}
	return 0;
}