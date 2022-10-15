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

char s[1005], t[1005];

void work()
{
    scanf("%s%s", s + 1, t + 1);
    int u = strlen(s + 1), v = strlen(t + 1);
    for (int l = 1; l <= u; l++) {
        for (int r = l; r <= u; r++) {
            if (r - l + 1 > v) continue;
            bool good = true;
            for (int i = l; i <= r; i++) {
                if (s[i] != t[i - l + 1]) good = false;
            }
            if (!good) continue;
            for (int i = 1; i <= v - (r - l + 1); i++) {
                if (i >= r || s[r - i] != t[r - l + 1 + i]) {
                    good = false; break;
                }
            }
            if (good) {
                printf("YES\n"); return;
            }
        }
    }
    printf("NO\n");
}

int main()
{
    int q; scanf("%d", &q);
    for (int i = 1; i <= q; i++) work();
    return 0;
}