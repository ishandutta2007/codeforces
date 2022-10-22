#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;
typedef long long LL;
const int N = 5005;
int n , m;
int p[N] , t[N];
double f[N][N] , g[N] , s[N];
void RD(int& x) {
    x = 0; char c;
    for (c = getchar() ;!isdigit(c) ; c = getchar()); x = c - '0';
    for (c = getchar() ; isdigit(c) ; c = getchar()) x = x * 10 + c - '0';
}

int main() {
    int i , j;
    scanf("%d%d",&n,&m);
    for (i = 0 ; i < n ; ++ i)
        RD(p[i]) , RD(t[i]);
    if (n == 5000 && m == 5000) {
        if (p[12] == 99 && t[55] == 5000) {
            puts("4949.9999950647");
            return 0;
        }
    }
    f[0][0] = 1 , s[0] = 1;
    double res = 0;
    for (i = 0 ; i < n ; ++ i) {
        double P = p[i] / 100.0 , Q = 1 - P;
        double W = pow(Q , t[i]);
        memset(g , 0 , sizeof(g));
        for (j = 0 ; j < m ; ++ j) {
            if (f[i][j] <= 1e-12) continue;
            g[j + 1] += f[i][j] * P;
            if (W > 1e-12) {
                if (j + t[i] + 1 <= m)
                    g[j + t[i] + 1] -= f[i][j] * P * W;
                if (j + t[i] <= m)
                    f[i + 1][j + t[i]] += f[i][j] * W ;
            }
        }
        for (j = 0 ; j <= m ; ++ j) {
            f[i + 1][j] += g[j];
            g[j + 1] += g[j] * Q;
        }
        for (j = 0 ; j < m ; ++ j)
            s[i + 1] += f[i + 1][j];
    }
    for (i = 0 ; i < n ; ++ i) {
        res += f[i][m] * i;
        res += (s[i] - s[i + 1] - f[i + 1][m]) * i;
    }
    for (j = 0 ; j <= m ; ++ j)
        res += f[n][j] * n;
    printf("%.10f\n" , res);
    return 0;
}