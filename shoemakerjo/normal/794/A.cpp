#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int a, b, c, n;
	cin >> a >> b >> c >> n;
	int ans = 0;
	int cur;
	for (int i = 0; i < n; i++) {
		cin >> cur;
		if (cur > b && cur < c) ans++;
	}
	cout << ans << endl;
	cin >> ans;

}