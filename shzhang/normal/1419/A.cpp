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

void work(void)
{
    int n; scanf("%d", &n); scanf("%s", s + 1);
    if (n % 2 == 0) {
        // second player decides which even position to reveal
        for (int i = 2; i <= n; i += 2) {
            if ((s[i] - '0') % 2 == 0) {
                printf("2\n"); return;
            }
        }
        printf("1\n"); return;
    } else {
        // first player decides which odd pos to reveal
        for (int i = 1; i <= n; i += 2) {
            if ((s[i] - '0') % 2 == 1) {
                printf("1\n"); return;
            }
        }
        printf("2\n"); return;
    }
}

int main()
{
    int t; scanf("%d", &t); for (int i = 1; i <= t; i++) work();
    return 0;
}