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
#define FOR(n)                      for (int i = 0; i < n; i++)
#define fast_io                     ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

ll poww(ll a, ll b, ll md) {
    if (b == -1) return poww(a, md - 2, md);
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 1e6 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll NMAX = 2e17;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

pll s, z, a, b;
ll t;

ll zer(ll n) {
    ll j = 0;
    while (n > 0) {
        j++;
        n /= 10;
    }

    return j;
}

int main() {
    fast_io;
    cin >> z.X >> z.Y >> a.X >> a.Y >> b.X >> b.Y;
    cin >> s.X >> s.Y >> t;

    vector<pll> v;
    v.push_back(z);
    for (int i = 1; ; i++) {
        if (zer(v.back().X) + zer(a.X) > 18 || zer(v.back().Y) + zer(a.Y) > 18) break;
        ll x = v.back().X * a.X + b.X;
        ll y = v.back().Y * a.Y + b.Y;

        if (x > NMAX || y > NMAX) break;
        v.push_back({x, y});
    }


    ll bf = 0;

    for (int i = 0; i < v.size(); i++) {
        pll p = v[i];
        ll tt = t;
        tt -= abs(p.X - s.X);
        tt -= abs(p.Y - s.Y);

        if (tt < 0) continue;

        for (ll j = 0; j < v.size() - i; j++) {
            for (ll k = 0; k <= i; k++) {
                ll t2 = tt;

                pll p1 = v[i + j];
                pll p2 = v[i - k];

                ll p1d, p2d;
                p1d = abs(p.X - p1.X) + abs(p.Y - p1.Y);
                p2d = abs(p.X - p2.X) + abs(p.Y - p2.Y);

                if (t2 - p1d - p1d - p2d >= 0 || t2 - p1d - p2d - p2d >= 0) bf = max(bf, 1 + j + k);
            }
        }
    }

    cout << bf << endl;
    return 0;
}