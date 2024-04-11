#include <bits/stdc++.h>
using namespace std;

#define N 1005
#define INF 1000000000000000000

template <class T> void chkmax(T &a, T b) { if (a < b) a = b; }

typedef long long ll;
int n, m, tw, cnt, color;
int w[N], b[N], clr[N];
ll sw[N], sb[N];
ll dp[2][N];
bool vis[N];
vector<int> v[N], u[N];

void dfs(int x, int par = 0) {
    if (clr[x]) return;
    clr[x] = color;
    for (int i = 0; i < v[x].size(); i ++) {
        int y = v[x][i];
        if (y == par) continue;
        dfs(y, x);
    }
}

void calc_dp() {
    for (int i = 1, t = 0; i <= cnt; i ++, t ^= 1) {
        for (int j = 0; j <= tw; j ++) {
            dp[t][j] = dp[t^1][j];
            for (int k = 0; k < u[i].size(); k ++) {
                int kk = u[i][k];
                if (j >= w[kk]) chkmax(dp[t][j], dp[t^1][j-w[kk]] + b[kk]);
            }
            if (j >= sw[i]) chkmax(dp[t][j], dp[t^1][j-sw[i]] + sb[i]);
        }
    }
}

int main() {
    scanf("%d %d %d", &n, &m, &tw);
    for (int i = 1; i <= n; i ++) {
        scanf("%d", &w[i]);
    }
    for (int i = 1; i <= n; i ++) {
        scanf("%d", &b[i]);
    }
    for (int i = 1; i <= m; i ++) {
        int x, y;
        scanf("%d %d", &x, &y);
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for (int i = 1; i <= n; i ++) if (!clr[i]) {
        color = ++cnt;
        dfs(i);
    }
    for (int i = 1; i <= n; i ++) {
        u[clr[i]].push_back(i);
        sb[clr[i]] += b[i];
        sw[clr[i]] += w[i];
    }
    calc_dp();
    printf("%I64d\n", dp[cnt&1^1][tw]);
}