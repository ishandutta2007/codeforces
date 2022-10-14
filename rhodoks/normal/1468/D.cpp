#include <bits/stdc++.h>
const int N = 2e5 + 9;
using namespace std;
int n, m, a, b;
int s[N];
int main() {
	int T;
	cin >> T;
	while (T--) {
		cin >> n >> m >> a >> b;
		for (int i = 0; i < m; ++i) cin >> s[i];
		sort(s, s + m);
		int num = abs(a - b) - 1, tm = a < b ? b - 1 : n - b;
		int ans = 0;
		for (int i = min(num - 1, m-1); i >= 0; --i) {
			if (tm >= s[i]+1) {
				ans ++;
				tm --;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}