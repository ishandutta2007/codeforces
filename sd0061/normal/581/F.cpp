#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
typedef long long LL;
using namespace std;
const int N = 5005;
int n , pre[N] , mcnt , deg[N];
struct edge {
    int x , next;
}e[N << 1];
int f[N][N][2] , m , size[N];
int g[2][N][2];
void dfs(int x , int fa) {
    int c = 0;
    size[x] = 0;
    for (int i = pre[x] ; ~i ; i = e[i].next) {
        int y = e[i].x;
        if (y != fa) {
            dfs(y , x);
            size[x] += size[y];
            ++ c;
        }
    }
    memset(f[x] , 0x3f , sizeof(f[x]));
    if (c == 0) {
        ++ size[x];
        f[x][0][0] = 0;
        f[x][1][1] = 0;        
    } else {
        int cur = 0 , nxt = 1;
        memset(g , 0x3f , sizeof(g));
        g[cur][0][0] = 0;
        g[cur][0][1] = 0;
        int S = 0;
        for (int i = pre[x] ; ~i ; i = e[i].next) {
            int y = e[i].x;
            if (y != fa) {
                memset(g[nxt] , 0x3f , sizeof(g[nxt]));
                for (int j = 0 ; j <= S ; ++ j) {
                    for (int k = 0 ; k <= size[y] ; ++ k) {
                        g[nxt][j + k][0] = min(g[nxt][j + k][0] , g[cur][j][0] + f[y][k][0]);
                        g[nxt][j + k][0] = min(g[nxt][j + k][0] , g[cur][j][0] + f[y][k][1] + 1);
                        g[nxt][j + k][1] = min(g[nxt][j + k][1] , g[cur][j][1] + f[y][k][0] + 1);
                        g[nxt][j + k][1] = min(g[nxt][j + k][1] , g[cur][j][1] + f[y][k][1]);
                    }
                }
                S += size[y];
                swap(cur , nxt);
            }
        }
        memcpy(f[x] , g[cur] , sizeof(f[x]));
    }
}

void work() {
    scanf("%d" , &n);
    memset(pre , -1 , sizeof(pre));
    for (int i = 1 ; i < n ; ++ i) {
        int x , y;
        scanf("%d%d" , &x , &y);
        e[mcnt] = (edge) {y , pre[x]} , pre[x] = mcnt ++;
        e[mcnt] = (edge) {x , pre[y]} , pre[y] = mcnt ++;        
        ++ deg[x] , ++ deg[y];
    }
    if (n == 2) {
        puts("1");
        return;
    }
    int root = -1;
    for (int i = 1 ; i <= n ; ++ i)
        if (deg[i] > 1) {
            root = i;
        } else
            ++ m;
    dfs(root , 0);
    printf("%d\n" , min(f[root][m / 2][0] , f[root][m / 2][1]));
}

int main() {
 
    work();
    return 0;
}