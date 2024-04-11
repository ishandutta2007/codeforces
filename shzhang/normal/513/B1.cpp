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

int perm[55];

int main()
{
    int n; ll m;
    scanf("%d%lld", &n, &m);
    m--;
    int l = 1; int r = n;
    for (ll i = n - 2; i >= 0; i--) {
        if (m & (1LL << i)) {
            perm[r] = n - 2 - i + 1; r--;
        } else {
            perm[l] = n - 2 - i + 1; l++;
        }
    }
    perm[l] = n;
    for (int i = 1; i <= n; i++) {
        printf("%d ", perm[i]);
    }
    return 0;
}