#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int a[n];
	int ans[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = n-1; i >= 0; i--) {
		ans[i] = 0;
		if (i == n-1) {
			ans[i] = a[i];
		}
		else {
			ans[i] = a[i]+a[i+1];
		}
	}
	for (int i = 0; i < n; i++) {
		cout << ans[i] << " ";
	}
	cout << endl;
	cin >> n;
}