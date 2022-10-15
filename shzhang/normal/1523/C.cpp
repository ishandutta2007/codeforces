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
int stk[1005]; int stktop = 0;

void work()
{
    int n; scanf("%d", &n); stktop = 0;
    for (int i = 1; i <= n; i++) {
        int x; scanf("%d", &x);
        if (x == 1) {
            stk[stktop] = 1; stktop++;
        } else {
            while (stk[stktop - 1] != x - 1) stktop--;
            stk[stktop - 1]++;
        }
        for (int j = 0; j < stktop; j++) {
            printf("%d", stk[j]);
            if (j < stktop - 1) printf(".");
        }
        printf("\n");
    }
}

int main()
{
    int t; scanf("%d", &t);
    for (int i = 1; i <= t; i++) work();
    return 0;
}