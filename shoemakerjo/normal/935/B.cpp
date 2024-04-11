#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	string s;
	cin >> s;
	int side = 3;
	int x = 0, y = 0;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'U') {
			y++;
		}
		else x++;
		if (x < y) {
			if (side == 3 || side == 1) {
				side = 1;
			}
			else {
				side = 1;
				ans++;
			}
		}
		if (x > y) {
			if (side == 2 || side == 3) {
				side = 2;
			}
			else {
				side = 2;
				ans++;
			}
		}
	}
	cout << ans << endl;
	cin >> n;
}