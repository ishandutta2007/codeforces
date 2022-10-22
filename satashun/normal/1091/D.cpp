#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef vector<int> vi;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define rep(i,n) rep2(i,0,n)
#define rep2(i,m,n) for(int i=m;i<(n);i++)
#define ALL(c) (c).begin(),(c).end()
#define dump(x) cout << #x << " = " << (x) << endl

const ll MOD = 998244353;
const int MX = 1000010;

ll inv[MX], fact[MX], ifact[MX];

void init() {
    inv[1] = 1;
    for (int i = 2; i < MX; ++i) {
        inv[i] = inv[MOD % i] * (MOD - MOD / i) % MOD;
    }
    fact[0] = ifact[0] = 1;
    for (int i = 1; i < MX; ++i) {
        fact[i] = fact[i-1] * i % MOD;
        ifact[i] = ifact[i-1] * inv[i] % MOD;
    }
}

ll comb(int n, int r) {
    if (n < 0 || r < 0 || r > n) return 0;
    return fact[n] * ifact[r] % MOD * ifact[n - r] % MOD;
}

int main() {
	init();
	int n; cin >> n;
	ll ans = fact[n];

	for (int i = 1; i < n; ++i) {
		ll t = (fact[n - i] - 1);
		if (t < 0) t += MOD;

		t = t * comb(n, i) % MOD * fact[i] % MOD;
		ans = (ans + t) % MOD;
	}

	cout << ans << endl;

	return 0;
}