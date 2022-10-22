#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>
#include <cctype>
#include <queue>
#include <cmath>
using namespace std;
typedef long long LL;
const int N = 1005;
int n;
int p[N][N];
bool f[N];
double d[N] , K[N] , B[N];


int main() {

    scanf("%d" , &n);
    for (int i = 1 ; i <= n ; ++ i)
        for (int j = 1 ; j <= n ; ++ j) {
            scanf("%d" , &p[i][j]);
            if (i == j) p[i][j];
        }
    for (int i = 1 ; i <= n ; ++ i) {
        d[i] = 1e60;
        K[i] = 1;
        B[i] = 1;
    }
    d[n] = 0;
    while (1) {
        int x = -1;
        for (int i = 1 ; i <= n ; ++ i)
            if (!f[i] && (!~x || d[i] < d[x]))
                x = i;
        f[x] = 1;
        if (x == 1) break;
        for (int i = 1 ; i <= n ; ++ i) {
            if (f[i] || !p[i][x])
                continue;
            B[i] += K[i] * 0.01 * p[i][x] * d[x];
            K[i] *= 1 - 0.01 * p[i][x];
            d[i] = min(d[i] , B[i] / (1 - K[i]));            
        }        
    }
    printf("%.12f\n" , d[1]);
    return 0;
}