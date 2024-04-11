#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <map>
#include <set>
#include <ctime>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second

typedef long long ll;

int mod = 1000000007;

int cnt = 0;

ll query(ll x1, ll y1, ll x2, ll y2, ll k, ll X1, ll Y1, ll X2, ll Y2, ll lvl, ll add = 0) {
    if (k <= add) {
        return 0;
    }
    ++cnt;
    if (x2 <= X1 || X2 <= x1 || y2 <= Y1 || Y2 <= y1) {
        return 0;
    }
//    ++cnt;
    if ((x1 <= X1 && X2 <= x2) || (y1 <= Y1 && Y2 <= y2)) {
        X1 = max(X1, x1);
        X2 = min(X2, x2);
        Y1 = max(Y1, y1);
        Y2 = min(Y2, y2);
        
        k = min(ll(k), ll(add) + ll(1ll << lvl));
//    cerr << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
//    cerr << X1 << " " << Y1 << " " << X2 << " " << Y2 << endl;
//    cerr << add << endl;
        ll res = k * ll(k + 1) / 2;
        res -= add * ll(add + 1) / 2;
        res %= mod;
//        cerr << res << endl;
        res *= min(X2 - X1, Y2 - Y1);
//        cerr << res << endl;
        return res % mod;
    }
    --lvl;
    ll MX = (ll(X1) + ll(X2)) / 2;
    ll MY = (ll(Y1) + ll(Y2)) / 2;
    return (query(x1, y1, x2, y2, k, X1, Y1, MX, MY, lvl, add) +
           query(x1, y1, x2, y2, k, X1, MY, MX, Y2, lvl, add + (1ll << lvl)) +
           query(x1, y1, x2, y2, k, MX, Y1, X2, MY, lvl, add + (1ll << lvl)) +
           query(x1, y1, x2, y2, k, MX, MY, X2, Y2, lvl, add)) % mod;
}

int main() {
    int q;
    cin >> q;
    forn (i, q) {
        ll x1, y1, x2, y2, k;
        cin >> x1 >> y1 >> x2 >> y2 >> k;
//        x1 = y1 = 1;
//        k = x2 = y2 = 1000000000;
//        k += rand();
        --x1;
        --y1;
//        cnt = 0;
        cout << query(x1, y1, x2, y2, k, 0, 0, 1 << 30, 1 << 30, 30) << endl;
//        cerr << cnt << endl;
    }
    return 0;
}