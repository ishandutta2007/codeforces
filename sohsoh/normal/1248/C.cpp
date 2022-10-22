/*
    Soheil Mohammadkhani
    Maybe candidate after this contest :)
*/
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
#define SZ(x)                       ll(x.size())
#define debug(x)                    cerr << #x << ": " <<  x << endl;
#define alog(a, n)                  for (int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
#define fast_io                     ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 1e6; //Change me please :)
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll fact[MAXN], inv[MAXN];

void prep() {
    fact[0] = 1;
    inv[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        fact[i] = fact[i - 1] * i % MOD;
        inv[i] = poww(fact[i], MOD - 2, MOD);
    }
}

ll C(ll r, ll n) {
    return fact[n] * inv[r] % MOD * inv[n - r] % MOD;
}

ll solve(ll m) {
    ll k = 0, ans = 0;
    while (m >= 0) {
        ll n = m + k;
        ans += C(k, n);
        ans %= MOD;
        m -= 2;
        k++;
    }

    return ans;
}

int main() {
    fast_io;
    prep();
    ll n, m, ans = 0;
    cin >> n >> m;
    ans += 2 * solve(n);
    ans += 2 * solve(m);
    ans -= 2;
    ans = (ans + MOD) % MOD;
    cout << ans << endl;
    return 0;
}