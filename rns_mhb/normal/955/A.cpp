#include <bits/stdc++.h>
using namespace std;

const double INF = 1e18;
template<class T> void chkmin(T &a, T b) { if (a > b) a = b; }
int hh, mm;
int h, d, c, n;
int t = 60 * 20;
double ans;

int main() {
    scanf("%d %d", &hh, &mm);
    scanf("%d %d %d %d", &h, &d, &c, &n);
    int now = 60 * hh + mm;
    ans = INF;
    if (now < t) {
        ans = c * (ceil(1.0 * h / n));
    }
    if (now <= t) {
        chkmin(ans, ceil(1.0 * ((t - now) * d + h) / n) * c * 0.8);
    }
    else {
        chkmin(ans, ceil(1.0 * h / n) * c * 0.8);
    }
    printf("%.6lf\n", ans);
    return 0;
}