#include <cstdio>
#include <iostream>

using namespace std;

typedef long long ll;

ll cnt(ll top) {
	ll sum = 0;
	ll bound = 1;
	ll fre = 1;
	for(int len = 1; len <= 18; ++len) {
		bound *= 10;
		if (bound <= top) {
			sum += fre * 9;
			if (len > 1) {
				fre *= 10;
			}
		} else {
			bound /= 10;
			int firstdig = int(top / bound);
			ll middle = (top % bound) / 10;
			int lastdig = int(top % 10);

			sum += firstdig * middle;
			if (lastdig > firstdig) {
				sum += firstdig;
			} else {
				sum += firstdig - 1;
			}
			if (bound >= 10) {
				bound /= 10;
			}
			sum += (firstdig - 1) * (bound - middle - 1);
			break;
		}
	}
	return sum;
}

int main() {
	ll a, b;
	cin >> a >> b;
	b++;
	ll ans = cnt(b) - cnt(a);
	cout << ans << endl;
	return 0;
}