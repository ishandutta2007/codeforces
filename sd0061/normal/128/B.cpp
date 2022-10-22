#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
typedef long long LL;
int n , k;
char str[N];

int root , last , nodecnt;
int u[N][26] , val[N] , par[N] , w[N];
LL f[N];
vector<int> e[N];
bool vis[N];
inline int newnode(int _val) {
    ++ nodecnt;
    memset(u[nodecnt] , 0 , sizeof(u[nodecnt]));
    val[nodecnt] = _val , par[nodecnt] = 0 , f[nodecnt] = 0;
    e[nodecnt].clear() , vis[nodecnt] = 0 , w[nodecnt] = 0;
    return nodecnt;
}

void extend(int c) {
    int p = last , np = newnode(val[p] + 1);
    while (p && u[p][c] == 0)
        u[p][c] = np , p = par[p];
    if (p == 0)
        par[np] = root;
    else {
        int q = u[p][c];
        if (val[p] + 1 == val[q]) {
            par[np] = q;
        } else {
            int nq = newnode(val[p] + 1);
            memcpy(u[nq] , u[q] , sizeof(u[q]));
            par[nq] = par[q];
            par[q] = par[np] = nq;
            while (p && u[p][c] == q)
                u[p][c] = nq , p = par[p];
        }
    }
    ++ w[np];
    last = np;
}
void dfs(int x) {
    for (int i = 0 ; i < e[x].size() ; ++ i) {
        int y = e[x][i];
        dfs(y);
        w[x] += w[y];
    }
}
LL DFS(int x) {
    if (vis[x]) return f[x]; vis[x] = 1;
    f[x] = w[x];
    for (int i = 0 ; i < 26 ; ++ i)
        if (u[x][i])
            f[x] += DFS(u[x][i]);
    return f[x];
}

void work() {
    scanf("%s%d" , str , &k);
    n = strlen(str);

    if ((LL) n * (n + 1) / 2 < k) {
        puts("No such line.");
        return;
    }
    nodecnt = 0;
    root = last = newnode(0);
    for (int i = 0 ; i < n ; ++ i)
        extend(str[i] - 'a');
    for (int i = 2 ; i <= nodecnt ; ++ i)
        e[par[i]].push_back(i);
    dfs(root);
    int x = root;
    w[root] = 0;
    while (x && k > 0) {
        if (k > w[x])
            k -= w[x];
        else
            break;
        for (int i = 0 ; i < 26 ; ++ i) {
            if (u[x][i]) {
                int y = u[x][i];
                if (k > DFS(y))
                    k -= DFS(y);
                else {
                    putchar('a' + i);
                    x = y;
                    break;
                }
            }
        }
    }
    puts("");
}

int main() {
    work();
    return 0;
}