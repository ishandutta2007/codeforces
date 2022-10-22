#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;

#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define debug(x)                    cerr << #x << ": " <<  x << endl;

ll poww(ll a, ll b, ll md) {
	return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll A[MAXN], n;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		ll sum = 0;
		for (int i = 0; i < n; i++) cin >> A[i], sum += A[i];
		sort(A, A + n);
		ll mx = *max_element(A, A + n);
		ll ans = 0;
		for (int i = 0; i < n - 1; i++) {
			ll diff = n * mx - sum - (mx - A[i]);
			diff -= A[i];
			if (diff > 0) ans = max(ans, diff);
			else ans = max(ans, (diff + ((n - 1ll) * MOD)) % (n - 1));
		}

		ll diff = (n * A[n - 2]) - sum - A[n - 1] - A[n - 2];

		if (diff > 0) ans = max(ans, diff);
		else ans = max(ans, diff + ((n - 1ll) * MOD) % (n - 1));	
		cout << ans << endl;
	}
	return 0;
}