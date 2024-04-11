/*
    Soheil Mohammadkhani
    I will change this text here when i've got "Expert" :)
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

const ll MAXN = 1e6 + 10; // CHANGE :)
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll h, c, t;
pdd bin_1() {
    ll lb = 1;
    ll hb = 1e8;
    while (hb - lb > 4) {
        ll m1 = (lb) + (hb - lb) / 3;
        ll m2 = (hb) - (hb - lb) / 3;
        ld c1 = ((m1 * h) + ((m1 - 1) * c)) ;
        ld c2 = ((m2 * h) + ((m2 - 1) * c)) ;
        c1 /= ld(2 * m1 - 1);
        c2 /= ld(2 * m2 - 1);
        c1 = abs(c1 - t);
        c2 = abs(c2 - t);
        if (c1 < c2) hb = m2;
        else lb = m1;
    }

    ll ans = lb;
    ld bf = INF;
    for (int i = lb; i <= hb; i++) {
        ld calc = ((i * h) + (i - 1) * c) / ld(2 * i - 1);
        if (abs(calc - ld(t)) < bf) {
            ans = i;
            bf = abs(calc - t);
        }
    }


    return {2 * ans - 1, bf};
}


pdd bin_2() {
    ll lb = 1;
    ll hb = 1e8;
    while (hb - lb > 4) {
        ll m1 = (lb) + (hb - lb) / 3;
        ll m2 = (hb) - (hb - lb) / 3;
        ld c1 = ((m1 * h) + ((m1) * c));
        ld c2 = ((m2 * h) + ((m2) * c));
        c1 /= ld(2 * m1);
        c2 /= ld(2 * m2);
        c1 = abs(c1 - t);
        c2 = abs(c2 - t);
//
//        cerr << fixed;
//        cerr.precision(20);
        if (c1 > c2) lb = m2;
        else hb = m1;

    }

    ll ans = lb;
    ld bf = INF;
    for (int i = lb; i <= hb; i++) {
        ld calc = ((i * h) + (i) * c) / ld(2 * i);
        if (abs(calc - ld(t)) < bf) {
            ans = i;
            bf = abs(calc - t);
        }
    }

    return {2 * ans, bf};
}


ll solve() {
    cin >> h >> c >> t;
    pdd x = bin_1();
    pdd y = bin_2();

//    debug(y.Y)

    if (x.Y == y.Y) cout << min(x.X, y.X);
    else if (x.Y > y.Y) cout << y.X;
    else cout << x.X;

    cout << endl;
    return 0;
}

int main() {
    fast_io;
    ll t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}