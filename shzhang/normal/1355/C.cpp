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

int main()
{
    int a, b, c, d;
    scanf("%d%d%d%d", &a, &b, &c, &d);
    ll ans = 0;
    //int ct = 0;
    /*for (int x = 100; x <= 200; x++) {
        for (int y = 200; y <= 300; y++) {
            for (int z = 300; z <= 4000; z++) {
                if (x + y > z) ct++;
            }
        }
    }
    printf("%d", ct);*/
    for (int i = a; i <= b; i++) {
        int minj = c - i + 1; /* 1 */
        int maxj = d - i + 1; /* d - c + 1 */
        int x = max(b, minj);
        int y = min(c, maxj);
        if (x <= y) {
            ans += ((ll)(x - (c - i) + y - (c - i)) * (ll)(y - x + 1)) / 2LL;
        }
        if (d - i + 1 < c) {
            int cnt = c - max((d - i + 1), b - 1);
            ans += (ll)cnt * (ll)(d - c + 1);
        }
    }
    printf("%lld", ans);
    return 0;
}