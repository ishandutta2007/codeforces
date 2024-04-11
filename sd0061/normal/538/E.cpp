#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
typedef long long LL;
const int N = 200005;

int n , m , pre[N] , mcnt;
struct edge {
    int x , next;
}e[N << 1];
int f[N] , deg[N] , s[N];

void dfs(int x , int fa , int dep) {
    if (deg[x] == 1) {
        f[x] = 1;
        s[x] = 1;
    } else {
        if (!dep)
            f[x] = 1 << 30;
        else
            f[x] = 0;
        for (int i = pre[x] ; ~i ; i = e[i].next) {
            int y = e[i].x;
            if (y != fa) {
                dfs(y , x , dep ^ 1);
                s[x] += s[y];
                if (!dep)
                    f[x] = min(f[x] , s[y] - f[y]);
                else
                    f[x] += f[y] - 1;
            }
        }
        if (!dep)
            f[x] = s[x] - f[x];
        else
            ++ f[x];
    }
}
void DFS(int x , int fa , int dep) {
    if (deg[x] == 1) {
        f[x] = 1;
    } else {
        if (!dep)
            f[x] = 1 << 30;
        else
            f[x] = 0;
        for (int i = pre[x] ; ~i ; i = e[i].next) {
            int y = e[i].x;
            if (y != fa) {
                DFS(y , x , dep ^ 1);
                if (!dep)
                    f[x] = min(f[x] , f[y] - 1);
                else
                    f[x] += s[y] - f[y];
            }
        }
        if (!dep)
            ++ f[x];
        else
            f[x] = s[x] - f[x];
    }
}
void work() {
    int i , x , y;
    scanf("%d" , &n);
    memset(pre , -1 , sizeof(pre));
    for (i = 1 ; i < n ; ++ i) {
        scanf("%d%d" , &x , &y);
        ++ deg[x] , ++ deg[y];
        e[mcnt] = (edge) {y , pre[x]} , pre[x] = mcnt ++;
        e[mcnt] = (edge) {x , pre[y]} , pre[y] = mcnt ++;
    }
    /*if (n == 1) {
        puts("1 1");
        return;
        }*/
    ++ deg[1];
    dfs(1 , 0 , 0);
    printf("%d " , f[1]);
    memset(f , 0 , sizeof(f));
    DFS(1 , 0 , 1);
    printf("%d\n" , f[1]);

}

int main() {
    work();
    return 0;
}