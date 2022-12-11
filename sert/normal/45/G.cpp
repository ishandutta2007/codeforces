#include <bits/stdc++.h>
using namespace std;

bool isPrime(int x) {
	if (x <= 1) return false;
	for (int i = 2; i * i <= x; i++)
		if (x % i == 0) return false;
	return true;
}

void solve(int n = -1) {
	if (n == -1)
		cin >> n;
	if (n == 3) {
		cout << "1 1 2\n";
		return;
	}

	int sum = (n * (n + 1)) / 2;
	if (isPrime(sum)) {
		for (int i = 0; i < n; i++) {
			cout << "1 ";
		}
		cout << "\n";	
		return;
	}

	for (int i = 2; i <= n; i++) {
		if (isPrime(i) && isPrime(sum - i)) {
			for (int j = 1; j <= n; j++) {
				cout << (i == j ? 2 : 1) << " ";
			}
			cout << "\n";
			return;
		}
	}
	for (int i = 2; i <= n; i++) {
		if (i != 3 && isPrime(i) && isPrime(sum - i - 3)) {
			for (int j = 1; j <= n; j++) {
				if (j == 3) cout << "2 ";
				else if (j == i) cout << "3 ";
				else cout << "1 ";
			}
			cout << "\n";
			return;
		}
	}
	exit(1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
#ifdef SERT
	for (int i = 2; i < 10; i++) {
		cout << i << " " << flush;
		solve(i);
		cout << flush;
	}
#else
	solve();
#endif
}