#include <bits/stdc++.h>

#define f first
#define s second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const int N = 200000 + 13;
const int M = 998244353;
const int B = 600;
const ld e = 1e-9;
/*
1
0.2 0.2 0.6 0.2

1
0.4998 0.4998 0.0004 0.1666
*/

ld calc(ld a, ld b, ld c, ld v) {

    if(a + b <= e)
        return 1;

    ld res = 1;

    if(a > e) {
        ld x = min(a, v);
        if(b > e)
            res += a * calc(a - x, b + x / 2, c + x / 2, v);
        else
            res += a * calc(a - x, 0, c + x, v);
    }

    if(b > e) {
        ld x = min(b, v);
        if(a > e)
            res += b * calc(a + x / 2, b - x, c + x / 2, v);
        else
            res += b * calc(0, b - x, c + x, v);
    }

//    cout << "calc " << a << ' ' << b << ' ' << c<< ' ' << v << ' ' << res << endl;

    return res;
}

void solve() {
    ld a, b, c, v;
    cin >> a >> b >> c >> v;

    cout << setprecision(20) << fixed << calc(a, b, c, v) << endl;
}


signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();


}