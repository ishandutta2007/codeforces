#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;
const int N = 300000+10;
int n, m, u, v, deg[N], vis[N], dp[N];
char s[N];
vector<int> g[N];
int dfs(int x, char ch) {
    if (vis[x]) return dp[x];
    vis[x] = 1;
    int ans = 0;
    for (int i = 0; i < g[x].size(); i ++) {
        int y = g[x][i];
        ans = max(ans, dfs(y, ch));
    }
    return dp[x] = ans + (s[x] == ch);
}

bool chk_ring() {
    bool vs[N];int in[N];
    memset(vs, 0, sizeof(vs));
    queue<int> que;
    for (int i = 1; i <= n; i ++) {
        in[i] = deg[i]; 
        if (deg[i] == 0) {
            que.push(i);
            vs[i] = 1;
        }
    } 

    while (que.size()) {
        int top = que.front(); que.pop();
        
        for (int i = 0; i < g[top].size(); i ++) {
            int nex = g[top][i];
            in[nex] --;
            if (in[nex] == 0) {
                que.push(nex);
                vs[nex] = 1;
            }
        }
    }

    for (int i = 1; i <= n; i ++)
        if (!vs[i]) return 0;
    return 1;
}

int main() {
    scanf("%d %d", &n, &m);
    scanf("%s", s+1);
    for (int i = 1; i <= m; i ++) {
        scanf("%d %d", &u, &v);
        g[u].push_back(v); deg[v] ++;
    }
    if (!chk_ring()) {
        return !printf("-1\n");
    }

    int res = 0;
    for (int alp = 'a'; alp <= 'z'; alp ++) {
        int tmp = 0;
        memset(vis, 0, sizeof(vis));
        for (int i = 1; i <= n; i ++) {
            if (deg[i] == 0) {
                tmp = max(dfs(i, alp), tmp);   
            }
        }     
        res = max(res, tmp);
    }
    for (int i = 1; i <= n; i ++) {
        if (vis[i] == 0) {
            printf("-1\n");
            exit(0);
        }
    }
    printf("%d\n", res);
}