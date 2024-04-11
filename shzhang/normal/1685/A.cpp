#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <cstdlib>
#include <utility>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
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

void work()
{
    int n; scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", a + i);
    if (n % 2) {
        printf("NO\n"); return;
    }
    map<int, int> freq;
    int commonval = -1;
    for (int i = 1; i <= n; i++) {
        freq[a[i]]++;
        if (freq[a[i]] == n / 2) commonval = a[i];
        if (freq[a[i]] > n / 2) {
            printf("NO\n"); return;
        }
    }

    if (commonval == -1) {
        printf("YES\n");
        sort(a + 1, a + n + 1);
        for (int i = 1; i <= n; i++) {
            if (i % 2) {
                printf("%d ", a[(i + 1) / 2]);
            } else {
                printf("%d ", a[i / 2 + n / 2]);
            }
        }
    } else {
        int lt = 0, gt = 0;
        for (int i = 1; i <= n; i++) {
            if (a[i] != commonval) {
                if (a[i] < commonval) lt++;
                else gt++;
            }
        }
        if (lt && gt) {
            printf("NO\n"); return;
        } else {
            printf("YES\n");
            for (int i = 1; i <= n; i++) {
                if (a[i] != commonval) {
                    printf("%d %d ", a[i], commonval);
                }
            }
        }
    }
    printf("\n");
}

int main()
{
    int t; scanf("%d", &t);
    for (int i = 1; i <= t; i++) work();
    return 0;
}