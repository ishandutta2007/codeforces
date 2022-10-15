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

#define encode(a, b) (((a)-1) * m + (b))

int uf[5005];
bool blocked[55][55];
bool hasgood[55][55];

int fin(int a)
{
    if (uf[a] == a) return a;
    return uf[a] = fin(uf[a]);
}

void un(int a, int b)
{
    a = fin(a); b = fin(b);
    if (a == b) return;
    uf[a] = b;
}

void work(void)
{
    /* solve problem here */
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            blocked[i][j] = false;
            uf[encode(i, j)] = encode(i, j);
            hasgood[i][j] = false;
        }
    }
    for (int i = 1; i <= n; i++) {
        char s[55]; scanf("%s", s + 1);
        for (int j = 1; j <= m; j++) {
            if (s[j] == '#') blocked[i][j] = true;
            if (s[j] == 'G') hasgood[i][j] = true;
            if (s[j] == 'B') {
                blocked[i][j] = blocked[i+1][j] = blocked[i][j+1]
                    = blocked[i-1][j] = blocked[i][j-1] = true;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < m; j++) {
            if (!blocked[i][j] && !blocked[i][j+1])
                un(encode(i, j), encode(i, j+1));
        }
    }
    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= m; j++) {
            if (!blocked[i][j] && !blocked[i+1][j])
                un(encode(i, j), encode(i+1, j));
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (hasgood[i][j] && fin(encode(i, j)) != fin(encode(n, m))) {
                printf("No\n"); return;
            }
        }
    }
    printf("Yes\n");
    /* remember to clean up any global variables if needed */
}

int main()
{
    int T; scanf("%d", &T);
    for (int i = 1; i <= T; i++) work();
    return 0;
}