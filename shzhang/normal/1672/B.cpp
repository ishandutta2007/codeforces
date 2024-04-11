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

char s[200005];

void work()
{
    scanf("%s", s + 1);
    int n = strlen(s + 1);
    int curpref = 0;
    for (int i = 1; i <= n; i++) {
        if (s[i] == 'A') {
            curpref++;
        } else {
            curpref--;
            if (curpref < 0) {
                printf("NO\n"); return;
            }
        }
    }
    printf("%s\n", s[n] == 'B' ? "YES" : "NO");
}

int main()
{
    int t; scanf("%d", &t);
    for (int i = 1; i <= t; i++) work();
    return 0;
}