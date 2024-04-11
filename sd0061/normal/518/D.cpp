#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 2005;

int n , t;
double p;
double f[N][N] , s[N];

void work() {
    scanf("%d%lf%d",&n,&p,&t);
    f[0][0] = 1;
    int i , j;
    for (i = 0 ; i < t ; ++ i) {
        for (j = 0 ; j <= n ; ++ j) {
            if (j < n) {
                f[i + 1][j + 1] += f[i][j] * p;
                f[i + 1][j] += f[i][j] * (1 - p);                
            } else
                f[i + 1][j] += f[i][j];
        }
    }
    double res = 0;
    for (i = 0 ; i <= n ; ++ i)
        res += i * f[t][i];
    printf("%.15f\n" , res);
}

int main() {
    //freopen("1" , "r" , stdin);
    work();
    return 0;
}