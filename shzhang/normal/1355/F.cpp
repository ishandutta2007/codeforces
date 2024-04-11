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

ll lst[] = {
    84687918336000000,
    14091321279645467,
    12102247529335477,
    87747117633700729,
    326580695497527083,
    87796770491685553,
    883023198139052797,
    22342094349139601,
    71235931512604841,
    192878245514479103,
    542676746453092519,
    3068689788020071,
    5399194415623193,
    8517511016337023,
    13425528102933757,
    22861092512071133,
    36738834719671459,
    51159497847369007,
    72410448629704357,
    99637302530329493,
    149158072733691997,
    202395587171454013
};

__int128 Gcd(__int128 a, __int128 b)
{
    if (b == 0) return a;
    return Gcd(b, a % b);
}

__int128 Lcm(__int128 a, __int128 b)
{
    return (a * b) / Gcd(a, b);
}

int main()
{
    int T;
    scanf("%d", &T);
    for (int d = 1; d <= T; d++) {
        __int128 curlcm = 1;
        for (int i = 0; i < 22; i++) {
            printf("? %lld\n", lst[i]);
            fflush(stdout);
            ll val; scanf("%lld", &val);
            curlcm = Lcm(curlcm, (__int128)val);
        }
        int ans = curlcm;
        int cnt = 0;
        for (int i = 1; i * i <= ans; i++) {
            if (ans % i == 0) {
                if (i * i == ans) {
                    cnt++;
                } else {
                    cnt += 2;
                }
            }
        }
        printf("! %d\n", cnt * 2);
        fflush(stdout);
    }
    return 0;
}