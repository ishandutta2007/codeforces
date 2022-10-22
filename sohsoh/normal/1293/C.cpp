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
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

bool g[3][MAXN] = {false};

int main() {
    fast_io;
    ll n, q;
    cin >> n >> q;

    set<pair<pll, pll>> fp;

    while (q--) {
        ll r, c;
        cin >> r >> c;
        ll rp = 1;
        if (r == 1) rp = 2;

        if (g[r][c]) {
            g[r][c] = false;
            pll tp1 = {r, c};
            pll tp2 = {rp, c + 1};
            pll tp3 = {rp, c - 1};
            pll tp4 = {rp, c};
            fp.erase({tp1, tp2});
            fp.erase({tp1, tp3});
            fp.erase({tp1, tp4});
            fp.erase({tp2, tp1});
            fp.erase({tp3, tp1});
            fp.erase({tp4, tp1});
        } else {
            g[r][c] = true;
            pll tp1 = {r, c};
            pll tp2 = {rp, c + 1};
            pll tp3 = {rp, c - 1};
            pll tp4 = {rp, c};

            if (g[rp][c + 1]) {
                fp.insert({tp1, tp2});
            }

            if (g[rp][c - 1]) {
                fp.insert({tp1, tp3});
            }

            if (g[rp][c]) {
                fp.insert({tp1, tp4});
            }
        }

        if (fp.empty() && !g[1][1] && !g[2][n]) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}