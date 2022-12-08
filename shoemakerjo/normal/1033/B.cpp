#include <bits/stdc++.h>

using namespace std;
#define ll long long
int t;
ll a, b;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin  >> t;
	while (t--) {
		cin >> a >> b;
		if (a - b != 1) {
			cout << "NO" << endl;
			continue;
		}
		ll sum = a+b;
		bool ok = true;
		for (ll i = 2; i <= sqrt(sum); i++) {
			if (sum % i == 0) {
				ok = false;
				break;
			}
		}
		if (ok) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}