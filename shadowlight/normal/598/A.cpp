#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
	//freopen("A.in", "r", stdin);
	//freopen("A.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		ll x;
		cin >> x;
		ll res = x * (x + 1) / 2;
		for (ll d = 1; d <= x; d *= 2) {
			res -= 2 * d;
		}
		cout << res << "\n";
	}
}