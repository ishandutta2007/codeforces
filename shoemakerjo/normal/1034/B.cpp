#include <bits/stdc++.h>

using namespace std;

#define ll long long
ll n, m;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	if (n > m) swap(n, m);
	if (n >= 3) {
		if (n%2 == 1 && m % 2 == 1) {
			cout << n*m - 1 << endl;
		}
		else cout << n*m << endl;
		return 0;
	}
	if (n == 1) {
		if (m % 6 == 0) {
			cout << m << endl;
		}
		if (m % 6 == 1) {
			cout << m-1 << endl;
		}
		if (m % 6 == 2) {
			cout << m-2 << endl;
		}
		if (m % 6 == 3) {
			cout << m-3 << endl;
		}
		if (m % 6 == 4) {
			cout << m-2 << endl;
		}
		if (m % 6 == 5) {
			cout << m-1 << endl;
		}
	}
	if (n == 2) {
		if (m == 2) cout << 0 << endl;
		else if (m == 3) cout << 4 << endl;
		else if (m == 7) cout << 12 << endl;
		else cout << n*m << endl;
	}

}