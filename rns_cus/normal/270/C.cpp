#include <bits/stdc++.h>
using namespace std;

int n, k, a, ans;

int main() {
//	freopen("c.in", "r", stdin);
	cin >> n;
	while (n --) {
		cin >> k >> a;
		ans = max(ans, k + 1); a --;
		while (a) {
			k ++, a >>= 2;
		}
		ans = max(ans, k);
	}
	cout << ans << endl;
	return 0;
}