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

ll n, q, k, A[MAXN], ps[MAXN];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> q >> k;
	for (int i = 1; i <= n; i++) cin >> A[i];
	A[n + 1] = k + 1;
	for (int i = 1; i <= n; i++) {
		ps[i] = ps[i - 1];
		ps[i] += A[i + 1] - A[i - 1] - 2;
	}

	while (q--) {
		int l, r;
		cin >> l >> r;
		if (l == r) cout << k - 1 << endl;
	       	else {
			ll ans = A[l + 1] - 2;
			ans += k - A[r - 1] - 1;	
			ans += ps[r - 1] - ps[l];
			cout << ans << endl;
		}
	}
	return 0;
}