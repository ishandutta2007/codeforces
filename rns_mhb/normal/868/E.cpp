#include <bits/stdc++.h>
using namespace std;
#define N 55
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

int n, m, s, dp[N][N], d[N][N], fi[N], se[N], deg[N], p[N], q[N], tt[N];

int f(int x) {
    return (x == p[x]) ? x : p[x] = f(p[x]);
}

int main() {
    //freopen("1.in", "r", stdin);
    //freopen("11.out", "w", stdout);
    int i, j, k, l, L, R, M;
    scanf("%d", &n);
    for (i = 1; i <= n; i ++)
        for (j = 1; j <= n; j ++)
            if (i != j) d[i][j] = inf;
    for (i = 1; i <= n; i ++) p[i] = i;
    for (i = 1; i < n; i ++) {
        scanf("%d %d %d", &j, &k, &l);
        fi[i] = j, se[i] = k;
        deg[j] ++, deg[k] ++;
        d[j][k] = d[k][j] = l;
    }
    scanf("%d %d", &s, &m);
    for (i = 1; i < n; i ++)
        if (fi[i] != s && se[i] != s)
            p[f(fi[i])] = f(se[i]);
    for (i = 0; i < m; i ++)
        scanf("%d", &j), q[f(j)] ++;
    for (i = 1; i <= n; i ++)
        for (j = 1; j <= n; j ++)
            for (k = 1; k <= n; k ++)
                chkmin(d[j][k], d[i][j] + d[i][k]);
    for (i = 1; i <= m; i ++)
        for (j = 1; j <= n; j ++)
            if (deg[j] == 1) {
                L = 0, R = inf;
                while (L < R) {
                    M = L + R + 1 >> 1;
                    int t = 0;
                    for (k = 1; k <= n; k ++)
                        if (deg[k] == 1) {
                            for (l = 0; l < i && dp[l][k] + d[j][k] < M; l ++);
                            t += i - l;
                        }
                    if (t < i) R = M - 1;
                    else L = M;
                }
                dp[i][j] = L;
            }

    L = 0, R = inf;
    while (L < R) {
        M = L + R + 1 >> 1;
        int t = 0;
        memset(tt, 0, sizeof tt);
        for (k = 1; k <= n; k ++)
            if (deg[k] == 1) {
                for (l = 0; l < m && dp[l][k] + d[s][k] < M; l ++);
                tt[f(k)] += m - l;
            }
        for (k = 1; k <= n; k ++)
            if (q[k] > tt[k]) break;
        if (k > n) L = M;
        else R = M - 1;
    }
    printf("%d\n", L);

    return 0;
}