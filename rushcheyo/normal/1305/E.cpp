#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 200005;
const int P = 998244353;
const int inf = 0x3f3f3f3f;

int power(int a, ll x) {
	int ans = 1;
	for (; x; x >>= 1, a = 1ll * a * a % P)
		if (x & 1) ans = 1ll * ans * a % P;
	return ans;
}
int gcd(int a, int b) {
	return !b ? a : gcd(b, a % b);
}

int main() {
	int n, m;
	cin >> n >> m;
	int k = 0, res = 0;
	while (k < n && res + k / 2 <= m) res += k / 2, ++k;
	if (k == n && res != m) return puts("-1"), 0;
	if (res == m) {
		for (int j = 1; j <= k; ++j) printf("%d ", j);
		for (int j = 1000000000 - (n - k) * (k + 1) + 1; j <= 1000000000; j += k + 1) printf("%d ", j);
		puts("");
		return 0;
	}
	for (int t = k + 2;; ++t) {
		int cnt = res;
		for (int i = 1; i <= k; ++i)
			if (t - i > i && t - i <= k) ++cnt;
		if (cnt < m) return puts("-1"), 0;
		if (cnt == m) {
			for (int j = 1; j <= k; ++j) printf("%d ", j);
			printf("%d ", t);
			for (int j = 1000000000 - (n - k - 1) * (t + 1) + 1; j <= 1000000000; j += t + 1) printf("%d ", j);
			puts("");
			break;
		}
	}
}