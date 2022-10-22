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
#define debug2(x)                   cerr << #x << ": " <<  x <<  " ";
#define debug_p(x)                  cerr << #x << ": " <<  x.X <<  " " << x.Y << endl;
#define alog(a, n)                  for (int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
#define FOR(n)                      for (int i = 0; i < n; i++)
#define fast_io                     ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define kill(x)                     return cout << x << endl, 0;

ll poww(ll a, ll b, ll md) {
    if (b == -1) return poww(a, md - 2, md);
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 1e6 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll c[MAXN] = {0};

ll solve() {
    ll x, cs = 0;
    cin >> x;
    string s;
    cin >> s;
    for (char e : s) {
        c[cs] = e - '0';
        cs++;
    }

    for (int i = 0; i < cs && cs < x; i++) {
        if (c[i] < 2) continue;
        ll rep = c[i] - 1;
        ll pcs = cs;
        for (int k = 0; k < rep && cs < x; k++) {
            for (int j = i + 1; j < pcs && cs < x; j++) {
                c[cs] = c[j];
                cs++;
            }
        }
    }

    ll sz = SZ(s);
    for (ll i = 0; i < x; i++) {
        if (c[i] < 1) continue;
        sz += (((c[i] - 1) % MOD) * ((sz - i - 1) % MOD)) % MOD;
    }

    cout << sz % MOD << endl;
    return 0;
}

int main() {
    fast_io;
    ll t;
    cin >> t;
    while (t--) solve();
    return 0;
}