#include <bits/stdc++.h>
using namespace std;
int main() {
	int T; cin >> T;
	while (T--) {
		int n; cin >> n;
		int ans = 0;
		while (n--) {
			int x; cin >> x;
			if (x == 1) ans++;
			else if (x == 2) ans += 0;
			else ans++;
		}
		cout << ans << endl;
	}
	return 0;
}