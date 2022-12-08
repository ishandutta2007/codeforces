#include <bits/stdc++.h>

using namespace std;

int n, L, a;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> L >> a;
	int ans = 0;
	int prev = 0;
	int t, l;
	for (int i = 0; i < n; i++) {
		cin >> t >> l;
		int numallo = t - prev;
		if (numallo > 0) ans += numallo/a;
		prev = t+l;
	}
	int numallo = L - prev;

	if (numallo > 0) ans += numallo/a;
	cout << ans << endl;
}