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

/*
cnt[x] = # of ways for 2nd highest to be equal to x
*/

int n;
int l[10], r[10];

ll cnt[10005];

ll atleast(int intv, int bound)
{
    if (bound > r[intv]) return 0;
    if (bound < l[intv]) return r[intv] - l[intv] + 1;
    return r[intv] - bound + 1;
}

ll atmost(int intv, int bound)
{
    if (bound < l[intv]) return 0;
    if (bound > r[intv]) return r[intv] - l[intv] + 1;
    return bound - l[intv] + 1;
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", l + i, r + i);
    }
    for (int second = 1; second <= n; second++) {
        for (int first = 1; first <= n; first++) {
            if (first == second) continue;
            for (int val = l[second]; val <= r[second]; val++) {
                /* case 1: val at first > val at second */
                ll ways = 1;
                for (int i = 1; i <= n; i++) {
                    if (i == second) continue;
                    if (i == first) {
                        ways *= atleast(i, val + 1);
                    } else if (i < second) {
                        ways *= atmost(i, val - 1);
                    } else {
                        ways *= atmost(i, val);
                    }
                }
                cnt[val] += ways;
            }
        }
    }
    for (int a = 1; a <= n; a++) {
        for (int b = a + 1; b <= n; b++) {
            for (int val = max(l[a], l[b]); val <= min(r[a], r[b]); val++) {
                ll ways = 1;
                for (int c = 1; c <= n; c++) {
                    if (c == a || c == b) continue;
                    if (c < b) {
                        ways *= atmost(c, val - 1);
                    } else {
                        ways *= atmost(c, val);
                    }
                }
                cnt[val] += ways;
            }
        }
    }
    double ans = 0.0;
    double prod = 1.0;
    for (int i = 1; i <= n; i++) {
        prod *= (double)(r[i] - l[i] + 1);
    }
    for (int i = 1; i <= 10000; i++) {
        ans += (double)cnt[i] * (double)i;
    }
    printf("%.15f", ans / prod);
    return 0;
}