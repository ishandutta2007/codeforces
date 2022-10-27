
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t --) {
		LL n;
		cin >> n;
		if (n % 2050) cout << -1 << endl;
		else {
			n /= 2050;
			int ans = 0;
			while (n) {
				ans += n % 10; n /= 10;
			}
			cout << ans << endl;
		}
	}
}