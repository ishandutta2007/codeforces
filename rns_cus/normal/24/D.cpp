#include<stdio.h>
#define N 1002
double gas[N][N];
double d[N][N];
int n, m;
int main(){
    int x, y;
   // freopen("D.in", "r", stdin);
    scanf("%d%d%d%d", &n, &m, &x, &y);
    for(int i = n-1; i >= x; i --) {
        for(int k = 0; k < 45; k ++) {
            for(int j = 1; j <= m; j ++) {
                double dd;
                if(j == 1 || j == m) dd = 3;
                else dd = 4;
                if(m == 1) dd = 2;
                d[i][j] = (d[i][j] + d[i+1][j] + d[i][j+1] + d[i][j-1]) / dd + 1.;
            }
        }
    }
    printf("%.9lf\n", d[x][y]);
}