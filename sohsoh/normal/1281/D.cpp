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

const ll MAXN = 60 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

bool grid[MAXN][MAXN] = {false};

ll solve() {
    ll r, c;
    cin >> r >> c;

    bool can = false;
    bool corner = false, edge = false, full = false, full_edge = false, all = true;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            char cc;
            cin >> cc;
            bool t = (cc == 'A');
            if (!t) {
                grid[i][j] = false;
                all = false;
                continue;
            }

            can = true;
            grid[i][j] = true;
            if (i == 0 || i == r - 1) {
                edge = true;
                if (j == 0 || j == c - 1) corner = true;
            }

            if (j == 0 || j == c - 1) edge = true;
        }
    }

    for (int i = 0; i < r; i++) {
        bool b = true;
        for (int j = 0; j < c; j++) {
            if (!grid[i][j]) b = false;
        }

        if (b) full = true;
        if (b && (i == 0 || i == r - 1)) {full_edge = true;}
    }

    for (int i = 0; i < c; i++) {
        bool b = true;
        for (int j = 0; j < r; j++) {
            if (!grid[j][i]) b = false;
        }

        if (b) full = true;
        if (b && (i == 0 || i == c - 1)) full_edge = true;
    }

    //DEBUG
//    for (int i = 0; i < r; i++) {
//        for (int j = 0; j < c; j++) {
//            cout << grid[i][j] << sep;
//        }
//        cout << endl;
//    }

    if (!can) return cout << "MORTAL" << endl, 0;
    ll bf = 4;
    if (edge) bf = 3;
    if (corner || full) bf = 2;
    if (full_edge) bf = 1;
    if (all) bf = 0;
    cout << bf << endl;

    return 0;
}

int main() {
    fast_io;
    ll t;
    cin >> t;
    while (t--) solve();
    return 0;
}