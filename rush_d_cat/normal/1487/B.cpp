#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int T;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> T;
	while (T --) {
		LL n, k;
		cin >> n >> k;
		-- k;
		if (n % 2 == 0) {
			k = k % n;
			cout << 1 + k << endl;
		} else {
			LL d = k / (n - 1);
			LL b = 1 + (d % n);
			LL todo = k % (n - 1);
			b = (b + todo) % n;
			if (todo >= n / 2) b ++;
			b = b % n; if (b == 0) b = n;
			cout << b << endl;
		}
	}
}