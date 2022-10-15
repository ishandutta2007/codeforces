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

ll arr[4][3] = {{0, 0, 0}, {1, 2, 3}, {2, 3, 1}, {3, 1, 2}};

int main()
{
    ll t;
    scanf("%lld", &t);
    for (ll d = 1; d <= t; d++) {
        ll val = d; scanf("%lld", &val);
         val--;
        ll tri_id = val / 3LL; ll tri_local = val % 3LL;
        ll lower_triple_cnt = 0; ll cur = 1; ll curlayer = 0;
        while (1) {
            if (lower_triple_cnt + cur <= tri_id) {
                lower_triple_cnt += cur; curlayer++;
                cur <<= 2LL;
            } else {
                break;
            }
        }
        tri_id -= lower_triple_cnt;
        ll ans = 0;
        for (ll x = 3, b = 0; x <= 1000000000000000000LL; x <<= 2LL, b += 2LL) {
            ll curv = (tri_id & x) >> b;
            ans += (ll)arr[curv][tri_local] << b;
        }
        ans += ((tri_local + 1LL) << (curlayer * 2LL));
        printf("%lld\n", ans);
    }
    //printf("%lld", 9999999999999LL << 1);
    return 0;
}