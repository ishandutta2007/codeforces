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
#define int  			    long long

ll poww(ll a, ll b, ll md) {
	return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 1e5 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

int n, A[MAXN], X[MAXN], S[MAXN];

inline void solve() {
	memset(X, 0, sizeof X);
	cin >> n;
	int ans = 0;
	for (int i = 1; i <= n; i++) cin >> A[i], S[i] = A[i];
	for (int i = 1; i <= n; i++) {
		S[i] -= X[i];
		S[i] = max(S[i], 1ll);
		X[i] += S[i] - 1;
		ans += S[i] - 1;
		int ind = A[i];
		int t = max(0ll, A[i] - n);
		ind -= t;
		X[i] -= t;
		while (ind > 1 && X[i] > 0) X[i + ind]++, ind--, X[i]--;
		X[i + 1] += X[i];
	}

	cout << ans << endl;
}

int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}