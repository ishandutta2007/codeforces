#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n, k;
	cin >> n >> k;
	if (k == 1LL) {
		cout << n << endl;
	}
	else {
		ll tp = 1LL;
		while (tp <= n) {
			tp *= 2LL;
		}
		cout << tp-1 << endl;
	}
	cin >> n;
}