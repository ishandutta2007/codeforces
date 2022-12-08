#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, a, b;
	cin >> n >> a >> b;
	int ans = 0;
	for (int i = 1; i <= a && i <= b; i++) {
		int cur = a/i;
		cur += b/i;
		if (cur >= n) {
			ans = i;
		}
	}
	cout << ans << endl;
	cin >> n;
}