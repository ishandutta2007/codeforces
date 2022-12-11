#include <bits/stdc++.h>
using namespace std;

bool solveEven(int n, int k) {
	if (n % 2 == 0 && n >= k * 2) {
		cout << "YES\n";
		for (int i = 0; i < k - 1; i++) cout << "2 ";
		cout << n - k * 2 + 2 << "\n";
		return true;
	}
	return false;
}

bool solveOdd(int n, int k) {
	if (n % 2 == k % 2 && n >= k) {
		cout << "YES\n";
		for (int i = 0; i < k - 1; i++) cout << "1 ";
		cout << n - k + 1 << "\n";
		return true;
	}
	return false;
}

void solve() {
	int n, k;
	cin >> n >> k;
	if (solveEven(n, k)) return;
	if (solveOdd(n, k)) return;
	cout << "NO\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}