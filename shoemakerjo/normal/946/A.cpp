#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int a[n];
	int ans = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		ans += abs(a[i]);
	}
	cout << ans << endl;
	cin >> n;
}