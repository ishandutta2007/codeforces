/*
    Soheil Mohammadkhani
    hello friend :)
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
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 2e5 + 10;
const ll LOG = 22;
const ll INF = 8e17;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll f1[MAXN], f2[MAXN], f3[MAXN], a[MAXN];

ll solve() {
    string s;
    cin >> s;

    ll n = SZ(s);

    fill(f1, f1 + n + 2, INF);
    fill(f2, f2 + n + 2, INF);
    fill(f3, f3 + n + 2, INF);

    ll ii = 0;
    for (char c : s) {
        a[ii] = c - '0';
        ii++;
    }

    for (int i = n - 1; i >= 0; i--) {
        if (a[i] == 1) f1[i] = i;
        if (a[i] == 2) f2[i] = i;
        if (a[i] == 3) f3[i] = i;
        f1[i] = min(f1[i], f1[i + 1]);
        f2[i] = min(f2[i], f2[i + 1]);
        f3[i] = min(f3[i], f3[i + 1]);
    }

//    alog(f1, n);
//    alog(f2, n);
//    alog(f3, n);

    ll bf = INF;
    for (int i = 0; i < n; i++) {
        ll e1 = f1[i];
        ll e2 = f2[i];
        ll e3 = f3[i];
        if (e1 == INF || e2 == INF || e3 == INF) continue;
        ll x = max(max(e1, e2), e3) - min(min(e1, e2), e3);
        bf = min(bf, x + 1);
    }

    if (bf > n) kill(0);
    kill(bf);
}

int main() {
    fast_io;
    ll t;
    cin >> t;
    while (t--) solve();
    return 0;
}