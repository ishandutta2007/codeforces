#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	cout.tie(0);
	int t;
	cin >> t;
	while (t --) {
		ll x, n;
		cin >> x >> n;
		if (n % 4 == 0) {
			cout << x << "\n";
		} else if (n % 4 == 1) {
			if (x % 2 == 0) {
				cout << x - n << "\n";
			} else {
				cout << x + n << "\n";
			}
		} else if (n % 4 == 2) {
			if (x % 2 == 0) 
				cout << x + 1 << "\n";
			else
				cout << x - 1 << "\n";
		} else if (n % 4 == 3) {
			if (x % 2 == 0)
				cout << n + x + 1 << "\n";
			else
				cout << x - 1 - n << "\n";
		}
	}
}
/*
0 -1 1 4 0 -5 1 8 0
1 2 0 -3 1 6 0 -7 8
*/