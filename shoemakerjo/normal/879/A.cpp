#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	int ans = 0;
	int s, d;
	for (int i = 0; i < n; i++) {
		cin >> s >> d;
		int x = (ans-s)/d;
		x++;
		x = max(x, 0);
		if (s > ans) x = 0;
		ans = x*d + s;
		// cout << ans << endl;
	}
	cout << ans << endl;
	// cin >> ans;
}