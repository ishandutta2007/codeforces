#include <bits/stdc++.h>
using namespace std;

#define N 300100

const double eps = 1e-6;

struct pnt{
    double x, y;
    pnt(double x = 0, double y = 0) : x(x), y(y) {}
    pnt operator + (const pnt &p) const {
        return pnt(x + p.x, y + p.y);
    }
    pnt operator - (const pnt &p) const {
        return pnt(x - p.x, y - p.y);
    }
    pnt operator * (const double &d) const {
        return pnt(x * d, y * d);
    }
    pnt operator / (const double &d) const {
        return pnt(x / d, y / d);
    }
    double operator ^ (const pnt &p) const {
        return x * p.y - y * p.x;
    }
    bool operator < (const pnt &p) const {
        return abs(y - p.y) > eps ? y < p.y : x < p.x;
    }
    bool operator != (const pnt &p) const {
        return (*this) < p || p < (*this);
    }
    void in() {scanf("%lf %lf", &x, &y);}
} p[N];

int n, q, f[N];
double ans[N];

struct seg{
    pnt st, ed;
    seg(pnt s = pnt(), pnt e = pnt()) : st(s), ed(e) {}
    pnt intersect_y(double y) {
        assert(st.y - eps < y && y < ed.y + eps);
        return (ed - st) * (y - st.y) / (ed.y - st.y) + st;
    }
    void convert(double &a, double &b, double &c) {
        if (abs(st.x - ed.x) < eps) {
            a = b = c = 0;
            return;
        }
        bool rev = 0;
        if (st.x > ed.x) rev = 1, swap(st, ed);
        double d = st.x * (ed.y - st.y) + 2 * st.y * (st.x - ed.x);
        a = (ed.y - st.y);
        b = -(st.x * (ed.y - st.y) + d);
        c = d * st.x;
        a /= 2 * (ed.x - st.x);
        b /= 2 * (ed.x - st.x);
        c /= 2 * (ed.x - st.x);
        if (rev) {
            a = -a, b = -b, c = -c;
            swap(st, ed);
        }
    }
    double size() {
        return (st.y + ed.y) * (ed.x - st.x) / 2;
    }
};

vector <seg> L, R, M;

double rlt[N];

bool cmp(double x, double y) {
    return x < y - eps;
}

vector <seg> ins[N], era[N];
vector <int> id[N];

void calc(vector <seg> &L, vector <seg> &R) {
    vector <double> X;
    for (auto s : L) X.push_back(s.st.x), X.push_back(s.ed.x);
    for (auto s : R) X.push_back(s.st.x), X.push_back(s.ed.x);
    for (int i = 1; i <= q; i ++) X.push_back(f[i]);
    sort(X.begin(), X.end(), cmp);
    X.erase(unique(X.begin(), X.end(), [&](double x, double y) {return abs(x - y) < eps;}), X.end());
    int m = X.size();
    for (int i = 0; i < m; i ++) ins[i].clear(), era[i].clear(), id[i].clear();
    for (auto s : L) {
        int c = lower_bound(X.begin(), X.end(), s.st.x, cmp) - X.begin();
        int d = lower_bound(X.begin(), X.end(), s.ed.x, cmp) - X.begin();
        if (c > d) swap(c, d);
        ins[c].push_back(s), era[d].push_back(s);
    }
    for (auto s : R) {
        swap(s.st, s.ed);
        int c = lower_bound(X.begin(), X.end(), s.st.x, cmp) - X.begin();
        int d = lower_bound(X.begin(), X.end(), s.ed.x, cmp) - X.begin();
        if (c > d) swap(c, d);
        ins[c].push_back(s), era[d].push_back(s);
    }
    for (int i = 1; i <= q; i ++) {
        id[lower_bound(X.begin(), X.end(), f[i], cmp) - X.begin()].push_back(i);
    }
    double a = 0, b = 0, c = 0, S = 0;
    for (int i = 0; i < m; i ++) {
        double aa, bb, cc, x = X[i];
        for (auto s : ins[i]) {
            s.convert(aa, bb, cc);
            a += aa, b += bb, c += cc;
        }
        for (auto s : era[i]) {
            s.convert(aa, bb, cc);
            a -= aa, b -= bb, c -= cc;
            S += s.size();
        }
        for (auto j : id[i]) {
            rlt[j] = S + a * x * x + b * x + c;
        }
    }
}

int main() {
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; i ++) p[i].in();
    int low = min_element(p + 1, p + n + 1) - p;
    int high = max_element(p + 1, p + n + 1) - p;
    for (int i = low, j; i != high; i = j) {
        j = i + 1; if (j > n) j -= n;
        R.emplace_back(p[i], p[j]);
    }
    for (int i = high, j; i != low; i = j) {
        j = i + 1; if (j > n) j -= n;
        L.emplace_back(p[j], p[i]);
    }
    reverse(L.begin(), L.end());
    auto itl = L.begin(), itr = R.begin();
    pnt lst = p[low];
    bool rev = 0;
    while (itl != L.end() && itr != R.end()) {
        pnt mid;
        if (itl -> ed < itr -> ed) {
            mid = (itr -> intersect_y(itl -> ed.y) + itl -> ed) / 2;
            if (mid < itl -> ed) rev = 1;
            itl ++;
        }
        else {
            mid = (itl -> intersect_y(itr -> ed.y) + itr -> ed) / 2;
            if (itr -> ed < mid) rev = 1;
            itr ++;
        }
        if (lst != mid) M.emplace_back(lst, mid), lst = mid;
    }
    double S = 0;
    for (int i = 1; i <= n; i ++) S += p[i] ^ p[i%n+1];
    S = abs(S) / 2;
    if (rev) swap(L, R);
    for (int i = 1; i <= q; i ++) scanf("%d", &f[i]), ans[i] = S;
    calc(L, M);
    for (int i = 1; i <= q; i ++) ans[i] -= rlt[i];
    calc(M, R);
    for (int i = 1; i <= q; i ++) ans[i] += rlt[i];
    for (int i = 1; i <= q; i ++) printf("%.6lf\n", ans[i]);

    return 0;
}