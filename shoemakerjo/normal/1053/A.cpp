

#include <bits/stdc++.h>

using namespace std;
#define ll long long
ll n, m, k;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m >> k;
	if ( (2LL*n*m)%k != 0) {
		cout << "NO" << endl;
		return 0;
	}

	if ((n*m)%k == 0) {
		// cout << "this" << endl;
		ll divy = k; //must divide this out from either
		ll f1 = __gcd(n, divy);
		ll f2 = divy/f1;
		cout << "YES" << endl;
		cout << 0 << " " << 0 << endl;

		if (f1 > 1) {
			cout << 2*n/f1 << " " << 0 << endl;
			cout << 0 << " " << m/f2 << endl;
		}
		else {
			cout << n/f1 << " " << 0 << endl;
			cout << 0 << " " << 2*m/f2 << endl;
		}
	}
	else {
		// cout << "NO" << endl;
		ll divy = k/2LL;
		ll f1 = __gcd(n, divy);
		ll f2 = (divy)/f1;
		cout << "YES" << endl;
		cout << 0 << " " << 0 << endl;

		cout << n/f1 << " " << 0 << endl;
		cout << 0 << " " << m/f2 << endl;
		
	}
	
	
}