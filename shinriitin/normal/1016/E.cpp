#include <bits/stdc++.h>

const double eps = 1e-9;

const int max_N = (int) 2e5 + 21;

int Sy, a, b, n, q, sum[max_N];

std::pair<int, int> seg[max_N];

double calcX(double x1, double y1, double x2, double y2) {
    return (x2 * y1 - x1 * y2) / (y1 - y2);
}

int getPos(double x) {
    return std::upper_bound(seg + 1, seg + 1 + n, std::make_pair(int(ceil(x - eps)), INT_MIN)) - seg - 1;
}


double calcDX(int i, double x1, double x2) {
    if (!i) return 0;
    x1 = std::max(x1, 1. * seg[i].first);
    x2 = std::min(x2, 1. * seg[i].second);
    return (x1 + eps < x2) ? x2 - x1 : 0;
}

void query() {
    int x, y;
    scanf("%d%d", &x, &y);
    double st = calcX(x, y, a, Sy);
    double ed = calcX(x, y, b, Sy);
    int s = getPos(st), t = getPos(ed);
    double ret;
    if (s == t) ret = calcDX(s, st, ed);
    else {
        ret = sum[t - 1] - sum[s];
        ret += calcDX(s, st, seg[s].second);
        ret += calcDX(t, seg[t].first, ed);
    }
    ret *= double (y - Sy) / y;
    printf("%.10f\n", ret);
}

int main() {
    scanf("%d%d%d%d", &Sy, &a, &b, &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d%d", &seg[i].first, &seg[i].second);
        sum[i] = sum[i - 1] + (seg[i].second - seg[i].first);
    }
    scanf("%d", &q);
    while (q--) query();
    return 0;
}