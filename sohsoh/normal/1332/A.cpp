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
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

int solve() {
    int a, b, c, d;
    int x, y;
    int x1, y1, x2, y2;
    cin >> a >> b >> c >> d;

    cin >> x >> y;
    cin >> x1 >> y1 >> x2 >> y2;

    if (x1 == x2) {
        if (a > 0 || b > 0)
            return cout << "NO" << endl, 0;
    }

    if (y1 == y2) {
        if (d > 0 || c > 0)
            return cout << "NO" << endl, 0;
    }

    int ex = a - b;
    x -= ex;

    int ey = c - d;
    y -= ey;

//    bug(x1);
//    bug(x);
//    bug(x2);
//    bug(y1);
//    bug(y);
//    bug(y2);

    if (x1 <= x && x <= x2 && y1 <= y && y <= y2) {
        return cout << "YES" << endl, 0;
    }

    cout << "NO" << endl;
    return 0;
}

int main() {
//    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;

    while (t--) {
//            cout << endl;
        solve();
//        cout << endl;
    }
    return 0;
}