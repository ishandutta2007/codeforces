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

const ll MAXN = 1e5 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

bool P[MAXN];
int F[MAXN];

bool is_prime(int x) {
	if (x == 1) return false;
	int sq = sqrt(x);
	for (int i = 2; i <= sq; i++) if (x % i == 0) return false;
	return true;
}

inline int solve() {
	int d;
	cin >> d;
	cout << ll(F[d + 1] * F[F[d + 1] + d]) << endl;
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	for (int i = 2; i < MAXN; i++) P[i] = is_prime(i);
	for (int i = MAXN - 2; i > 0; i--) {
		if (P[i]) F[i] = i;
		else F[i] = F[i + 1];
	}

	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}