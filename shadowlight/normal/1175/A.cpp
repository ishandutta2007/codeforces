#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
	//freopen("A.in", "r", stdin);
	//freopen("A.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	ll t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		ll n, k;
		cin >> n >> k;
		ll res = 0;
		while (n != 0) {
			res += n % k;
			n /= k;
			if (n) {
				res++;
			}
		}
		cout << res << "\n";
	}
}