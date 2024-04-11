#include <bits/stdc++.h>
#define sz(x) (int((x).size()))
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
typedef long long ll;

typedef double real;
typedef std::pair<real, real> P;

const int maxn = 100*1000+5;
const real inf = 1e20;

int n;
P a, b, t, p[maxn];
std::pair<real, int> alist[3], blist[3];
bool seen[maxn];
real ans, last = inf;

void sub(P &a, P b) {
    a.first -= b.first;
    a.second -= b.second;
}
real sqr(real a) {
    return a*a;
}
real dist(P a, P b) {
    return std::sqrt(sqr(a.first - b.first) + sqr(a.second - b.second));
}

int main() {
    scanf("%lf%lf%lf%lf%lf%lf%d", &a.first, &a.second, &b.first, &b.second, &t.first, &t.second, &n);
    for (int i = 0; i < 3; i++) {
        alist[i] = { inf, 0 };
        blist[i] = { inf, 0 };
    }
    for (int i = 0; i < n; i++) {
        scanf("%lf%lf", &p[i].first, &p[i].second);
        alist[2] = { dist(p[i], a) - dist(p[i], t), i}; std::sort(alist, alist+3);
        blist[2] = { dist(p[i], b) - dist(p[i], t), i}; std::sort(blist, blist+3);
        ans += dist(p[i], t) * 2;
    }

    domin(last, ans + alist[0].first);
    domin(last, ans + blist[0].first);
    domin(last, ans + blist[0].first + alist[1].first);
    domin(last, ans + blist[1].first + alist[0].first);
    if (alist[0].second != blist[0].second) domin(last, ans + blist[0].first + alist[0].first);
    printf("%.8lf\n", last);

}