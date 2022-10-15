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

void cycle(int n, ll l, ll r, ll off)
{
    if (n == 0) return;
    while (l <= (n - 1) * 2 && l <= r) {
        printf("%lld ", (l % 2 ? 1 : l / 2 + 1) + off); l++;
    }
    if (r == (ll)n * (ll)(n-1) + 1LL) {
        cycle(n-1, l - (n - 1) * 2, r - 1 - (n - 1) * 2, off + 1);
        printf("%lld ", off + 1);
    } else {
        cycle(n-1, l - (n - 1) * 2, r - (n - 1) * 2, off + 1);
    }
}

int main()
{
    int T;
    scanf("%d", &T);
    for (int i = 1; i <= T; i++) {
        int n; ll l, r;
        scanf("%d%lld%lld", &n, &l, &r);
        cycle(n, l, r, 0);
        printf("\n");
    }
    return 0;
}