#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll md = 1e9 + 7;
typedef long double ld;
const int N = 1e5 + 34;
const ld EPS = 1e-4;

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    int n, p1, p2, p3, t1, t2, ans = 0;
    int l, r, l1, r1, t;
    cin >> n >> p1 >> p2 >> p3 >> t1 >> t2;
    cin >> l >> r;
    ans += p1 * (r - l);
    for (int i = 1; i < n; i++) {
        l1 = l;
        r1 = r;
        cin >> l >> r;
        ans += p1 * (r - l);
        t = l - r1;
        if (t <= t1)
            ans += p1 * t;
        else if (t <= t1 + t2)
            ans += t1 * p1 + (t - t1) * p2;
        else
            ans += t1 * p1 + t2 * p2 + (t - t1 - t2) * p3;
    }

    cout << ans;

    return 0;
}