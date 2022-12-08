#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
	ll n, a, b;
	cin >> n >> a >> b;
	bool ok = false;
	for (ll i = 0LL; i <= n; i+=1LL) {
		if (i*a > n) break;
		ll cur = n - i*a;
		if (cur % b == 0LL) {
			cout << "YES" << endl;
			cout << i << " " << cur/b << endl;
			ok = true;
			break;
		}
	}
	if (!ok)  {
		cout << "NO" << endl;
	}
	cin >> n;
}