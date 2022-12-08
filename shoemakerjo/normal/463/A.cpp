#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, s;
	cin >> n >> s;
	int ans = -1;

	int x, y;
	while (n--) {
		cin >> x >> y;
		if (s < x) continue;
		if (s == x) {
			if (y == 0) {
				ans = max(ans, 0);
			}
			continue;
		}
		if (y != 0) ans = max(ans, 100-y);
		else ans = max(ans, 0);
	}

	cout << ans << endl;
	cin >> n;

}