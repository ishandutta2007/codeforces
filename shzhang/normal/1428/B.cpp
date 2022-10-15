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

char s[300005];

void work()
{
    int n;
    scanf("%d", &n);
    scanf("%s", s + 1);
    bool has_left = false; bool has_right = false;
    for (int i = 1; i <= n; i++) {
        if (s[i] == '<') has_left = true;
        if (s[i] == '>') has_right = true;
    }
    int ans = 0;
    for (int i = 2; i <= n; i++) {
        if (s[i] == '-' || s[i-1] == '-') ans++;
    }
    if (s[1] == '-' || s[n] == '-') ans++;
    if (!has_left || !has_right) ans = n;
    printf("%d\n", ans);
}

int main()
{
    int t; scanf("%d", &t);
    for (int i = 1; i <= t; i++) work();
    return 0;
}