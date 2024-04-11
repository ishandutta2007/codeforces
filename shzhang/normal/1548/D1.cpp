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

ll cnt[4][4];

int Gcd(int A, int b)
{
    if (b == 0) return A;
    return Gcd(b, A % b);
}

int main()
{
    int n; scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int x, y; scanf("%d%d", &x, &y);
        cnt[x%4][y%4]++;
    }
    ll ans = 0;
    for (int a = 0; a < 4; a++) {
        for (int b = 0; b < 4; b++) {
            for (int c = 0; c < 4; c++) {
                for (int d = 0; d < 4; d++) {
                    for (int e = 0; e < 4; e++) {
                        for (int f = 0; f < 4; f++) {
                            int edge1 = (a == c && b == d ? 0 : 2);
                            int edge2 = (a == e && b == f ? 0 : 2);
                            int edge3 = (c == e && d == f ? 0 : 2);
                            int x1 = c - a;
                            int y1 = d - b;
                            int x2 = e - a;
                            int y2 = f - b;
                            int val = x1 * y2 - x2 * y1;
                            if (val < 0) val = -val;
                            if (val % 2) continue;
                            val /= 2;
                            if ((val + 1 - (((edge1 + edge2 + edge3) / 2) % 2)) % 2 == 1) {
                                ans += cnt[a][b] * cnt[c][d] * cnt[e][f];
                            }
                        }
                    }
                }
            }
        }
    }
    ans -= n;
    ans -= n * (n-1) * 3;
    //printf("%lld ", ans);
    ans /= 6LL;
    printf("%lld", ans);
    return 0;
}