#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int x, y;
	cin >> x >> y;
	int ans = 0;
	int a = y, b = y, c = y;
	while (a < x || b < x || c < x) {
		if (a <= b && a <= c) {
			a = min(x, b+c-1);
		}
		else if (b <= c) {
			b = min(x, a+c-1);
		}
		else {
			c = min(x, a+b-1);
		}
		ans++;
	}
	cout << ans << endl;
	cin >> ans;
}