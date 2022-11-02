#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll da, db, g;
typedef pair <ll, ll> pll;
inline void go(ll &x, ll &y, vector <pll> &v) {
    if (x != y) v.emplace_back(x * da + g, y * da + g);
    x = 2 * y - x;
}

ll a[4], b[4];
ll solve(ll *a, vector <pll> &v) {
    while (1) {
        sort(a, a + 4);
        ll d = a[3] - a[0];
        if (d <= 1) {
            ll x = a[0];
            if (x & 1) {
                for (int i = 0; i < 4; i ++) {
                    if (a[i] != x) break;
                    go(a[i], a[3], v);
                }
                x ++;
                sort(a, a + 4);
            }
            return x;
        }
        ll d2 = min(a[1] - a[0], a[3] - a[1]);
        ll d3 = min(a[2] - a[0], a[3] - a[2]);
        while (max(d2, d3) <= d / 5) {
            if (d2 <= d3) {
                if (a[1] - a[0] == d2) {
                    if (a[2] - a[0] == d3) go(a[1], a[0], v), go(a[1], a[2], v);
                    else go(a[1], a[2], v), go(a[1], a[3], v);
                }
                else if (a[2] - a[0] == d3) go(a[1], a[2], v), go(a[1], a[0], v);
                else go(a[1], a[3], v), go(a[1], a[2], v);
            }
            else if (a[1] - a[0] == d2) {
                if (a[2] - a[0] == d3) go(a[2], a[0], v), go(a[2], a[1], v);
                else go(a[2], a[1], v), go(a[2], a[0], v);
            }
            else if (a[2] - a[0] == d3) go(a[2], a[1], v), go(a[2], a[3], v);
            else go(a[2], a[3], v), go(a[2], a[1], v);
            d2 = min(a[1] - a[0], a[3] - a[1]);
            d3 = min(a[2] - a[0], a[3] - a[2]);
        }
        sort(a, a + 4);
        for (int i = 1; i <= 2; i ++) {
            if (min(a[i] - a[0], a[3] - a[i]) > d / 5) {
                if (a[i] - a[0] > a[3] - a[i]) for (int j = i + 1; j < 4; j ++) go(a[j], a[i], v);
                else for (int j = 0; j < i; j ++) go(a[j], a[i], v);
                break;
            }
        }
    }
}

int main() {
    for (int i = 0; i < 4; i ++) scanf("%I64d", &a[i]);
    for (int i = 0; i < 4; i ++) scanf("%I64d", &b[i]);

    if (a[0] == a[1] && a[1] == a[2] && a[2] == a[3]) {
        for (int i = 0; i < 4; i ++) if (b[i] != a[0]) return puts("-1"), 0;
        puts("0"); return 0;
    }

    for (int i = 1; i < 4; i ++) da = __gcd(da, a[i] - a[0]), db = __gcd(db, b[i] - b[0]);
    da = abs(da), db = abs(db);
    if (da != db) return puts("-1"), 0;
    g = (a[0] % da + da) % da;
    if ((b[0] % db + db) % db != g) return puts("-1"), 0;
    for (int i = 0; i < 4; i ++) a[i] = (a[i] - g) / da, b[i] = (b[i] - g) / db;
    int cnt = 0;
    for (int i = 0; i < 4; i ++) if ((a[i] ^ b[i]) & 1) cnt += ((a[i] & 1) << 1) - 1;
    if (cnt) return puts("-1"), 0;
    vector <pll> v, w;
    ll x = solve(a, v), y = solve(b, w);
    vector <pll> &p = y > x ? v : w;
    if (x > y) swap(x, y), swap(a, b);
    ll d = y - x >> 1;
    while (a[3] - a[0] <= d) {
        go(a[2], a[0], p), go(a[1], a[3], p);
        sort(a, a + 4);
    }
    while (1) {
        ll del = a[3] - a[0];
        while (del <= d) {
            for (int i = 0; i < 3; i ++) go(a[i], a[3], p);
            for (int i = 1; i < 4; i ++) go(a[i], a[0], p);
            d -= del;
        }
        if (del == 1) break;
        go(a[0], a[1], p), go(a[3], a[2], p);
        sort(a, a + 4);
    }
    reverse(w.begin(), w.end());
    printf("%d\n", int(v.size() + w.size()));
    for (auto x : v) printf("%I64d %I64d\n", x.first, x.second);
    for (auto x : w) printf("%I64d %I64d\n", 2 * x.second - x.first, x.second);

    return 0;
}