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

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d\n", 3 * n + 4);
    printf("0 0\n0 1\n1 0\n1 1\n");
    for (int i = 1; i <= n; i++) {
        printf("%d %d\n%d %d\n%d %d\n", i+1, i, i, i+1, i+1, i+1);
    }
    return 0;
}