/*
    Soheil Mohammadkhani
    IDK :)
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

#define all(x)                      (x).begin(),(x).end()
#define Sort(x)                     sort(all((x)))
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define SZ(x)                       ll(x.size())
#define debug(x)                    cerr << #x << ": " <<  x << endl;
#define bug(x)                      cerr << #x << ": " <<  x <<  " ";
#define alog(a, n)                  for (int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
#define FOR(n)                      for (int i = 0; i < n; i++)
#define fast_io                     ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define kill(x)                     return cout << x << endl, 0;

ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 2e5 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 998244353 ; // 1e9 + 9;

ll fact[MAXN] = {0};
ll inv[MAXN] = {0};
ll n, k;

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

ll calc() {
    ll c = n - k;

    ll ans = 0;
    for (int i = 0; i < c; i++) {
        ans += (i % 2 == 0 ? 1ll : -1ll) * C(i, c) * poww(c - i, n, MOD) % MOD;
    }
    return (ans % MOD + MOD) % MOD;
}

int main() {
    cin >> n >> k;
    prep();
    if (n <= k) kill(0);
    if (k == 0) kill(fact[n]);

    cout << 2 * C(k, n) * calc() % MOD << endl;
    return 0;
}