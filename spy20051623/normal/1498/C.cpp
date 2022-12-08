#include <bits/stdc++.h>
using namespace std;
long long s[1005][1005];
const int mod = 1e9 + 7;

int main() {
//	freopen("in.txt", "r", stdin);
	long long t, n, k, i, j, sum;
	cin >> t;
	while (t--) {
		memset(s, 0, sizeof(s));
		cin >> k >> n;
		s[n][k] = 1;
		for (i = n; i > 0; --i) {
			for (j = k; j > 0; --j) {
				s[i][j - 1] = (s[i][j - 1] + s[i][j]) % mod;
				s[i - 1][k - j] = (s[i - 1][k - j] + s[i][j]) % mod;
			}
		}
		sum = 0;
		for (i = 1; i <= n; ++i)
			sum = (sum + s[i][0]) % mod;
		cout << sum << endl;
	}
	return 0;
}