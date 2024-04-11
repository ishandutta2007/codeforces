#include <bits/stdc++.h>
using namespace std;
#define M 20
#define N 101000
int mx[N][2], son[N], pa[M][N], sum[N], vis[N], dp[N], w[N], st[N], en[N];
typedef pair<int,int> pi;
vector<int> v[N];
pi A[N];

void update(int x, int dis) {
    if(dis > mx[x][0]) {
        mx[x][1] = mx[x][0], mx[x][0] = dis;
    } else if(dis > mx[x][1]) mx[x][1] = dis;
}

int cnt;

void dfs(int x, int p) {
    mx[x][0] = mx[x][1] = 0;
    son[x] = 0;
    int mm = 0;
    for(int i = 0; i < v[x].size(); i ++) {
        int id = v[x][i];
        int y = st[id] + en[id] - x;
        if(y == p) continue;
        pa[0][y] = x;
        dp[y] = dp[x] + w[id];
        dfs(y, x);
        if(!son[x] || mm < mx[y][0] + w[id]) son[x] = y, mm = mx[y][0] + w[id];
        update(x, mx[y][0] + w[id]);
    }
}

void dfs1(int x, int p) {
    for(int i = 0; i < v[x].size(); i ++) {
        int id = v[x][i];
        int y = st[id] + en[id] - x;
        if(y == p) continue;
        if(mx[x][0] == mx[y][0] + w[id]) {
            update(y, mx[x][1] + w[id]);
        } else {
            update(y, mx[x][0] + w[id]);
        }
        dfs1(y, x);
    }
}

void dfs2(int x, int len) {
    if(!son[x]) {
        A[++ cnt] = pi(-len, x);
        return ;
    }
    for(int i = 0; i < v[x].size(); i ++) {
        int id = v[x][i];
        int y = st[id] + en[id] - x;
        if(y == pa[0][x]) continue;
        if(y == son[x]) dfs2(y, len + w[id]);
        else dfs2(y, w[id]);
    }
}

int main() {
    //freopen("2.in", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int n, Q;
    scanf("%d%d", &n, &Q);
    for(int i = 1; i < n; i ++) {
        scanf("%d%d%d", &st[i], &en[i], &w[i]);
        v[st[i]].push_back(i);
        v[en[i]].push_back(i);
    }
    dfs(1, 0);
    dfs1(1, 0);
    int R = 1;
    for(int i = 2; i <= n; i ++) if(mx[i][0] < mx[R][0]) R = i;
    pa[0][R] = 0;
    dp[R] = 0;
    dfs(R, 0);
    dfs2(R, 0);
    for(int i = 1; i < M; i ++) {
        for(int j = 1; j <= n; j ++) {
            pa[i][j] = pa[i - 1][pa[i - 1][j]];
        }
    }
    sort(A + 1, A + cnt + 1);
    sum[0] = 0;
    vis[R] = 1;
    for(int i = 1; i <= cnt; i ++) {
        sum[i] = sum[i - 1] - A[i].first;
        int x = A[i].second;
        while(!vis[x]) {
            vis[x] = i;
            x = pa[0][x];
        }
    }
    int ans = 0;
    while(Q --) {
        int x, y;
        scanf("%d%d", &x, &y);
        x = (x + ans - 1) % n + 1;
        y = (y + ans - 1) % n + 1;
        if(y * 2 >= cnt) {
            ans = sum[cnt];
            printf("%d\n", ans);
            continue;
        }
        if(vis[x] <= 2 * y) {
            ans = sum[2 * y];
            printf("%d\n", ans);
            continue;
        }
        int xx = x;
        for(int i = M - 1; i >= 0; i --) {
            int j = pa[i][xx];
            if(!j) continue;
            if(vis[j] > 2 * y) xx = j;
        }
        xx = pa[0][xx];
        ans = sum[2 * y] + mx[x][0] + dp[x] - dp[xx] - min(-A[2 * y].first, mx[xx][0]);
        printf("%d\n", ans);
    }
    return 0;

}