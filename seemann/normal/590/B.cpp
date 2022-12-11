#include <cassert>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <string>
#include <iomanip>
#include <vector>
#include <set>
#include <map>
#include <cassert>
#include <queue>

using namespace std;

#define FOR(a, b) for (int a = 0; a < (b); ++a)
#define clr(a) memset(a, 0, sizeof(a))
#define pb(i) push_back(i)
#define forab(i, a, b) for(int i = int(a); i < int(b); ++i)
#define forba(i, b, a) for(int i = int(b) - 1; i >= int(a); --i)
#define forn(i, n) forab(i, 0, n)
#ifdef LOCAL
#define debug(a) cerr << #a << ": " << a << '\n';
#else
#define debug(a)
#endif

typedef long long ll;
typedef long double ldb;

const int INF = 1e9;
const ldb EPS = 1e-9;
const ldb PI = acos(-1.0);
const int MAXN = 1e5;

struct point {
    ldb x, y;
    point () :x(), y() {};
    point(ldb _x, ldb _y) : x(_x), y(_y) {}
    point operator + (const point & o) const {
        return point(x + o.x, y + o.y);
    }
    point operator - (const point & o) const {
        return point(x - o.x, y - o.y);
    }
    ldb len2() {
        return x * x + y * y;
    }
    ldb len() {
        return sqrt(x * x + y * y);
    }
    point operator * (ldb d) const {
        return point(x * d, y * d);
    }
    void read() {
        cin >> x >> y;
    }
    void print() {
        cerr << x << ' ' << y << '\n';

    }
};
int main() {
#ifdef LOCAL
    freopen("b.in", "r", stdin);
    //freopen("", "w", stdout);
    //freopen("", "w", stderr);
#endif
    point st, en;
    st.read();
    en.read();
    ll vm, t;
    cin >> vm >> t;
    point v, w;
    v.read();
    w.read();
    point ns = st + v * t;
    ldb l, r;
    if ((en - ns).len() / vm > t) {
        st = ns;
        l = t, r = 1e18;
        v = w;
    } else {
        l = 0, r = t;
        t = 0;
    }
    FOR(_, 150) {
        ldb m = (l + r) / 2;
        if ((st + v * (m - t) - en).len() / vm > m) 
            l = m;
        else
            r = m;
    }
    cout << fixed << setprecision(15) << double(r) << '\n';
    
    return 0;
}