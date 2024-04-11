#include <bits/stdc++.h>
using namespace std;

long long n, ans, p[5];

int main() {
//	freopen("k.in", "r", stdin);
	p[0] = 2, p[1] = 3, p[2] = 5, p[3] = 7;
	cin >> n;
	for (int i = 0; i < (1 << 4); i ++) {
		int bit = __builtin_popcount(i);
		long long mod = 1;
		for (int j = 0; j < 4; j ++) if (i & (1 << j)) mod *= p[j];
		if (bit & 1) ans -= n / mod;
		else ans += n / mod;
	}
	cout << ans << endl;
	return 0;
}