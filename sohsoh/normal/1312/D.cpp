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
#define SZ(x)                       ll(x.size());
#define debug(x)                    cerr << #x << ": " <<  x << endl;
#define bug(x)                      cerr << #x << ": " <<  x <<  " ";
#define alog(a, n)                  for (int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
#define forr(n)                     for (int i = 0; i < n; i++)
#define fast_io                     ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 1e6 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 998244353; // 1e9 + 9;

int main() {
    fast_io;
    ll n, m;
    cin >> n >> m;

    ll* fact = new ll[m + 1];
    fact[0] = 1;
    for (int i = 1; i < m + 1; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }

    ll x = (((fact[m] % MOD) * (poww(fact[n - 1], MOD - 2, MOD) % MOD)) % MOD) * (poww(fact[m - n + 1], MOD - 2, MOD) % MOD);
//    cout << x << endl;
    x = x % MOD;
    x = x * (n - 2) % MOD;

    x *= poww(2, n - 3, MOD);

    x = x % MOD;

    cout << x << endl;

    return 0;
}