#include <bits/stdc++.h>
using namespace std;
int cnt, tot, num;
#define N 1000
int arr[N], dis[N], low[N], val[N], col[N], vis[N][N];
vector<int> v[N], rv[N];
void dfs(int x, int p) {
    arr[++tot] = x;
    dis[x] = ++cnt;
    low[x] = cnt;
    for(int i = 0; i < v[x].size(); i ++) {
        int y = v[x][i];
        if(y == p) continue;
        if(dis[y]) low[x] = min(low[x], dis[y]);
        else {
            dfs(y, x);
            low[x] = min(low[x], low[y]);
        }
    }
    if(low[x] == dis[x]) {
        ++num;
        while(1) {
            int y = arr[tot--];
            col[y] = num;
            if(y == x) break;
        }
        val[num] = x;
    }
}

void dfs1(int x, int p) {
    dis[x] = ++cnt;
    for(int i = 0; i < rv[x].size(); i ++) {
        int y = rv[x][i];
        if(y == p) continue;
        dfs1(y, x);
    }
}

int a[N];

bool cmp(int i, int j) {
    return dis[i] < dis[j];
}

int main() {
    //freopen("1.in", "r", stdin);
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; i ++) {
        int x, y;
        scanf("%d%d", &x, &y);
        v[x].push_back(y);
        v[y].push_back(x);
        vis[x][y] = vis[y][x] = 1;
    }
    dfs(1, 0);
    for(int i = 1; i <= n; i ++) {
        for(int j = 0; j < v[i].size(); j ++) {
            int k = v[i][j];
            if(col[k] == col[i]) continue;
            if(col[k] > col[i]) continue;
            else {
                rv[col[i]].push_back(col[k]), rv[col[k]].push_back(col[i]);
            }
        }
    }
    if(n == 2) {
      puts("-1");
      return 0;
    }
    if(num == 1) {
        puts("0");
        return 0;
    }
    if(num == 2) {
        for(int i = 1; i <= n; i ++) for(int j = i + 1; j <= n; j ++) if(col[i] != col[j] && !vis[i][j]) {
            printf("%d\n", 1);
            printf("%d %d\n", i, j);
            return 0;
        }
    }
    cnt = 0;
    dfs1(1, 0);
    int gas = 0;
    for(int i = 1; i <= num; i ++) if(rv[i].size() == 1) a[gas ++] = i;
    sort(a, a + gas, cmp);
    printf("%d\n", (gas + 1) / 2);
    int xx = (gas + 1) / 2;
    for(int i = 0; i < gas / 2; i ++) {
        printf("%d %d\n", val[a[i]], val[a[xx + i]]);
    }
    if(gas & 1) printf("%d %d\n", val[a[0]], val[a[gas / 2]]);
    return 0;
}