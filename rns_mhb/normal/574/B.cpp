#include <bits/stdc++.h>
using namespace std;
#define N 4040
#define inf 1000000000
#define eps 1e-7
#define pi acos(-1)
#define gc getchar
#define pc putchar
#define pb push_back

typedef pair<int, int> pii;
typedef long long ll;

template <class T>
inline void chkmax(T &x, T y) {if (x < y) x = y;}

template <class T>
inline void chkmin(T &x, T y) {if (x > y) x = y;}

int n, m, len[N], adj[N][N];
bool vis[N][N];

int main() {
    //freopen("1.in", "r", stdin);
    //freopen("11.out", "w", stdout);
    int a, b, ans = inf;
    scanf("%d %d", &n, &m);
    while (m --) {
        scanf("%d %d", &a, &b);
        vis[a][b] = 1;
        adj[a][len[a]++] = b;
        adj[b][len[b]++] = a;
    }
    for (int i = 1; i <= n; i ++)
        for (int j = 0; j < len[i]; j ++)
            for (int k = 0; k < len[i]; k ++) {
                int u = adj[i][j], v = adj[i][k];
                if (vis[u][v]) chkmin(ans, len[i] + len[u] + len[v]);
            }
    if (ans == inf) puts("-1");
    else printf("%d\n", ans - 6);

    return 0;
}