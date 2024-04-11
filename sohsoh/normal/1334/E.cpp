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
const ll MOD = 998244353; // 1e9 + 9;
const ll INF = 1e15;

ll D, fact[MAXN];
int q;
vector<ll> P;

inline bool Prime(ll n) {
	if (n == 1) return false;
	int sq = sqrt(n);
	for (int i = 2; i <= sq; i++) if (n % i == 0) return false;
	return true;
}

inline int C(ll n, ll k) {
	int ans = 0;
	while (n % k == 0) {
		n /= k;
		ans++;
	}

	return ans;
}

inline ll Seq(ll n) {
	ll tans = 1, ans = 0;

	for (ll e : P)
		if (n % e == 0)
			tans = tans * fact[C(n, e)] % MOD, ans += C(n, e);
	ans = fact[ans];
	return ans * poww(tans, MOD - 2, MOD) % MOD;	
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	scanf("%lld %d", &D, &q);
	int sq = sqrt(D);
	fact[0] = 1;
	for (int i = 1; i < MAXN; i++) fact[i] = fact[i - 1] * i % MOD;
	for (int i = 1; i <= sq; i++) {
		if (D % i) continue;
		if (Prime(i)) P.push_back(i);
		if (Prime(D / i) && D / i != i) P.push_back(D / i);
	}
	
	while (q--) {
		ll u, v;
		scanf("%lld %lld", &u, &v);
		ll g = __gcd(u, v);
		printf("%lld \n", Seq(u / g) * Seq(v / g) % MOD);
	}
	return 0;
}