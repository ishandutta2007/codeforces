#include <bits/stdc++.h>

using namespace std;

int main() {
	int _;
	cin >> _;
	while (_ --) {
		long long n, B, x, y, a = 0, ans = 0;
		cin >> n >> B >> x >> y;
		for (int i = 1; i <= n; i ++) {
			if (a + x > B) a -= y;
			else a += x;
			ans += a;
		}
		cout << ans << "\n";
	}
	return 0;
}