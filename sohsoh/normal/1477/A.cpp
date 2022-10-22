#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
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

ll A[MAXN], n, k;

inline int solve() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> A[i];
	ll G = abs(A[1] - A[2]);
	for (int i = 1; i < n; i++)
		G = __gcd(G, abs(A[i] - A[i + 1]));
	for (int i = 1; i <= n; i++) {
		ll t = abs(k - A[i]);
		if (t % G == 0) return cout << "YES" << endl, 0;
	}

	cout << "NO" << endl;
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}