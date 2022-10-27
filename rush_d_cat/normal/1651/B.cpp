#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ios::sync_with_stdio(false);
	cout.tie(0);
	int t;
	cin >> t;

	while (t --) {
		int n;
		cin >> n;
		ll ans[n + 1];
		ans[0] = 1;
		bool ok = true;
		for (int i = 1; i < n; i ++) {
			ans[i] = ans[i-1] * 3;
			if (ans[i] > 1000000000) ok = false;
		}
		if (!ok) cout << "NO" << "\n"; 
		else {
			cout << "YES" << "\n";
			for (int i = 0; i < n; i ++) cout << ans[i] << " ";
			cout << "\n";
		}
	}
}
/*
x < y


y-x y-x


3x, y
*/