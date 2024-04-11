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

ll ab(ll a)
{
    return a < 0LL ? -a : a;
}

int main()
{
    int t;
    scanf("%d", &t);
    for (int d = 1; d <= t; d++) {
        int n;
        scanf("%d", &n);
        ll ans1 = 0, ans2 = 0;
        for (ll i = 1; i <= n; i++) {
            if (i < (n / 2) || i == n) {
                ans1 += (1LL << i);
            } else {
                ans2 += (1LL << i);
            }
        }
        printf("%lld\n", ab(ans1 - ans2));
    }
    return 0;
}