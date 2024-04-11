#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 1005;
const int Q = 1e9 + 7;
int n , m;
int p[N];
double f[N][N];
void work() {
    int i , j , x , y;
    scanf("%d%d",&n,&m);
    for (i = 1 ; i <= n ; ++ i)
        scanf("%d",&p[i]);
    for (i = 1 ; i <= n ; ++ i)
        for (j = 1 ; j <= n ; ++ j)
            if (p[i] > p[j])
                f[i][j] = 1.0;
    for (i = 1 ; i <= m ; ++ i) {
        scanf("%d%d",&x,&y);
        f[x][y] = f[y][x] = (f[x][y] + f[y][x]) / 2.0;
        for (j = 1 ; j <= n ; ++ j)
            if (j != x && j != y) {
                f[j][x] = f[j][y] = (f[j][x] + f[j][y]) / 2.0;
                f[x][j] = f[y][j] = (f[x][j] + f[y][j]) / 2.0;                
            }
    }
    double res = 0;
    for (i = 1 ; i <= n ; ++ i)
        for (j = i + 1 ; j <= n ; ++ j)
            res += f[i][j];
    printf("%.10f\n" , res);
}

int main() {
    work();
    return 0;
}