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

ll n, m, A[MAXN], B[MAXN];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	ll g = 0;
	for (int i = 0; i < n; i++) {
		cin >> A[i];
		if (i == 0) continue;
		if (g == 0) g = abs(A[i] - A[i - 1]);
		else g = __gcd(g, abs(A[i] - A[i - 1]));
	}

	for (int i = 0; i < m; i++) {
		ll x = 0;
		cin >> x;
		if (g == 0) cout << A[0] + x << sep;
		else cout << __gcd(g, A[0] + x) << sep;
	}

	cout << endl;
	return 0;
}