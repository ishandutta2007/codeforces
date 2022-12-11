#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;
typedef long long ll;
typedef long double ld;

struct mT{
    ll x, y, t;
    ld p;
};

bool cmp(const mT &a, const mT &b) {
    return a.t < b.t;
}

ll n;
ld mx, ans[3000], res;
mT a[3000];

int main() {
    //freopen("a.in", "r", stdin);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i].x >> a[i].y >> a[i].t >> a[i].p;

    sort(a, a + n, cmp);

    res = ans[0] = a[0].p;

    for (int i = 1; i < n; i++) {
        mx = 0;
        for (int j = 0; j < i; j++)
            if ((a[i].x - a[j].x) * (a[i].x - a[j].x) + (a[i].y - a[j].y) * (a[i].y - a[j].y) <= (a[i].t - a[j].t) * (a[i].t - a[j].t))
                mx = max(mx, ans[j]);
        ans[i] = a[i].p + mx;
        res = max(res, ans[i]);
    }

    cout.precision(10);
    cout << fixed << res;

    return 0;
}