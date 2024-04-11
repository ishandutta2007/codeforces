#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <utility>

using namespace std;

#define ll long long
#define updiv(a, b) ((a) % (b) == 0 ? (a) / (b) : (a) / (b) + 1)

ll n, a, r, m;
ll h[100005];
ll psum[100005], ssum[100005];

ll eval(ll left_hole, ll right_high)
{
    if (a + r <= m) {
        //printf("%lld %lld %lld\n", left_hole, right_high,
        //    left_hole * a + right_high * r);
        return left_hole * a + right_high * r;
    } else {
        ll mcnt = min(left_hole, right_high);
        left_hole -= mcnt, right_high -= mcnt;
        //printf("%lld %lld %lld\n", left_hole, right_high,
        //    left_hole * a + right_high * r);
        return mcnt * m + left_hole*a + right_high * r;
    }
}

ll fin(ll ht)
{
    ll l = 0, R = 0;
    for (int i = 1; i <= n; i++) {
        if (h[i] < ht) {
            l +=  ht - h[i];
        } else {
            R += h[i] - ht;
        }
    }
    return eval(l, R);
}

int main()
{
    scanf("%lld%lld%lld%lld", &n, &a, &r, &m);
    for (int i = 1; i <= n; i++) scanf("%lld", h + i);
    sort(h + 1, h + n + 1);
    for (int i = 1; i <= n; i++) {
        psum[i] = psum[i-1] + h[i];
    }
    for (int i = n; i >= 1; i--) {
        ssum[i] = ssum[i+1] + h[i];
    }
    ll ans = r * psum[n];
    for (int i = 1; i <= n; i++) {
        ll left_hole = h[i] * (ll)(i-1) - psum[i-1];
        ll right_high = ssum[i+1] - h[i] * (ll)(n-i);
        ans = min(ans, eval(left_hole, right_high));
    }
    ans  = min(ans, fin(psum[n] / n));
    ans  = min(ans, fin(updiv(psum[n], n)));
    printf("%lld", ans);
    return 0;
}