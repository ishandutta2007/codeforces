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

const ll MAXN = 1e2 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll A[MAXN][MAXN], n;

bool is_prime(ll x) {
	if (x == 1) return false;
	ll sq = sqrt(x);
	for (int i = 2; i <= sq; i++) if (x % i == 0) return false;
	return true;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;

	while (t--) {
		cin >> n;
		for (int i = 1; i < n; i++) for (int j = 1; j < n; j++) A[i][j] = 4;
		ll s = 4 * (n - 1);
		ll q = 1;
		while (true) {
			if (!is_prime(q) && is_prime(s + q)) break;
			q++;
		}

		for (int i = 1; i < n; i++) A[n][i] = A[i][n] = q;
		s = q * (n - 1);

		q = 2;
		while (true) {
			if (!is_prime(q) && is_prime(s + q)) break;
			q++;
		}

		A[n][n] = q;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) cout << A[i][j] << sep;
			cout << endl;
		}
	}
	return 0;
}