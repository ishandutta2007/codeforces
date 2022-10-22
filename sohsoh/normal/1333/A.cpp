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

int solve() {
    int n, m;
    cin >> n >> m;
    string res;
    string res2;
    for (int i = 0; i < m; i++) {
        if (i % 2 == 0) {
            res.push_back('B');
            res2.push_back('W');
        } else {
            res.push_back('W');
            res2.push_back('B');
        }
    }

    for (int i = 0; i < n - 1; i++) {
        if (i % 2 == 0) {
            cout << res << endl;
        } else {
            cout << res2 << endl;
        }
    }


    res2.pop_back();
    res.pop_back();
    if (n % 2 == 0 && m % 2 == 0) {
        cout << 'B';
        cout << res << endl;
        return 0;
    }

    if (n % 2 == 0) {
        cout << res2;
        cout << 'B' << endl;
    } else {
        cout << res;
        cout << 'B' << endl;
    }

    return 0;
}

int main() {
//    fast_io;
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}