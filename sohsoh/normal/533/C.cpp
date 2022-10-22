/*
    Soheil Mohammadkhani
    I will change this text here when i've got "Candidate Master":)
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

const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

int main() {
    fast_io;
    pll p, v;
    cin >> p.X >> p.Y >> v.X >> v.Y;
    ll t = 0;
    while (true) {
        if (t % 2 == 0) {
            ll xd = v.X - p.X, yd = v.Y - p.Y;
            if (xd < yd && make_pair(p.X - 1, p.Y) != v && p.X > 0) p.X--;
            else if (make_pair(p.X, p.Y - 1) != v && p.Y > 0) p.Y--;
            else if (p.X > 0 && make_pair(p.X - 1, p.Y) != v) p.X--;

            if (p == make_pair(0ll, 0ll)) return cout << "Polycarp" << endl, 0;
        } else {
            if (v.X > 0 && v.Y > 0 && make_pair(v.X - 1, v.Y - 1) != p) v.X--, v.Y--;
            else {
                ll xd = v.X - p.X, yd = v.Y - p.Y;
                if (xd < yd && make_pair(v.X - 1, v.Y) != p && v.X > 0) v.X--;
                else if (make_pair(v.X, v.Y - 1) != p && v.Y > 0) v.Y--;
                else if (v.X > 0 && make_pair(v.X - 1, v.Y) != p) v.X--;
            }

            if (v == make_pair(0ll, 0ll)) return cout << "Vasiliy" << endl, 0;
        }
        t++;
    }
    return 0;
}