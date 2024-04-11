#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int _, n, q;

int main() {
	cin.tie(0)->ios::sync_with_stdio(false);
	cin >> _;
	while (_--) {
		cin >> n >> q;
		ll sum = 0, even = 0, odd = 0;
		for (int a, i = 1; i <= n; i++) {
			cin >> a;
			sum += a;
			if (a & 1) odd++;
			else even++;
		}
		while (q--) {
			ll type, x;
			cin >> type >> x;
			if (type) {
				sum += odd * x;
				if (x & 1) even += odd, odd = 0;
			} else {
				sum += even * x;
				if (x & 1) odd += even, even = 0;
			}
			cout << sum << "\n";
		}		
	}
	return 0;	
}