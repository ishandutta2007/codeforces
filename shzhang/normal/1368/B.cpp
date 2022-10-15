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

int cnt[15];

int main()
{
    ll k; scanf("%lld", &k);
    while (1) {
        for (int i = 0; i <= 9; i++) {
            //debug("%d", i);
            cnt[i]++;
            ll prod = 1;
            for (int j = 0; j <= 9; j++) prod *= cnt[j];
            if (prod >= k) goto loop_end;
        }
    }
    loop_end:
    for (int i = 0; i <= 9; i++) {
        for (int j = 1; j <= cnt[i]; j++) printf("%c", "codeforces"[i]);
    }
    return 0;
}