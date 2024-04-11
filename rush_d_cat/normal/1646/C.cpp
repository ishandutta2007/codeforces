#include <bits/stdc++.h>
using namespace std;

const int N = 20000 + 10;
int t;
typedef long long ll;
int main() {
	ios::sync_with_stdio(false);
	cout.tie(0);

	cin >> t;

	vector<ll> fac(100, 0);
	fac[0] = 1;
	for (int i = 1; i <= 20; i ++) {
		fac[i] = fac[i-1] * i;
		if (fac[i] >= (ll)1e12) {
			break;
		}
	}

	while (t --) {
		ll n;
		cin >> n;
		int ans = 1e9;
		for (int i = 0; i < 1<<12; i ++) {
			ll s = n;
			int tmp = 0;
			for (int j = 0; j < 12; j ++) {
				if (i >> j & 1) s -= fac[j + 3], tmp += 1;
			}
			if (s >= 0) {
				for (int j = 0; j < 40; j ++) if (s >> j & 1) tmp += 1;
				ans = min(ans, tmp);
			}
		}
		cout << ans << "\n";
	}
}