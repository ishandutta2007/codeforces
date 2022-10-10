#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	ll n;
	cin >> n;
	if(n == 1) {
		cout << "1\n";
		return 0;
	}
	vector<ll> pf;
	for(ll p = 2; p * p <= n; p++) {
		if(n % p)
			continue;
		pf.push_back(p);
		while(n % p == 0)
			n /= p;
	}
	if(n > 1)
		pf.push_back(n);
	if(pf.size() >= 2) {
		cout << "1\n";
		return 0;
	}
	cout << pf[0] << '\n';
}