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
#include <random>
#include <chrono>

using namespace std;

#define ll long long
#define MOD 998244353
#define mul(a, b) (((ll)(a) * (ll)(b)) % MOD)
/* total: curpos, mask, restrict, has_nonzero */
int f[20][1030][2][2];
int cnt[20][1030][2][2];

ll l, r; int k;

int work(ll bound)
{
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 1030; j++) {
            for (int K = 0; K < 2; K++) {
                for (int L = 0; L < 2; L++) {
                    f[i][j][K][L] = cnt[i][j][K][L] = 0;
                }
            }
        }
    }
    char s[25];
    sprintf(s + 1, "%lld", bound);
    int digcnt = strlen(s + 1);
    cnt[0][0][1][0] = 1;
    for (int i = 0; i < digcnt; i++) {
        for (int mask = 0; mask < (1 << 10); mask++) {
            for (int rest = 0; rest < 2; rest++) {
                for (int nonzero = 0; nonzero < 2; nonzero++) {
                    for (int nxt = 0; nxt < 10; nxt++) {
                        if (rest && nxt + '0' > s[i+1]) continue;
                        int nmask;
                        if (!nonzero && !nxt) {
                            nmask = mask;
                        } else {
                            nmask = mask | (1 << nxt);
                        }
                        int cntcur = cnt[i][mask][rest][nonzero];
                        int fcur = f[i][mask][rest][nonzero];
                        int& cntv = cnt[i+1][nmask][rest && nxt + '0' == s[i+1]][nonzero || nxt];
                        int& fv = f[i+1][nmask][rest && nxt + '0' == s[i+1]][nonzero || nxt];
                        cntv += cntcur;
                        if (cntv >= MOD) cntv -= MOD;
                        fv += mul(10, fcur);
                        if (fv >= MOD) fv -= MOD;
                        fv += mul(cntcur, nxt);
                        if (fv >= MOD) fv -= MOD;
                    }
                }
            }
        }
    }
    int ans = 0;
    for (int mask = 0; mask < (1 << 10); mask++) {
        int bwt = 0;
        for (int i = 0; i < 10; i++) {
            if (mask & (1 << i)) bwt++;
        }
        if (bwt <= k) {
            ans += f[digcnt][mask][0][1];
            if (ans >= MOD) ans -= MOD;
            ans += f[digcnt][mask][1][1];
            if (ans >= MOD) ans -= MOD;
        }
    }
    //printf("%lld: %d\n", bound, ans);
    return ans;
}

int main()
{
    scanf("%lld%lld%d", &l, &r, &k);
    printf("%d", ((work(r) - work(l - 1)) % MOD + MOD) % MOD);
    return 0;
}