#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		bool can = false;
		for (int i = 0; i < 20; i++) {
			can |= i * 111 <= n && (n - i * 111) % 11 == 0;
		}
		cout << (can ? "YES\n" : "NO\n");
	}
	return 0;
}