// Sohsoh84 :)))
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
#define int 			    ll

const ll MAXN = 2e5 + 10;
const ll LOG = 20;

ll A[MAXN], B[MAXN], G[MAXN][LOG], n, lgg[MAXN];

inline void solve() {
	cin >> n;
	lgg[1] = 0;
	for (int i = 1; i <= n; i++) {
		cin >> A[i];
		if (i > 1) {
			G[i - 1][0] = abs(A[i] - A[i - 1]);
			lgg[i] = lgg[i / 2] + 1;
		}
	}

	for (int j = 1; j < LOG; j++) {
		for (int l = 1; l < n; l++) {
			int r = min(n - 1, l + (1 << (j - 1)));
			G[l][j] = __gcd(G[l][j - 1], G[r][j - 1]);
		}
	}

	ll ans = 1;
	for (int i = 1; i < n; i++) {
		int l = 1, r = n - i;
		while (l < r) {
			int mid = (l + r + 1) >> 1, x = lgg[mid];
			ll g = G[i][x];	
			g = __gcd(g, G[min(n - 1, i + mid - (1 << x))][x]);
			if (g > 1) l = mid;
			else r = mid - 1;
		}

		if (l == 1) {
			if (ans == 1 && G[i][0] > 1) {
				ans = 2;
			}
		} else ans = max(ans, l + 1);
	}

	cout << ans << endl;
	for (int i = 1; i <= n; i++) memset(G[i], 0, sizeof G[i]);
}

int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}