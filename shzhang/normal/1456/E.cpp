#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <cstdlib>
#include <utility>
#include <cmath>
#include <queue>
#include <stack>
#include <cstring>

using namespace std;

#define ll long long

#ifndef ONLINE_JUDGE
#define debug(format, ...) fprintf(stderr, \
    "%s:%d: " format "\n", __func__, __LINE__,##__VA_ARGS__)
#else
#define debug(format, ...)
#define NDEBUG
#endif

int n, k;
ll l[55][55], r[55][55];
int badcnt[55][55];
ll c[55];

ll f[55][55][55][4][4];

#define INF 1000000000000000000LL

static inline ll getval(int pos, int mode, ll bit)
{
    if (pos < 1 || pos > n) return -1;
    if (mode == 0) return l[pos][0] >> bit;
    if (mode == 1) return (l[pos][0] >> bit) + 1;
    if (mode == 2) return r[pos][0] >> bit;
    return (r[pos][0] >> bit) - 1;
}

int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%lld%lld", &(l[i][0]), &(r[i][0]));
        for (int j = 1; j < k; j++) {
            l[i][j] = (l[i][j-1] >> 1) + (l[i][j-1] & 1);
            r[i][j] = (r[i][j-1] >> 1) - (1 - (r[i][j-1] & 1));
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < k; j++) {
            badcnt[i][j] = badcnt[i-1][j] + (r[i][j] < l[i][j] ? 1 : 0);
        }
    }
    for (int i = 0; i < k; i++) scanf("%lld", c + i);
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            for (int lmode = 0; lmode < 4; lmode++) {
                for (int rmode = 0; rmode < 4; rmode++) {
                    f[k][i][j][lmode][rmode] = INF;
                }
            }
        }
    }
    for (int bit = k - 1; bit >= 0; bit--) {
        for (int i = 1; i <= n + 1; i++) {
            for (int lmode = 0; lmode < 4; lmode++) {
                ll lval = getval(i - 1, lmode, bit);
                for (int rmode = 0; rmode < 4; rmode++) {
                    ll rval = getval(i, rmode, bit);
                    ll xorval = lval ^ rval;
                    if (lval == -1 || rval == -1) xorval = 0;
                    for (ll x = 0; x < k - bit; x++) {
                        f[bit][i][i-1][lmode][rmode] += (xorval & (1LL << x)) ?
                            c[x + bit] : 0;
                    }
                    debug("bit %d, [%d %d], %lld, %lld: %lld",
                        bit, i, i-1, lval, rval, f[bit][i][i-1][lmode][rmode]);
                }
            }
        }
        for (int siz = 1; siz <= n; siz++) {
            for (int i = 1; i + siz - 1 <= n; i++) {
                int j = i + siz - 1;
                for (int lmode = 0; lmode < 4; lmode++) {
                    ll lval = getval(i - 1, lmode, bit);
                    int lmodenew = lmode;
                    if (lmodenew == 1 && (lval & 1LL)) lmodenew = 0;
                    if (lmodenew == 3 && !(lval & 1LL)) lmodenew = 2;
                    for (int rmode = 0; rmode < 4; rmode++) {
                        //debug("%d %d", lmode, rmode);
                        ll rval = getval(j + 1, rmode, bit);
                        int rmodenew = rmode;
                        if (rmodenew == 1 && (rval & 1LL)) rmodenew = 0;
                        if (rmodenew == 3 && !(rval & 1LL)) rmodenew = 2;
                        if (badcnt[j][bit] - badcnt[i-1][bit]) {
                            f[bit][i][j][lmode][rmode] = INF; continue;
                        }
                        f[bit][i][j][lmode][rmode] =
                            f[bit+1][i][j][lmodenew][rmodenew] +
                            (lval == -1 || rval == -1 ||
                                (lval & 1) == (rval & 1) ? 0 : c[bit]);
                        debug("bit %d, [%d %d], %lld, %lld: %lld",
                            bit, i, j, lval, rval, f[bit][i][j][lmode][rmode]);
                        for (int K = i; K <= j; K++) {
                            //debug("%d %d %d", i, j, K);
                            f[bit][i][j][lmode][rmode] = min(
                                f[bit][i][j][lmode][rmode],
                                f[bit+1][i][K-1][lmodenew][l[K][bit] !=
                                    (l[K][0] >> (ll)(bit)) && !(l[K][bit] & 1) ? 1 : 0] +
                                f[bit][K+1][j][l[K][bit] ==
                                    (l[K][0] >> (ll)bit) ? 0 : 1][rmode] +
                                (lval == -1 || (lval & 1) == (l[K][bit] & 1) ?
                                    0 : c[bit])
                            );
                            /*debug("%lld %lld %lld (%lld %lld)",
                                f[bit+1][i][K-1][lmodenew][l[K][bit+1] ==
                                    (l[K][0] >> (ll)(bit + 1)) ? 0 : 1],
                                f[bit][K+1][j][l[K][bit] ==
                                        (l[K][0] >> (ll)bit) ? 0 : 1][rmode],
                                (lval == -1 || (lval & 1) == (l[K][bit] & 1) ?
                                    0 : c[bit]),
                                getval(i-1, lmodenew, bit + 1),
                                getval(K, l[K][bit+1] ==
                                    (l[K][0] >> (ll)(bit + 1)) ? 0 : 1, bit + 1));*/
                            f[bit][i][j][lmode][rmode] = min(
                                f[bit][i][j][lmode][rmode],
                                f[bit+1][i][K-1][lmodenew][r[K][bit] !=
                                    (r[K][0] >> (ll)(bit)) && (r[K][bit] & 1) ? 3 : 2] +
                                f[bit][K+1][j][r[K][bit] ==
                                    (r[K][0] >> (ll)bit) ? 2 : 3][rmode] +
                                (lval == -1 || (lval & 1) == (r[K][bit] & 1) ?
                                    0 : c[bit])
                            );
                        }
                        //debug("bit %d, [%d %d], %lld, %lld: %lld",
                            //bit, i, j, lval, rval, f[bit][i][j][lmode][rmode]);
                    }
                }
            }
        }
    }
    printf("%lld", f[0][1][n][0][0]);
    return 0;
}