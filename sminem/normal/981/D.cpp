#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n, k;
ll a[55], z[55];

bool dp[55][55];

bool sub(ll a, ll b) {
	return (b & a) == b;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> k;
	for (ll i=1; i<=n; i++) {
		cin >> a[i];
		z[i] = z[i-1] + a[i];
	}

	ll mask = 0;
	for (ll v=61; v>=0; v--) {
		mask += 1ll << v;

		memset(dp, 0, sizeof(dp));
		dp[0][0] = true;

		for (ll i=1; i<=n; i++) {
			for (ll j=1; j<=k; j++) {
				for (ll y=0; y<i; y++) {
					dp[i][j] |= dp[y][j-1] && sub(z[i] - z[y], mask);
				}
			}
		}

		if (!dp[n][k])
			mask -= 1ll << v;
	}

	cout << mask;
}