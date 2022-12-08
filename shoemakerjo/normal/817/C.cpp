#include <iostream>
#define ll long long
using namespace std;
bool test(ll s, ll t) {
	ll temp = t;
	ll ds = 0;
	while (temp > 0) {
		ds += temp%10;
		temp /= 10;
	}
	if (t-ds >= s) return true;
	return false;
}

int main() {
	ll n, s;
	cin >> n >> s;
	ll low = 1;
	ll high = n;

	if (!test(s, n)) {
		cout << 0 << endl;
	}
	else {
		while (low <= high) {
			// cout << low << " " << high << endl;
			ll mid = (low+high)/2;
			if (test(s, mid)) {
				if (!test(s, mid-1)) {
					cout << n-mid+1 << endl;
					break;
				}
				high = mid - 1;
			}
			else low = mid + 1;
		}
	}
	// cin >> n;
}