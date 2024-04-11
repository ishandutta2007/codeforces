#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int n, a, b, c;
	cin >> n >> a >> b >> c;
	int ans = 0;
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			if (i*a + j*b <= n) {
				if ((n - i*a - j*b) % c == 0) {
					ans = max(i + j + (n - i*a - j*b) / c, ans);
				}
			}
		}
	}
	cout << ans;
	return 0;
}