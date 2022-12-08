#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define pii pair<int, int>

int t, n;

const ll mod = 1000000007;
const int maxn = 500010;

ll nums[maxn];

int bitcount[63];

ll mul (ll a, ll b) {
	return (a%mod)*(b%mod) % mod;
}

void add (ll &a, ll b) {
	a = (a + b)%mod;
}

void solve() {
	cin >> n;
	for (int i = 0; i < 61; i++) bitcount[i] = 0;
	for (int i = 1; i <= n; i++) {
		cin >> nums[i];
	}
	for (int i = 0; i < 61; i++) {
		for (int j = 1; j <= n; j++) {
			if (nums[j] & (1LL << i)) bitcount[i]++;
		}
	}
	ll res = 0LL;
	for (int i = 1; i <= n; i++) {
		ll andsum = 0LL;
		ll orsum = 0LL;

		for (int j = 0; j < 61; j++) {
			// do the or first

			if (nums[i] & (1LL << j)) {
				//bit is present
				orsum += mul(1LL << j, n);
			}
			else {
				orsum += mul(1LL << j, bitcount[j]);
			}

			//and sum
			if (nums[i] & (1LL << j)) {
				//must have bit to be in and
				andsum += mul(1LL << j, bitcount[j]);
			}
		}
		add(res, mul(andsum, orsum));
	}
	cout << res << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// for (int i = 0; i < 61; i++) {
	// 	cout << (1LL << i) << " ";
	// }
	// cout << endl;

	cin >> t;
	while (t--) solve();
	cout.flush();
}