#include <bits/stdc++.h>

using namespace std;

bool prime(int x) {
	for (int i = 2; i <= sqrt(x); i++) {
		if (x%i == 0) return false;
	}
	return true;
}

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = n+1; i < m; i++) {
		if (prime(i)) {
			cout << "NO" << endl;
			return 0;
		}
	}
	if (prime(m)) cout << "YES" << endl;
	else cout << "NO" << endl;
	cin >> n;
}