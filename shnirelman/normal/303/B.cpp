#include <bits/stdc++.h>

#define f first
#define s second
//#define x first
//#define y second
//#define int li
#define err if(debug_out)cout

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;
using pld = pair<ld, ld>;

const int INF = 1e9 + 13;
const li INF64 = 1e18 + 13;
const int N = 1e5 + 13;
const int LOGN = 20;
const int K = 22;
const int M = 998244353;//1e9 + 7;
//const int A = 26;
const ld eps = 1e-8;

mt19937 rnd(45768);

/*
*/

int get(int n, int x, int w) {
    if(w % 2 == 0) {
        if(x + w / 2 <= n && x - w / 2 >= 0)
            return x - w / 2;
        else if(x - w / 2 < 0)
            return 0;
        else
            return n - w;
    } else {
        if(x + w / 2 <= n && x - w / 2 - 1 >= 0)
            return x - w / 2 - 1;
        else if(x - w / 2 - 1 < 0)
            return 0;
        else
            return n - w;
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, x, y, a, b;
    cin >> n >> m >> x >> y >> a >> b;

    int g = __gcd(a, b);

    a /= g;
    b /= g;

    int w = min(n / a, m / b) * a;
    int h = min(n / a, m / b) * b;

    int x1 = get(n, x, w);
    int y1 = get(m, y, h);

    cout << x1 << ' ' << y1 << ' ' << x1 + w << ' ' << y1 + h << endl;
}