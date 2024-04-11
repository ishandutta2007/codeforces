#include <bits/stdc++.h>
using namespace std;

#define N 1005

typedef long double ld;
typedef pair<ld, int> pdi;
const ld eps = 1e-8;
int sgn(ld x) { return x < -eps ? -1 : x > eps; }

struct pnt{
    ld x, y;
    pnt(ld x = 0, ld y = 0) : x(x), y(y) {}
    pnt operator+ (const pnt &b) const { return pnt(x + b.x, y + b.y); }
    pnt operator- (const pnt &b) const { return pnt(x - b.x, y - b.y); }
    ld operator^ (const pnt &b) const { return x * b.y - y * b.x; }
    void input() {
        double xx, yy;
        scanf("%lf %lf", &xx, &yy);
        x = xx, y = yy;
    }
    ld dist() {
        return sqrt(x * x + y * y);
    }
} p[N];

int n, q;
vector<pdi> inter;

ld solve(pnt x, pnt v) {
    inter.clear();
    for (int i = 0; i < n; i ++) {
        int f1 = sgn(v ^ (p[i] - x)), f2 = sgn(v ^ (p[i+1] - x));
        if (f1 == f2) continue;
        ld tmp = ((x - p[i]) ^ (p[i+1] - p[i])) / ((p[i+1] - p[i]) ^ v);
        if (f1 > f2) inter.push_back(pdi(tmp, f1 && f2 ? 2 : 1));
        else inter.push_back(pdi(tmp, f1 && f2 ? -2 : -1));
    }
    sort(inter.begin(), inter.end());
    ld rtn = 0;
    for (int i = 0, j = 0; i + 1 < inter.size(); i ++) {
        j += inter[i].second;
        if (j) rtn += inter[i+1].first - inter[i].first;
    }
    rtn *= v.dist();
    return rtn;
}

int main() {
    scanf("%d %d", &n, &q);
    for (int i = 0; i < n; i ++) p[i].input();
    p[n] = p[0];
    while (q --) {
        pnt x, v;
        x.input(), v.input();
        v = v - x;
        printf("%.10lf\n", (double)solve(x, v));
    }
    return 0;
}