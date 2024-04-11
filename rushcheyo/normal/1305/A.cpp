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

int t, n, a[N], b[N];

int main() {
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; ++i) cin >> a[i];
		for (int i = 0; i < n; ++i) cin >> b[i];
		sort(a, a + n);
		sort(b, b + n);
		for (int i = 0; i < n; ++i) cout << a[i] << ' ';
		cout << endl;
		for (int i = 0; i < n; ++i) cout << b[i] << ' ';
		cout << endl;
	}
}