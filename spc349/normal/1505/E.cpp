#include <bits/stdc++.h>
using namespace std;

string a[10];

int main() {
	int n, m; cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int x = 0, y = 0, ans = a[0][0] == '*';
	while (x != n - 1 || y != m - 1) {
		if (x == n - 1) y++;
		else if (y == m - 1) x++;
		else if (a[x + 1][y] == a[x][y + 1]) y++;
		else if (a[x + 1][y] == '*') x++;
		else y++;
		ans += a[x][y] == '*';
	}
	cout << ans << endl;
	return 0;
}