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

#define MOD 998244353

int f[1000005];
int psum[1000005];
int factors[1000005];

int n;

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j += i) {
            factors[j]++;
        }
    }
    for (int i = 1; i <= n; i++) {
        f[i] = (psum[i-1] + factors[i]) % MOD;
        psum[i] = (psum[i-1] + f[i]) % MOD;
    }
    printf("%d", f[n]);
    return 0;
}