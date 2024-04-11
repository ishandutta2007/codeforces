#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
using namespace std;
typedef long long LL;

#define N 100005
int n , m , pre[N] , mcnt;
struct edge {
    int x , next;
}e[N << 1];
int f[N] , ncnt;

int dfs(int x , int fa) {
    f[x] = ++ ncnt;
    int px = -1 , py;
    for (int i = pre[x] ; ~i ; i = e[i].next) {
        int y = e[i].x;
        if (!f[y]) {
            py = dfs(y , x);
            if (~py) {
                printf("%d %d %d\n" , py , y , x);
            } else if (!~px) {
                px = y;
            } else {
                printf("%d %d %d\n" , px , x , y);
                px = -1;
            }
        } else if (f[y] > f[x]) {
            if (!~px) {
                px = y;
            } else {
                printf("%d %d %d\n" , px , x , y);
                px = -1;
            }
        }
    }
    return px;
}

void work()
{
    int i , x , y;
    scanf("%d%d",&n,&m);
    mcnt = ncnt = 0;
    memset(pre , -1 , sizeof(pre));
    for (i = 1 ; i <= m ; ++ i) {
        scanf("%d%d",&x,&y);
        e[mcnt] = (edge) {y , pre[x]} , pre[x] = mcnt ++;
        e[mcnt] = (edge) {x , pre[y]} , pre[y] = mcnt ++;
    }
    if (m & 1) {
        puts("No solution");
        return;
    }
    dfs(1 , 0);
}

int main()
{
    work();
    return 0;
}