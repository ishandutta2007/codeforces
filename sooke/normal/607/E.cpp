#include <bits/stdc++.h>

long double read() {
    int x;
    scanf("%d", &x);
    return x / 1000.0L;
}

const long double eps = 1e-9, Eps = 1e-7;
const int N = 1e5 + 5, V = 4e7 + 5;

int n, m, q, rb[N], vol, stc[V];
std::pair<int, int> p[N];
long double k, ox, oy, a[N], b[N], cx[N], cy[N];
long double ans, dis[N], s[N], t[N], tb[N];

struct FenwickTree {
    int f[N];

    void reset(int n) { memset(f, 0, (n + 1) * 4); }
    void modify(int u, int x) {
        for (int i = u; i <= m; i += i & -i) { f[i] += x; }
    }
    int query(int u) {
        int res = 0;
        for (int i = u; i >= 1; i ^= i & -i) { res += f[i]; }
        return res;
    }
    int query(int l, int r) {
        if (l >= r) { return 0; }
        return query(r) - query(l);
    }
} tr;

long double get(int i, int j) {
    long double x = (b[i] - b[j]) / (a[j] - a[i]), y = a[i] * x + b[i];
    return std::sqrt((x - ox) * (x - ox) + (y - oy) * (y - oy));
}

bool check(long double k, bool typ) {
    int res = 0; m = 0;
    for (int i = 0; i < n; i++) {
        long double x = cx[i] - ox, y = cy[i] - oy;
        if (dis[i] > k * k - eps) { continue; }
        if (std::abs(dis[i]) < eps) {
            s[i] = std::atan2(a[i], 1);
            t[i] = std::atan2(-a[i], -1);
        } else {
            long double z = std::sqrt(k * k / dis[i] - 1);
            s[i] = std::atan2(y - x * z, x + y * z);
            t[i] = std::atan2(y + x * z, x - y * z);
        }
        if (s[i] > t[i]) { std::swap(s[i], t[i]); }
        s[i] += eps; t[i] -= eps;
        tb[m++] = s[i]; tb[m++] = t[i];
    }
    std::sort(tb, tb + m);
    for (int i = 0; i < n; i++) {
        if (dis[i] > k * k - eps) { p[i] = {m, i}; continue; }
        p[i] = {std::upper_bound(tb, tb + m, s[i]) - tb - 1, i};
        rb[i] = std::upper_bound(tb, tb + m, t[i]) - tb;
    }
    std::sort(p, p + n);
    if (!typ) {
        tr.reset(m);
        for (int i = 0; i < n; i++) {
            if (p[i].first == m) { break; }
            res += tr.query(p[i].first, rb[p[i].second]);
            tr.modify(rb[p[i].second], 1);
            if (res >= q) { return false; }
        }
    } else {
        for (int i = 0; i < n; i++) {
            if (p[i].first == m) { break; }
            for (; vol > 0 && rb[stc[vol]] <= p[i].first; vol--);
            stc[++vol] = p[i].second;
            for (int i = vol - 1; i > 0; i--) {
                if (rb[stc[i]] > rb[stc[i + 1]]) { break; }
                double tmp = get(stc[i], stc[i + 1]);
                ans += tmp; res++;
                std::swap(stc[i], stc[i + 1]);
            }
        }
        ans += (q - res) * k;
    }
    return true;
}

int main() {
    scanf("%d", &n);
    ox = read(); oy = read(); scanf("%d", &q);
    int pass = 0;
    for (int i = 0; i < n; i++) {
        a[i] = read(); b[i] = read();
        if (std::abs(a[i]) < eps) {
            cx[i] = ox; cy[i] = b[i];
        } else {
            long double _a = -1 / a[i], _b = oy - _a * ox;
            cx[i] = (_b - b[i]) / (a[i] - _a);
            cy[i] = a[i] * cx[i] + b[i];
        }
        dis[i] = (ox - cx[i]) * (ox - cx[i]) + (oy - cy[i]) * (oy - cy[i]);
        if (dis[i] < eps) { pass++; }
    }
    if (pass * (pass - 1ll) / 2 >= q) { printf("0.000000\n"); return 0; }
    for (long double l = Eps, r = 21e8, mid; l <= r; ) {
        mid = (l + r) / 2;
        if (check(mid, false)) {
            l = mid + Eps; k = mid;
        } else {
            r = mid - Eps;
        }
    }
    check(k, true);
    printf("%.6f\n", (double) ans);
    return 0;
}