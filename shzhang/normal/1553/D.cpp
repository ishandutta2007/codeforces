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

int u, v;
char s[100005], t[100005];
int nxt[100005][26][2];
int f[100005][2];

void work()
{
    scanf("%s%s", s + 1, t + 1);
    u = strlen(s + 1), v = strlen(t + 1);
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 2; j++) {
            nxt[u][i][j] = nxt[u+1][i][j] = u + 1;
        }
    }
    for (int i = u - 1; i >= 0; i--) {
        for (int j = 0; j < 26; j++) {
            for (int k = 0; k < 2; k++) {
                if (s[i+1] == j + 'a' && (i + 1) % 2 == k) {
                    nxt[i][j][k] = i + 1;
                } else {
                    nxt[i][j][k] = nxt[i+1][j][k];
                }
            }
        }
    }
    for (int i = 1; i <= v; i++) {
        for (int j = 0; j < 2; j++) {
            f[i][j] = nxt[f[i-1][1-j]][t[i] - 'a'][j];
        }
    }
    printf("%s\n", (f[v][u % 2] != u + 1) ? "YES" : "NO");
}

int main()
{
    int q; scanf("%d", &q);
    for (int i = 1; i <= q; i++) work();
    return 0;
}