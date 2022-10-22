#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
	//freopen("C.in", "r", stdin);
	//freopen("C.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	ll n, m;
	cin >> n >> m;
	ll pr;
	cin >> pr;
	ll st = pr;
	ll p = 0;
	for (ll i = 1; i < n; i++) {
		ll x;
		cin >> x;
		p = __gcd(x - pr, p);
		pr = x;
	}
	ll pa = -1;
	for (int i = 0; i < m; i++) {
		ll pn;
		cin >> pn;
		if (p % pn == 0) {
			pa = i + 1;
			break;
		}
	}
	if (pa == -1) {
		cout << "NO\n";
		return 0;
	}
	cout << "YES\n";
	cout << st << " " << pa << "\n";
}