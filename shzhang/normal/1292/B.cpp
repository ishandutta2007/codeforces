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

using namespace std;

#define ll long long
#define dist(i, j) (absolute((i == -1 ? xs : points[i].first) - points[j].first) + absolute((i == -1 ? ys : points[i].second) - points[j].second))

ll absolute(ll a)
{
    return a < 0 ? -a : a;
}

int main()
{
    ll x0, y0, ax, ay, bx, by;
    scanf("%lld%lld%lld%lld%lld%lld", &x0, &y0, &ax, &ay, &bx, &by);
    ll xs, ys, t;
    scanf("%lld%lld%lld", &xs, &ys, &t);
    vector<pair<ll, ll> > points;
    while (1) {
        if (absolute(x0 - xs) >= 100000000000000000LL || absolute(y0-ys)  >= 100000000000000000LL) break;
        points.push_back(make_pair(x0, y0));
        x0 = ax * x0 + bx;
        y0 = ay * y0 + by;
    }
    int ans = 0;
    for (int i = 0; i < points.size(); i++) {
        for (int j = 0; j < points.size(); j++) {
            if (dist(-1, i) + dist(i, j) > t) continue;
            ans = max(ans, (int)absolute(j-i) + 1);
            if (dist(-1, i) + dist(i, j) * 2 > t) {
                if (j > i) {
                    int k = i;
                    while (k >= 0 && dist(-1, i) + dist(i, j) * 2 + dist(i, k) < t) k--;
                    k++;
                    ans = max(ans, (int)absolute(j - k) + 1);
                } else {
                    int k = i;
                    while (k < points.size() && dist(-1, i) + dist(i, j) * 2 + dist(i, k) < t) k++;
                    k--;
                    ans = max(ans, (int)absolute(j - k) + 1);
                }
            }
        }
    }
    printf("%d", ans);
    return 0;
}