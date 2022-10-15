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

int p[100005];
int left[100005], right[100005];

int main()
{
    int n; scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", p + i);
    }
    for (int i = 2; i <= n; i++) {
        if (p[i] > p[i-1]) left[i] = left[i-1] + 1;
        else left[i] = 0;
    }
    for (int i = n - 1; i >= 1; i--) {
        if (p[i] > p[i+1]) right[i] = right[i+1] + 1;
        else right[i] = 0;
    }
    int maxv = -1;
    for (int i = 1; i <= n; i++) {
        //printf("%d %d\n", left[i], right[i]);
        if (left[i] == right[i] && left[i] % 2 == 0) {
            maxv = max(maxv, left[i]);
        }
    }
    if (maxv < 0) {
        printf("0"); return 0;
    }
    int maxv_cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (left[i] > maxv || right[i] > maxv) {
            printf("0"); return 0;
        }
        if (left[i] == maxv || right[i] == maxv) {
            maxv_cnt++;
        }
    }
    if (maxv_cnt > 1) {
        printf("0");
    } else {
        printf("1");
    }
    return 0;
}