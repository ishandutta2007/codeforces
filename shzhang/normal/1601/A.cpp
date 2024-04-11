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

int a[200005];
int n;
int cnt[35];

void work()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", a + i);
    for (int j = 0; j < 30; j++) {
        cnt[j] = 0;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 30; j++) {
            if (a[i] & (1 << j)) cnt[j]++;
        }
    }
    for (int i = 1; i <= n; i++) {
        bool good = true;
        for (int j = 0; j < 30; j++) {
            if (cnt[j] % i != 0) good = false;
        }
        if (good) printf("%d ", i);
    }
    printf("\n");
}

int main()
{
    int t; scanf("%d", &t);
    for (int i = 1; i <= t; i++) work();
    return 0;
}