
#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <set>
#include <queue>
#include <cmath>
#include <algorithm>
#include <cstring>

using namespace std;

#define ll long long

int main()
{
    ll a, b;
    scanf("%lld%lld", &a, &b);
    int ans = 0;
    for (ll hbit = 0; hbit < 62; hbit++) {
        for (ll rbit = 0; rbit < hbit; rbit++) {
            ll val = (1LL << (hbit + 1LL)) - 1LL - (1LL << rbit);
            if (val >= a && val <= b) {
                ans++;
            }
        }
    }
    printf("%d", ans);
    return 0;
}