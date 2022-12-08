#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n, k;
	cin >> n >> k;
	if (k - n >= 2LL) {
		cout << "No" << endl;
	}
	else {
		bool ok = true;
		for (ll i = 1LL; i <= k; i++) {
			if (n % i != i-1LL) {
				ok = false;
				break;
			}
		}
		if (ok) cout << "YeS" << endl;
		else cout << "nO" << endl;

	}
	cin >> n;
	
}