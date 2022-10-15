#include <bits/stdc++.h>
 
inline int read() {
    char c, _c; int x; for (c = _c = getchar(); !isdigit(c); c = getchar()) { _c = c; }
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return _c == '-' ? -x : x;
}
 
const long double eps = 1e-10, Eps = 1e-8, pi = std::acos(-1.0L);
const int N = 2e5 + 5, V = 4e7 + 5;
 
int n, m, rb[N];
long long k, fuck, shit;
std::pair<int, int> p[N];
long double ox, oy, a[N], b[N], c[N];
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
 
bool check(long double mid) {
    long long res = 0; m = 0;
    long long inner = 0;
    for (int i = 0; i < n; i++) {
        long double x = a[i], y = b[i];
        dis[i] = std::sqrt(x * x + y * y);
        if (dis[i] < mid + eps) {
            inner++;
        } else {
            s[i] = std::atan2(y, x) - std::acos(mid / dis[i]);
            t[i] = std::atan2(y, x) + std::acos(mid / dis[i]);
            if (s[i] > t[i]) { std::swap(s[i], t[i]); }
            if (s[i] < -pi + eps) { s[i] += pi * 2; }
            if (t[i] > pi) { t[i] -= pi * 2; }
            if (s[i] > t[i]) { std::swap(s[i], t[i]); }
            s[i] += eps; t[i] -= eps;
            tb[m++] = s[i]; tb[m++] = t[i];
        }
    }
    std::sort(tb, tb + m);
    for (int i = 0; i < n; i++) {
        if (dis[i] < mid + eps) {
            p[i] = {m, i}; continue;
        }
        p[i] = {std::upper_bound(tb, tb + m, s[i]) - tb - 1, i};
        rb[i] = std::upper_bound(tb, tb + m, t[i]) - tb;
    }
    std::sort(p, p + n);
    tr.reset(m);
    res = (n - inner) * (n - inner - 1ll) / 2;
    for (int i = 0; i < n; i++) {
        if (p[i].first == m) { break; }
        res -= tr.query(p[i].first, rb[p[i].second]);
        tr.modify(rb[p[i].second], 1);
    }
    res += inner * (inner - 1ll) / 2;
    res += inner * (n - inner);
    return res >= k;
}
 
int main() {
    scanf("%d%lld", &n, &k);
    std::vector<long double> vec;
    for (int i = 0; i < n; i++) {
        a[i] = read(); b[i] = read();
        if (a[i] == 0 && b[i] == 0) {
            fuck++;
        } else if (a[i] != 0) {
            if (a[i] > 0) {
                vec.push_back(std::atan2(b[i], a[i]));
            } else {
                vec.push_back(std::atan2(-b[i], -a[i]));
            }
        } else {
            if (b[i] > 0) {
                vec.push_back(std::atan2(b[i], a[i]));
            } else {
                vec.push_back(std::atan2(-b[i], -a[i]));
            }
        }
    }
    std::sort(vec.begin(), vec.end());
    for (int i = 0, j; i < vec.size(); i = j) {
        for (j = i; j < n && std::abs(vec[i] - vec[j]) < eps; j++);
        shit += (j - i) * (j - i - 1ll) / 2;
    }
    shit += fuck * (fuck - 1ll) / 2;
    shit += fuck * (n - fuck);
    if (shit >= k) { printf("0.000000\n"); return 0; }
    for (long double l = Eps, r = 2e4, mid; l <= r; ) {
        mid = (l + r) / 2;
        if (check(mid)) {
            r = mid - Eps;
            ans = mid;
        } else {
            l = mid + Eps;
        }
    }
    printf("%.6f\n", (double) ans);
    return 0;
}