#include <bits/stdc++.h>
using namespace std;

int main() {
//	freopen("in.txt", "r", stdin);
	int t, flag;
	long long x, i, j;
	cin >> t;
	while (t--) {
		cin >> x;
		flag = 0;
		for (i = 0; i <= pow(x / 2, 1.0 / 3) + 1; ++i) {
			j = pow(x - i * i * i, 1.0 / 3);
			if (j <= 0 || i <= 0)
				continue;
			if (i * i * i + j * j * j == x || i * i * i + (j + 1) * (j + 1) * (j + 1) == x
			        || i * i * i + (j - 1) * (j - 1) * (j - 1) == x) {
				flag = 1;
				break;
			}
		}
		cout << (flag ? "YES" : "NO") << endl;
	}
	return 0;
}