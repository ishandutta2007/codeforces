#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
const int mod = 1000000;
const ld eps = 1e-15;

int n, lastans;
ll m;

struct pnt{
    ld x, y;
    pnt (ld x = 0, ld y = 0) : x(x), y(y) {};
    pnt operator+ (const pnt &b) const { return pnt(x + b.x, y + b.y); }
    pnt operator- (const pnt &b) const { return pnt(x - b.x, y - b.y); }
    ld operator^ (const pnt &b) const { return x * b.y - y * b.x; }
    bool operator< (const pnt &b) const { return fabs(x - b.x) <= eps ? y < b.y : x < b.x; }
};

set<pnt> :: iterator l, r, t;

struct convex {
    set<pnt> hull;
    void init() {
        hull.clear();
        hull.insert(pnt(0, 0));
    }
    void insert(pnt p) {
        r = hull.lower_bound(p); l = r, l --;
        if (r != hull.end()) {
            if (((*r - p) ^ (*l - p)) <= eps) return;
            while (1) {
                t = r; r ++;
                if (r == hull.end()) break;
                if (((*r - p) ^ (*t - p)) <= eps) break;
                else hull.erase(t);
            }
        }
        while (1) {
            if (l == hull.begin()) break;
            t = l; l --;
            if (((*t - p) ^ (*l - p)) <= eps) break;
            else hull.erase(t);
        }
        hull.insert(p);
    }
    bool query(pnt p) {
        r = hull.lower_bound(pnt(p.x, 0));
        if (r == hull.end()) return 0;
        l = r, l --;
        return ((*r - p) ^ (*l - p)) <= eps;
    }
} cvx;

int main() {
    scanf("%d %I64d", &n, &m);
    cvx.init();
    for (int i = 1; i <= n; i ++) {
        int type, x, y;
        scanf("%d %d %d", &type, &x, &y);
        x = (x + lastans) % mod + 1;
        y = (y + lastans) % mod + 1;
        if (type == 1) cvx.insert(pnt(x,y));
        else if (cvx.query(pnt(1.0 * y / x, 1.0 * m / x))) {
            puts("YES");
            lastans = i;
        }
        else puts("NO");
    }
    return 0;
}