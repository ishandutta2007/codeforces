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

void work()
{
    int n; scanf("%d", &n);
    int first_nonzero = n + 1;
    int last_nonzero = 0;
    int zerocnt = 0;
    for (int i = 1; i <= n; i++) {
        int x; scanf("%d", &x);
        if (x == 0) {
            zerocnt++;
        } else {
            first_nonzero = min(first_nonzero, i);
            last_nonzero = max(last_nonzero, i);
        }
    }
    if (zerocnt == n) {
        printf("0\n");
    } else if (n - zerocnt == last_nonzero - first_nonzero + 1) {
        printf("1\n");
    } else {
        printf("2\n");
    }
}

int main()
{
    int t; scanf("%d", &t);
    for (int i = 1; i <= t; i++) work();
    return 0;
}