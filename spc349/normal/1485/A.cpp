#include <bits/stdc++.h>
using namespace std;
int main () {
	int T; cin >> T;
	while (T--) {
		int a, b; cin >> a >> b;
		int ans = 0x3f3f3f3f;
		for (int i = max(b, 2); i <= b + 100; i++) {
			int cur = a, sum = i - b;
			while (cur) cur /= i, sum++;
			ans = min(ans, sum);
		}
		cout << ans << endl;
	}
	return 0;
}