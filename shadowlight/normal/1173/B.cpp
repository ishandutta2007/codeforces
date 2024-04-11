#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
	//freopen("B.in", "r", stdin);
	//freopen("B.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	int m;
	cin >> m;
	int n = 0;
	while (2 * n - 1 < m) {
		n++;
	}
	cout << n << "\n";
	for (int i = 0; i < min(n, m); i++) {
		cout << "1 " << i + 1 << "\n";
	}
	for (int i = 0; i < m - n; i++) {
		cout << i + 2 << " " << n << "\n";
	}
}