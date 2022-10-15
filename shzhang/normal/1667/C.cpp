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

int main()
{
    scanf("%d", &n);
    k = n / 3;
    if (n % 3 == 0) {
        printf("%d\n", 2 * k);
        for (int i = 1; i <= k; i++) {
            printf("%d %d\n", k-i+1, i);
        }
        for (int i = 1; i < k; i++) {
            printf("%d %d\n", 2*k+i, n-i);
        }
        printf("%d %d\n", n, n);
    } else {
        printf("%d\n", 2 * k + 1);
        for (int i = 1; i <= k; i++) {
            printf("%d %d\n", k-i+1, i);
        }
        for (int i = 1; i <= k + 1; i++) {
            printf("%d %d\n", n-k-1+i, n-i+1);
        }
    }
    return 0;
}