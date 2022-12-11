#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
vector <pair<ld, ld> > ans;
const int N = 1e6 + 34;

void go(ld &a, ld &b, ld d, ld e) {
    ld x, y, D;
    D = (a - b + e) * (a - b + e) - 4 * d + 4 * e * b;
    if (D < 0) D = 0;
    x = (a - b + e + sqrtl(D)) * 0.5;
    y = e - x;
    ans.push_back(make_pair(x, y));
    a += y;
    b += x;
}


ld mx[N], mn[N];

int main() {
    //freopen("a.in", "r", stdin);
    ld a = 0, b = 0;
    double x, y;
    int n;
    scanf("%d", &n);
    for (int i = 0 ;i < n; i++) {
        scanf("%lf", &x);
        mn[i] = x;
    }
    for (int i = 0; i < n; i++) {
        scanf("%lf", &y);
        mx[i] = y;
    }
    for (int i = 0; i < n; i++) {
        go(a, b, mn[i], mn[i] + mx[i]);
    }
    for (int i = 0; i < n; i++) {
        x = ans[i].first;
        printf("%.9f ", x);
    }
    printf("\n");
    for (int i = 0; i < n; i++) {
        y = ans[i].second;
        printf("%.9f ", y);
    }
    return 0;
}