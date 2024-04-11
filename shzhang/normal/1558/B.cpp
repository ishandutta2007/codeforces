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

int n, MOD;
int f[4000005];
int psum[4000005];

int main()
{
    scanf("%d%d", &n, &MOD);
    int val = 0;
    f[1] = 1;
    for (int i = 1; i <= n; i++) {
        val += psum[i];
        if (val >= MOD) val -= MOD;
        if (i > 1) f[i] = val;
        psum[i+1] += f[i];
        if (psum[i+1] >= MOD) psum[i+1] -= MOD;
        for (int j = 2; i * j <= n; j++) {
            psum[i * j] += f[i];
            if (psum[i*j] >= MOD) psum[i*j] -= MOD;
            if ((i + 1) * j <= n) {
                psum[(i + 1) * j] -= f[i];
                if (psum[(i + 1) * j] < 0) psum[(i + 1) * j] += MOD;
            }
        }
    }
    printf("%d", f[n]);
    return 0;
}