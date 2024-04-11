#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const double eps = 1e-11, Eps = 1e-7;

const int N = 1e6 + 5;

int n;
double ans, sum, lstsum;

struct Element {
    int p, t;
    double l, r;
} a[N];

bool equal(long double x, long double y) {
    return std::abs(x - y) < eps;
}
bool compared(const Element &u, const Element &v) {
    return 1.0L * u.p / u.t > 1.0L * v.p / v.t;
}
bool comparep(const Element &u, const Element &v) {
    return u.p < v.p;
}

bool check(double mid) {
    double max = -1e9;
    for (int i = 0, j; i < n; i = j) {
        for (j = i; j < n && a[i].p == a[j].p; j++) {
            if (max > a[j].p * (1 - mid * a[j].r / sum)) {
                return false;
            }
        }
        for (j = i; j < n && a[i].p == a[j].p; j++) {
            max = std::max(max, a[j].p * (1 - mid * a[j].l / sum));
        }
    }
    return true;
}

int main() {
    n = read();
    for (int i = 0; i < n; i++) { a[i].p = read(); }
    for (int i = 0; i < n; i++) { a[i].t = read(); }
    std::sort(a, a + n, compared);
    for (int i = 0, j; i < n; i = j) {
        lstsum = sum;
        for (j = i; j < n && equal(1.0L * a[i].p / a[i].t, 1.0L * a[j].p / a[j].t); j++) {
            sum += a[j].t;
        }
        for (j = i; j < n && equal(1.0L * a[i].p / a[i].t, 1.0L * a[j].p / a[j].t); j++) {
            a[j].l = lstsum + a[j].t; a[j].r = sum;
        }
    }
    std::sort(a, a + n, comparep);
    for (double l = 0, r = 1, mid; l <= r; ) {
        mid = (l + r) / 2;
        if (check(mid)) {
            l = mid + Eps; ans = mid;
        } else {
            r = mid - Eps;
        }
    }
    printf("%.6f\n", ans);
    return 0;
}