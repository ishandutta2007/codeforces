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

char s1[45], s2[45];

void work()
{
    int n; scanf("%d", &n);
    scanf("%s", s1 + 1);
    for (int i = 1; i <= n; i++) s2[i] = s1[i];
    sort(s2 + 1, s2 + n + 1);
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (s2[i] != s1[i]) ans++;
    }
    printf("%d\n", ans);
}

int main()
{
    int t; scanf("%d", &t);
    for (int i = 1; i <= t; i++) work();
    return 0;
}