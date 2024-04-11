#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;

const int N = 20;
const int S = (1 << 18);
const int M = 505;
const ll inf = 0x3f3f3f3f3f3f3f3f;

int n, m, tot = 0, head[N];
int id[N], ans[N], deg[N], ned[N];
ll f[N][N][S], c[N];
bool vis[N], pre[N][N][S];
queue <int> q;

struct Edge {
    int to, nxt;
} e[M];

inline void add(int from, int to) {
    e[++tot].to = to;
    e[tot].nxt = head[from];
    head[from] = tot;
}

template <typename T>
inline void read(T &X) {
    char ch = 0; T op = 1; 
    for (X = 0; ch > '9' || ch < '0'; ch = getchar())
        if (ch == '-') op = -1;
    for (; ch >= '0' && ch <= '9'; ch = getchar())
        X = (X * 10) + ch - '0';
    X *= op;
}

inline void topsort() {
    int cnt = 0;
    for (int i = 1; i <= n; i++) 
        if (!deg[i]) vis[i] = 1, q.push(i), ned[i] = 0;
    for (; !q.empty(); ) {
        int x = q.front(); q.pop();
        id[++cnt] = x;
        for (int i = head[x]; i; i = e[i].nxt) {
            int y = e[i].to;
            --deg[y];
            ned[y] |= (1 << (x - 1)) | ned[x];
            if (!deg[y] && !vis[y]) {
                vis[y] = 1;
                q.push(y);
            }
        }
    }
    reverse(id + 1, id + 1 + n);
}

inline int lowbit(int x) {
    return x & (-x);
}

void getAns(int i, int j, int s) {
    if (s == 0) return;
    int tos, toi, toj;
    if (j == 1) toj = n + 1, toi = i - 1;
    else toj = j - 1, toi = i;
    if (!pre[i][j][s]) tos = s;
    else {
        tos = s ^ (1 << (id[toj] - 1));
        int now = id[toj];
        ans[now] = toi;
    }
    getAns(toi, toj, tos);
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("sample.in", "r", stdin);
    #endif

    read(n), read(m);
    for (int i = 1; i <= m; i++) {
        int x, y; ll v;
        read(x), read(y), read(v);
        c[x] += v, c[y] -= v, ++deg[x];
        add(y, x);
    }

    topsort();

/*    for (int i = 1; i <= n; i++)
        printf("%d ", ned[i]);
    printf("\n");
    for (int i = 1; i <= n; i++)
        printf("%d ", id[i]);
    printf("\n");
    for (int i = 1; i <= n; i++)
        printf("%lld ", c[i]);
    printf("\n");       */

    memset(f, 0x3f, sizeof(f));
    memset(pre, 0, sizeof(pre));
    f[0][1][0] = 0;
    for (int i = 0; i < n; i++)
        for (int j = 1; j <= n + 1; j++)
            for (int s1 = 0; s1 < (1 << n); s1++) {
                if(f[i][j][s1] == inf) continue;
//                printf("%d %d %d : %lld\n", i, j, s1, pre[i][j][s1]);
                if (j == n + 1) {
                    if (f[i + 1][1][s1] > f[i][j][s1]) {
                        f[i + 1][1][s1] = f[i][j][s1];
//                      pre[i + 1][1][s1][0] = s1, pre[i + 1][1][s1][1] = j, pre[i + 1][1][s1][2] = i;
                        pre[i + 1][1][s1] = 0;
                    }
                } else {
                    if (f[i][j + 1][s1] > f[i][j][s1]) {
                        f[i][j + 1][s1] = f[i][j][s1];
                        pre[i][j + 1][s1] = 0;
//                      pre[i][j + 1][s1][0] = s1, pre[i][j + 1][s1][1] = j, pre[i][j + 1][s1][2] = i;
                    }
                    int to = id[j];
                    if ((1 << (to - 1)) & s1) continue;
                    if ((ned[to] & s1) == ned[to]) {
                        int s2 = s1 | (1 << (to - 1));
                        ll val = c[to] * i;
                        if (f[i][j + 1][s2] > f[i][j][s1] + val) {
                            f[i][j + 1][s2] = f[i][j][s1] + val;
//                          pre[i][j + 1][s2][0] = s1, pre[i][j + 1][s2][1] = j, pre[i][j + 1][s2][2] = i;
                            pre[i][j + 1][s2] = 1;
                        }
                    }
                }
            }
//    printf("%d %d %d : %lld\n", n, 1, (1 << n) - 1, f[n][1][(1 << n) - 1]);

    getAns(n, 1, (1 << n) - 1);
    
    for (int i = 1; i <= n; i++)
        printf("%d%c", ans[i], " \n"[i == n]);
    return 0;
}