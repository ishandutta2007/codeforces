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

ll f[100][100];

int main()
{
    int t;
    scanf("%d", &t);
    for (int dat = 1; dat <= t; dat++) {
        ll d, m;
        scanf("%lld%lld", &d, &m);
        for (int i = 0; i <= 60; i++) {
            for (int j = 0; j <= 60; j++) f[i][j] = 0;
        }
        f[0][0] = 1;
        ll ans = 0;
        for (int i = 1; i <= 37; i++) {
            for (int j = 0; j < 31; j++) {
                f[i][j+1] = 0;
                if ((1 << j) > d) {
                    continue;
                } else if ((1 << j) <= d && (1 << (j + 1)) > d) {
                    for (int k = 0; k <= j; k++) {
                        f[i][j+1] += ((ll)(d - ((1 << j) - 1)) * (ll)f[i-1][k]) % m;
                        if (f[i][j+1] >= m) f[i][j+1] -= m;
                    }
                } else {
                    for (int k = 0; k <= j; k++) {
                        f[i][j+1] += ((ll)(1 << j) * (ll)f[i-1][k]) % m;
                        if (f[i][j+1] >= m) f[i][j+1] -= m;
                    }
                }
                ans += f[i][j+1];
                if (ans >= m) ans -= m;
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}