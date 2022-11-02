#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
ll n, m, mul1 = 1, mul2 = 1; int d1, d2;
int main() {
	cin >> n >> m;
	while (mul1 < n) d1++, mul1 *= 7;
	while (mul2 < m) d2++, mul2 *= 7;
	if (n == 1) d1++, mul1 *= 7;
	if (m == 1) d2++, mul2 *= 7;
	if (d1 + d2 >= 8) cout << 0 << endl;
	else {
		int ret = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				string r;
				int p1 = mul1;
				for (int k = 0; k < d1; k++) {
					p1 /= 7;
					r += (i / p1) % 7 + 48;
				}
				int p2 = mul2;
				for (int k = 0; k < d2; k++) {
					p2 /= 7;
					r += (j / p2) % 7 + 48;
				}
				sort(r.begin(), r.end());
				bool f = true;
				for (int k = 1; k < r.size(); k++) {
					if (r[k - 1] == r[k]) f = false;
				}
				if (f) ret++;
			}
		}
		cout << ret << endl;
	}
	return 0;
}