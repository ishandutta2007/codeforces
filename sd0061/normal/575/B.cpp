#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <queue>
#include <vector>
#include <cctype>
#include <set>
using namespace std;
typedef long long LL;
const int N = 100005;
const int Q = 1e9 + 7;
int n , K , pre[N] , mcnt;
struct edge {
    int x , w , next;
}e[N << 1];
int f[17][N] , dep[N] , res;
int up[N] , down[N] , power[1000005];

void dfs(int x , int fa) {
    f[0][x] = fa , dep[x] = dep[fa] + 1;
    for (int i = pre[x] ; ~i ; i = e[i].next) {
        int y = e[i].x;
        if (y != fa) {
            dfs(y , x);
        }
    }
}
void DFS(int x , int fa) {
    for (int i = pre[x] ; ~i ; i = e[i].next) {
        int y = e[i].x;
        if (y != fa) {
            DFS(y , x);
            up[x] += up[y];
            down[x] += down[y];
            if (!e[i].w) {
                res += power[down[y]] - 1;
                res %= Q;
            }
            if (!e[i ^ 1].w) {
                res += power[up[y]] - 1;
                res %= Q;
            }            
        }
    }

}
int LCA(int x , int y) {
    if (dep[x] < dep[y])
        swap(x , y);
    for (int i = 16 ; i >= 0 ; -- i)
        if (dep[x] - dep[y] >> i & 1)
            x = f[i][x];
    if (x == y) return y;
    for (int i = 16 ; i >= 0 ; -- i)
        if (f[i][x] != f[i][y]) {
            x = f[i][x];
            y = f[i][y];
        }
    return f[0][y];
}

void work() {
    scanf("%d" , &n);
    memset(pre , -1 , sizeof(pre));
    for (int i = 1 ; i < n ; ++ i) {
        int x , y , z;
        scanf("%d%d%d" , &x , &y , &z);
        e[mcnt] = (edge) {y , 1 , pre[x]} , pre[x] = mcnt ++;
        e[mcnt] = (edge) {x , !z , pre[y]} , pre[y] = mcnt ++;        
    }
    dfs(1 , 0);
    for (int j = 1 ; j < 17 ; ++ j)
        for (int i = 1 ; i <= n ; ++ i)
            f[j][i] = f[j - 1][f[j - 1][i]];
    scanf("%d" , &K);
    power[0] = 1;
    for (int i = 1 ; i <= K ; ++ i) {
        power[i] = power[i - 1] << 1;
        power[i] %= Q;
    }
    int x = 1;
    for (int i = 0 ; i < K ; ++ i) {
        int y;
        scanf("%d" , &y);
        int z = LCA(x , y);
        ++ up[x] , -- up[z];
        ++ down[y] , -- down[z];
        x = y;
    }
    res = 0;
    DFS(1 , 0);
    printf("%d\n" , res);
}
int main() {
    work();
    return 0;
}