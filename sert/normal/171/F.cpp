#include <bits/stdc++.h>
using namespace std;

int reverse(int x) {
	int y = 0;
	while (x > 0) {
		y = y * 10 + x % 10;
		x /= 10;
	}
	return y;
}

void solve() {
	vector<int> a;
	int mx = (int)1e6;
	vector<bool> isPrime(mx, true);

	for (int i = 2; i < mx; i++) {
		if (!isPrime[i]) continue;
		for (int j = i * 2; j < mx; j += i) {
			isPrime[j] = false;
		}
	}


	for (int i = 10; i < mx; i++) {
		if (!isPrime[i]) continue;
		int x = reverse(i);
		if (x == i) continue;
		if (isPrime[x]) {
			a.push_back(i);
		}
	}

	int x;
	cin >> x;
	cout << a[x - 1] << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
#ifdef SERT
	int t = 1;
	for (int i = 1; i < t; i++) {
		solve();
	}
#endif
}