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

int a[100005];
int b[100005];
int odd[100005], odd2[100005];

void work()
{
    for (int i = 1; i <= 100000; i++) odd[i] = odd2[i] = 0;
    int n; scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i);
        b[i] = a[i];
    }
    sort(b + 1, b + n + 1);
    for (int i = 1; i <= n; i++) {
        if (i % 2 == 1) {
            odd[a[i]]++; odd2[b[i]]++;
        }
    }
    for (int i = 1; i <= 100000; i++) {
        if (odd[i] != odd2[i]) {
            printf("NO\n"); return;
        }
    }
    printf("YES\n");
}

int main()
{
    int t; scanf("%d", &t);
    for (int i = 1; i <= t; i++) work();
    return 0;
}