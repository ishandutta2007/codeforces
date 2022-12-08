#include <bits/stdc++.h>
using namespace std;
int c[2][27];

int main() {
//	freopen("in.txt", "r", stdin);
	int t, n, k, i, j;
	bool ok;
	char ch;
	cin >> t;
	while (t--) {
		cin >> n >> k;
		memset(c, 0, sizeof(c));
		ok = true;
		for (i = 0; i < 2; ++i) {
			getchar();
			for (j = 0; j < n; ++j) {
				ch = getchar();
				++c[i][ch - 'a'];
			}
		}
		for (i = 0; i < 26; ++i) {
			c[0][i] -= c[1][i];
			if (c[0][i] % k != 0 || c[0][i] < 0) {
				ok = false;
				break;
			}
			c[0][i + 1] += c[0][i];
		}
		cout << (ok ? "YES" : "NO") << endl;
	}
	return 0;
}