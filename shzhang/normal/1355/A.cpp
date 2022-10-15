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
    int t;
    scanf("%d", &t);
    for (int d = 1; d <= t; d++) {
        ll a, k; scanf("%lld%lld", &a, &k);
        k--;
        while (k > 0) {
            char s[30]; sprintf(s, "%lld", a);
            ll mindigit = 100, maxdigit = 0;
            for (int i = 0; s[i]; i++) {
                mindigit = min(mindigit, (ll)(s[i] - '0'));
                maxdigit = max(maxdigit, (ll)(s[i] - '0'));
            }
            //printf("%lld%lld\n", mindigit, maxdigit);
            if (mindigit == 0 || maxdigit == 0) break;
            a += mindigit * maxdigit;
            k--;
        }
        printf("%lld\n", a);
    }
    return 0;
}