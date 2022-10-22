#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200005;
int n , m , q;
int pre[N] , mcnt;
struct edge {
    int x , next;
}e[N << 1];
int F[N];
int getf(int x) {
    return F[x] == x ? x : F[x] = getf(F[x]);
}
int ncnt , dfn[N] , low[N];
bool bridge[N];
int f[18][N] , Lev , cnt;
void dfs(int x , int fa) {
    low[x] = dfn[x] = ++ ncnt;
    for (int i = pre[x] ; ~i ; i = e[i].next) {
        int y = e[i].x;
        if (i != fa) {
            if (!dfn[y]) {
                dfs(y , i ^ 1);
                low[x] = min(low[x] , low[y]);
                if (low[y] > dfn[x])
                    bridge[i >> 1] = 1;
            } else if (dfn[y] < dfn[x])
                low[x] = min(low[x] , dfn[y]);
        }
    }    
}
void DFS(int x) {
    if (low[x]) return;
    low[x] = cnt;
    for (int i = pre[x] ; ~i ; i = e[i].next)
        if (!bridge[i >> 1])
            DFS(e[i].x);
}
void dfs(int x , int fa , int dep) {
    dfn[x] = dep , f[0][x] = fa;   
    for (int i = pre[x] ; ~i ; i = e[i].next) {
        int y = e[i].x;
        if (y != fa) {
            dfs(y , x , dep + 1);
        }
    }
}
int LCA(int x , int y) {
    if (dfn[x] < dfn[y])
        swap(x , y);
    for (int i = Lev ; i >= 0 ; -- i)
        if (dfn[x] - dfn[y] >> i & 1)
            x = f[i][x];
    if (x == y) return y;
    for (int i = Lev ; i >= 0 ; -- i)
        if (f[i][x] != f[i][y]) {
            x = f[i][x];
            y = f[i][y];
        }
    return f[0][y];
}
int up[N] , down[N];
bool check(int x) {
    for (int i = pre[x] ; ~i ; i = e[i].next) {
        int y = e[i].x;
        if (f[0][y] == x) {
            if (!check(y))
                return 0;
            up[x] += up[y];
            down[x] += down[y];
        }
    }
    if (up[x] && down[x])
        return 0;
    return 1;
}
void work() {
    scanf("%d%d%d", &n, &m, &q);
    memset(pre , -1 , sizeof(pre));
    for (int i = 1 ; i <= n ; ++ i)
        F[i] = i;
    vector< pair<int , int> > E;
    for (int i = 0 ; i < m ; ++ i) {
        int x , y;
        scanf("%d%d" , &x , &y);
        E.push_back(make_pair(x , y));
        e[mcnt] = (edge) {y , pre[x]} , pre[x] = mcnt ++;
        e[mcnt] = (edge) {x , pre[y]} , pre[y] = mcnt ++;
        F[getf(x)] = getf(y);
    }
    for (int i = 1 ; i <= n ; ++ i) {
        if (!dfn[i])
            dfs(i , -1);
    }
    memset(low , 0 , sizeof(low));
    for (int i = 1 ; i <= n ; ++ i) {
        if (!low[i]) {
            ++ cnt;
            DFS(i);
        }
    }
    n = cnt;
    memset(pre , -1 , sizeof(pre));
    mcnt = 0;
    for (auto &it : E) {
        int x = it.first , y = it.second;
        if (low[x] != low[y]) {
            x = low[x] , y = low[y];
            e[mcnt] = (edge) {y , pre[x]} , pre[x] = mcnt ++;
            e[mcnt] = (edge) {x , pre[y]} , pre[y] = mcnt ++;
        }
    }
    memset(dfn , 0 , sizeof(dfn));
    for (int i = 1 ; i <= n ; ++ i) {
        if (!dfn[i])
            dfs(i , 0 , 1);
    }    
    for (int j = 1 ; 1 << j < n ; ++ j) {
        for (int i = 1 ; i <= n ; ++ i)
            f[j][i] = f[j - 1][f[j - 1][i]];
        Lev = j;
    }
    for (int i = 0 ; i < q ; ++ i) {
        int x , y;
        scanf("%d%d" , &x , &y);
        if (getf(x) != getf(y)) {
            puts("No");
            return;
        }
        x = low[x] , y = low[y];
        int z = LCA(x , y);
        up[x] ++;
        up[z] --;
        down[y] ++;
        down[z] --;
    }
    for (int i = 1 ; i <= n ; ++ i) {
        if (!f[0][i] && !check(i)) {
            puts("No");
            return;
        }
    }
    puts("Yes");
}

int main() {
    work();    
    return 0;
}