#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	cout.tie(0);
	int t;
	cin >> t;
	while (t --) {
		string s;
		cin >> s;
		int n = s.length();

		int ans = 1e9;
		for (int i = 0; i < n; i ++)
			for (int j = i + 1; j < n; j ++) {
				int x = 10 * (s[i] - '0') + (s[j] - '0');
				if (x % 25 == 0) {
					ans = min(ans, n - 2 - i);
				}
			}
		cout << ans << "\n";
	}
}