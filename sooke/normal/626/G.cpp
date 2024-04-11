#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const long double eps = 1e-10;
const int N = 4e5 + 5;

int n, m, q, cnt, p[N], a[N], b[N];
long double ans;

struct Element {
    int i, d;
    
    inline long double get() {
        return 1.0L * p[i] * a[i] / (a[i] + b[i] - d) / (a[i] + b[i] - d + 1);
    }
};

bool operator <(Element u, Element v) {
    if (std::abs(u.get() - v.get()) < eps) { return u.i < v.i; }
    return u.get() < v.get();
}

std::set<Element> min, max;

void update() {
    if (!min.empty()) {
        Element u = *min.begin();
        int i = u.i;
        max.erase((Element) {i, 0});
        min.erase((Element) {i, 1});
        ans -= u.get(); b[i]--; cnt--;
        max.insert((Element) {i, 0});
        if (b[i] > 0) { min.insert((Element) {i, 1}); }
    }
    while (!max.empty() && cnt < m) {
        Element u = *max.rbegin();
        int i = u.i;
        max.erase((Element) {i, 0});
        min.erase((Element) {i, 1});
        ans += u.get(); b[i]++; cnt++;
        min.insert((Element) {i, 1});
        if (b[i] < a[i]) { max.insert((Element) {i, 0}); }
    }
}

int main() {
    n = read(); m = read(); q = read();
    for (int i = 0; i < n; i++) { p[i] = read(); }
    for (int i = 0; i < n; i++) { a[i] = read(); }
    for (int i = 0; i < n; i++) { max.insert((Element) {i, 0}); }
    update();
    for (; q; q--) {
        int opt = read(), i = read(); i--;
        max.erase((Element) {i, 0});
        min.erase((Element) {i, 1});
        ans -= 1.0L * p[i] * b[i] / (a[i] + b[i]);
        a[i] += opt == 1 ? 1 : -1;
        ans += 1.0L * p[i] * b[i] / (a[i] + b[i]);
        if (b[i] > 0) {
            b[i]--; cnt--;
            ans -= ((Element) {i, 0}).get();
        }
        if (b[i] < a[i]) { max.insert((Element) {i, 0}); }
        if (b[i] > 0) { min.insert((Element) {i, 1}); }
        update();
        printf("%.6f\n", (double) ans);
    }
    return 0;
}