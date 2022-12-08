#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int l, r, a;
	cin >> l >> r >> a;
	int ans = 0;
	for (int k = 0; k <= 300; k++) {
		int sum = max(0, k-l) + max(0, k-r);
		if (sum <= a) ans = max(ans, k*2);
	}
	cout << ans << endl;
	cin >> ans;
}