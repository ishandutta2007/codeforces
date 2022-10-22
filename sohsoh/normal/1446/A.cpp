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

ll n, W, A[MAXN];

int solve() {
	cin >> n >> W;
	vector<ll> ls;
	ll ans = -1, sum_ls = 0;
	for (int i = 1; i <= n; i++) {
		cin >> A[i];
		if (A[i] <= W) {
			if (A[i] >= (W + 1) / 2) ans = i;
			else if (sum_ls < (W + 1) / 2) {
				sum_ls += A[i];
				ls.push_back(i);
			}
		}
	}


	if (ans > 0) cout << 1 << endl << ans << endl;
	else {
		if (sum_ls < (W + 1) / 2) cout << -1 << endl;
		else {
			cout << ls.size() << endl;
			for (ll e : ls) cout << e << sep;
			cout << endl;
		}
	}

	return 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}