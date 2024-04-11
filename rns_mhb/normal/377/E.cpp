#include <bits/stdc++.h>
using namespace std;
#define N 200010

typedef long long ll;
typedef long double ld;

struct Line {
    ll m, b;
    Line(ll mm = 0, ll bb = 0) : m(mm), b(bb) {}
    void in() {scanf("%I64d %I64d", &m, &b);}
    bool operator < (Line &L) const {
        if (b == L.b) return m > L.m;
        return b < L.b;
    }
    ld get(ll x) {
        return 1.0 * m * x + b;
    }
} line[N];
struct ConvexHull {
    int sz;
    vector <Line> hull;
    ConvexHull(int maxSize) {
        hull = vector <Line> (maxSize + 1);
        sz = 0;
    }
    bool isBad(int l1, int l2, int l3) {
        ld left = 1.0 * (hull[l3].b - hull[l1].b) / (hull[l1].m - hull[l3].m);
        ld right = 1.0 * (hull[l1].b - hull[l2].b) / (hull[l2].m - hull[l1].m);
        return left < right;
    }
    void addLine(ll m, ll b) {
        hull[sz++] = Line(m, b);
        while (sz > 2 && isBad(sz - 3, sz - 2, sz - 1)) {
            hull[sz-2] = hull[sz-1];
            sz --;
        }
    }
    ld query(ll x) {
        int le = 0, ri = sz - 1;
        while (le < ri) {
            int mi = (le + ri) / 2;
            if (hull[mi].get(x) <= hull[mi + 1].get(x)) le = mi + 1;
            else ri = mi;
        }
        return hull[le].get(x);
    }
} C = ConvexHull(N);

int n;
ll s;

ll calc_position(ll s) {
    ll le = 0, ri = 1e16 + 10;
    while (le < ri) {
        ll mi = le + ri >> 1;
        if (C.query(mi) >= s) ri = mi;
        else le = mi + 1;
    }
    return le;
}

int main() {
    scanf("%d %I64d", &n, &s);
    for (int i = 0; i < n; i ++) line[i].in();
    sort(line, line + n);
    int k = 0;
    for (int i = 1; i < n; i ++) {
        if (line[i].b == line[k].b || line[i].m < line[k].m) continue;
        line[++k] = line[i];
    }
    C.addLine(line[0].m, 0);
    for (int i = 1; i <= k; i ++) {
        ll t = calc_position(line[i].b);
        C.addLine(line[i].m, C.query(t) - line[i].b - line[i].m * t);
    }
    printf("%I64d\n", calc_position(s));

    return 0;
}