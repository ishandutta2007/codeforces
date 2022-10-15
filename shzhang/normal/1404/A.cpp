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
bool has0[300005];
bool has1[300005];
bool hasq[300005];
char s[300005];

void work()
{
    scanf("%d%d", &n, &k);
    for (int i = 0; i < k; i++) has0[i] = has1[i] = hasq[i] = false;
    scanf("%s", s);
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') has0[i % k] = true;
        if (s[i] == '1') has1[i % k] = true;
        if (s[i] == '?') hasq[i % k] = true;
    }
    int zerocnt = 0, onecnt = 0;
    for (int i = 0; i < k; i++) {
        if (has0[i] && has1[i]) {
            printf("NO\n"); return;
        }
        if (has0[i]) zerocnt++;
        if (has1[i]) onecnt++;
    }
    if (max(zerocnt, onecnt) > k / 2) {
        printf("NO\n");
    } else {
        printf("YES\n");
    }
}

int main()
{
    int t; scanf("%d", &t);
    for (int i = 1; i <= t; i++) work();
    return 0;
}