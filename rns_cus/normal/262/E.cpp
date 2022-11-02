#include <bits/stdc++.h>
using namespace std;
#define N 44

int a[N];
long long c[N][N], n, t;

void prepare() {
	c[0][0] = 1;
	for (int i = 0; i <= 40; i ++) {
		c[i][0] = 1;
		for (int j = 1; j <= i; j ++) c[i][j] = c[i-1][j] + c[i-1][j-1];
	}
}

int main() {
//	freopen("e.in", "r", stdin);
	prepare();
	cin >> n >> t;
	int bit = 0;
	for (int i = 0; i <= 40; i ++) {
		if (t == (1ll << i)) {
			bit = i + 1; break;
		}
	}
	if (!bit) {
		puts("0"); return 0;
	}
	int m = 0;
	n ++;
	while (n) {
		a[++m] = n % 2, n /= 2;
	}
	long long ans = 0;
	int x = 0;
	for (int i = m; i >= 1; i --) {
		if (a[i]) {
			ans += c[i-1][bit-x];
		}
		if (a[i]) x ++;
if (x > bit) break;
	}
	if (x == bit) ans ++;
	if (bit == 1) ans --;
	cout << ans << endl;
	return 0;
}