#include <bits/stdc++.h>
using namespace std;

#define N 2525

typedef long long ll;

struct pnt{
    ll x, y;
    pnt(ll x = 0, ll y = 0) : x(x), y(y) {}
    pnt operator + (const pnt &p) {
        return pnt(x + p.x, y + p.y);
    }
    pnt operator - (const pnt &p) {
        return pnt(x - p.x, y - p.y);
    }
    ll operator ^ (const pnt &p) const {
        return x * p.y - y * p.x;
    }
    ll operator & (const pnt &p) {
        return x * p.x + y * p.y;
    }
    int sgn() const {
        if (y > 0 || (y == 0 && x > 0)) return 0;
        return 1;
    }
    bool operator < (const pnt &p) const {
        int c = sgn(), pc = p.sgn();
        if (c != pc) return c < pc;
        return ((*this) ^ p) > 0;
    }
    void in() {scanf("%I64d %I64d", &x, &y);}
} p[N], q[N];

int n;

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i ++) p[i].in();
    ll ans = 0;
    for (int i = 0; i < n; i ++) {
        int m = 0;
        for (int j = 0; j < n; j ++) if (i != j) q[m++] = p[j] - p[i];
        sort(q, q + m);
        ans += 1ll * m * (m - 1) * (m - 2) / 6;
        for (int j = 0, k = 1; j < m; j ++) {
            if (k == m) k = 0;
            while ((q[j] ^ q[k]) > 0) {
                k ++; if (k == m) k = 0;
            }
            int c = k - j - 1;
            if (c < 0) c += m;
            ans -= 1ll * c * (c - 1) / 2;
        }
    }
    printf("%I64d\n", ans * (n - 4) / 2);

    return 0;
}