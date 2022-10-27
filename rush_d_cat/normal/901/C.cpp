#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
typedef long long LL;
const int N = 300000+10;
int n, m, u, v;
vector<int> G[N];
int pre[N], low[N], is_dfs[N];
int deg[N];
int dfs_clock;
int tarjan(int u, int p) {
    int lowu = pre[u] = ++ dfs_clock;
    is_dfs[u] = 1;
    for (int i = 0; i < G[u].size(); i ++) {
        int v = G[u][i];
        if (v == p) continue;
        if (!pre[v]) {
            int lowv = tarjan(v, u);
            lowu = min(lowu, lowv);
        } else if (pre[v] < pre[u]) {
            lowu = min(lowu, pre[v]);
        }
    }
    return low[u] = lowu;
}

void init() {
    memset(pre, 0, sizeof(pre));
    memset(deg, 0, sizeof(deg));
    memset(is_dfs, 0, sizeof(is_dfs));
    dfs_clock = 0;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i ++)
        G[i].clear();
    for (int i = 1; i <= m; i ++) {
        scanf("%d %d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for (int i = 1; i <= n; i ++) 
        if (!is_dfs[i])
            tarjan(i, -1);
}

int nxt[N], vis[N], cnt[N];
int q, x, y;
LL sum[N];
int main() {
    init();
    for (int i = 1; i <= n; i ++) {
        cnt[low[i]] ++;
    }
    int L = 1, R = 0;
    while (R <= n && L <= n) {
        while (R+1<=n && ((vis[low[R+1]] == 0) || ((vis[low[R+1]]+1) < cnt[low[R+1]]))) {
            vis[low[R+1]] ++; R ++;
        } 
        nxt[L] = R; vis[low[L]] --; L ++;
    }
    for (int i = 1; i <= n; i ++) {
        sum[i] = sum[i-1] + (nxt[i] - i + 1);
    }

    /*
    printf("low: \n");
    for (int i = 1; i <= n; i ++) printf("%d ", low[i]);
    printf("\n");
    printf("nxt: \n");
    for (int i = 1; i <= n; i ++) printf("%d ", nxt[i]);
    printf("\n");
    */

    scanf("%d", &q);
    while (q --) {
        scanf("%d %d", &x, &y);    
        int L = x-1, R = y;
        while (R - L > 1) {
            int mid = (L + R) / 2;
            if (nxt[mid] < y) {
                L = mid;
            } else {
                R = mid;
            }
        }
        if (nxt[R] < y) L = R;
        LL ans = 0;
        ans += sum[L] - sum[x-1]; // [x, L]
        ans += (LL)(y - L) * (y - L + 1) / 2; // [L+1, y]
        printf("%lld\n", ans);
    }
}