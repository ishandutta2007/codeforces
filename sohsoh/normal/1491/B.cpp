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

int n, u, v, A[MAXN];

inline void solve() {
	cin >> n >> u >> v;
	int ans = v + min(u, v);
	for (int i = 1; i <= n; i++) {
		cin >> A[i];
		if (i > 1) {
			int t = abs(A[i] - A[i - 1]);
			if (t > 1) ans = 0;
			if (t == 1) ans = min({ans, u, v});
		}
	}	

	cout << ans << endl;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}