#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>
#include <cmath>
using namespace std;
typedef long long LL;
const int N = 405;
int n , m , g[N][N];    

void work() {
    scanf("%d%d" , &n , &m);
    for (int i = 1 ; i <= m; ++ i) {
        int x , y;
        scanf("%d%d" , &x , &y);
        g[x][y] = g[y][x] = 1;
    }
    if (m == 0 || m == n * (n - 1) / 2)
        puts("-1");
    else {
        if (g[1][n]) {
            for (int i = 1 ; i <= n ; ++ i)
                for (int j = 1 ; j <= n ; ++ j)
                    if (i != j)
                        g[i][j] ^= 1;
        }
        for (int i = 1 ; i <= n ; ++ i)
            for (int j = 1 ; j <= n ; ++ j)
                if (!g[i][j])
                    g[i][j] = 1 << 29;
        for (int k = 1 ; k <= n ; ++ k)
            for (int i = 1 ; i <= n ; ++ i)
                for (int j = 1 ; j <= n ; ++ j)
                    g[i][j] = min(g[i][j] , g[i][k] + g[k][j]);
        if (g[1][n] == 1 << 29)
            g[1][n] = -1;
        printf("%d\n" , g[1][n]);
    }
}

int main() {
    work();
    return 0;
}