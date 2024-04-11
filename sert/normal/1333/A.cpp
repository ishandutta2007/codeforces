#include <bits/stdc++.h>
using namespace std;

int main() {
	int t, n, m;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (n * m % 2 == 0 && i == 0 && j == m - 1 && m % 2 == 0) cout << "B";
				else if (n * m % 2 == 0 && i == n - 1 && j == 0 && m % 2 == 1) cout << "B";
				else cout << ((i + j) % 2 ? "W" : "B");
			}
			cout << "\n";
		}
	}
}