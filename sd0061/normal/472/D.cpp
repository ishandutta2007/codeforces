#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <stack>
#include <queue>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cassert>
#include <cctype>
using namespace std;
typedef long long LL;
const int N = 2005;
const int M = 200005;
int n , g[N][N] , D[N][N];
int d[N] , pre[N] , mcnt , p[N];
bool f[N];
struct edge {
    int x , w , next;
}e[N << 1];

void dfs(int x , int fa , int* dep) {
    for (int i = pre[x] ; ~i ; i = e[i].next) {
        int y = e[i].x;
        if (y != fa) {
            dep[y] = dep[x] + e[i].w;
            dfs(y , x , dep);
        }
    }
}

void work() {
    int i , j , x , y;
    scanf("%d",&n);
    for (i = 1 ; i <= n ; ++ i)
        for (j = 1 ; j <= n ; ++ j)
            scanf("%d",&g[i][j]);
    bool flag = 0;
    for (i = 1 ; i <= n ; ++ i)
        for (j = 1 ; j <= n ; ++ j)
            if (i == j) {
                if (g[i][j])
                    flag = 1;
            } else {
                if (!g[i][j] || g[i][j] != g[j][i])
                    flag = 1;
            }
    if (flag) {
        puts("NO");
        return;
    }
    memset(d , 63 , sizeof(d));
    memset(pre , -1 , sizeof(pre));
    memset(p , -1 , sizeof(p));
    d[1] = 0 , p[1] = 0;
    while (1) {
        x = -1;
        for (i = 1 ; i <= n ; ++ i)
            if (!f[i] && (!~x || d[i] < d[x]))
                x = i;
        if (!~x) break; f[x] = 1;
        if (p[x]) {
            y = p[x];
            //cout << x << ' ' << y << ' ' << d[x] << endl;
            e[mcnt] = (edge) {x , d[x] , pre[y]} , pre[y] = mcnt ++;
            e[mcnt] = (edge) {y , d[x] , pre[x]} , pre[x] = mcnt ++;
        }
        for (y = 1 ; y <= n ; ++ y)
            if (!f[y] && g[x][y] < d[y])
                d[y] = g[x][y] , p[y] = x;
    }
    for (i = 1 ; i <= n ; ++ i)
        dfs(i , 0 , D[i]);
    for (i = 1 ; i <= n ; ++ i)
        for (j = 1 ; j <= n ; ++ j)
            if (g[i][j] != D[i][j])
                flag = 1;
    puts(flag ? "NO" : "YES");
}

int main() {
    work();
    return 0;
}