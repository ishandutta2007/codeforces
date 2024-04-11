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

char s[1005];
char ns[1005];

void work()
{
    int n, m; scanf("%d%d", &n, &m);
    scanf("%s", s + 1);
    for (int i = 1; i <= min(n, m); i++) {
        for (int j = 1; j <= n; j++) {
            ns[j] = s[j];
            if (s[j] == '1') continue;
            int x = (s[j-1] == '1' ? 1 : 0);
            int y = (s[j+1] == '1' ? 1 : 0);
            if (x + y == 1) ns[j] = '1';
        }
        for (int j = 1; j <= n; j++) s[j] = ns[j];
    }
    printf("%s\n", s + 1);
}

int main()
{
    int t; scanf("%d", &t);
    for (int i = 1; i <= t; i++) work();
    return 0;
}