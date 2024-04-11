#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int sum[n+1];
	int cur;
	for (int i = 2; i <= n; i++) {
		cout << "? " << 1 << " " << i << endl;
		cin >> sum[i];
	}
	int ans[n+1];
	cout << "? " << 2 << " " << 3 << endl;
	cin >> cur;
	ans[1] = (sum[2]+sum[3]-cur)/2;
	for (int i = 2; i <= n; i++) {
		ans[i] = sum[i] - ans[1];
	}
	cout << "!";
	for (int i = 1; i <= n; i++) {
		cout << " " << ans[i];
	}
	cout << endl;
	// cin >> n;
}