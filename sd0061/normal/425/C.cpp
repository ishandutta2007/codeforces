#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
#include <stack>
#include <vector>
#include <queue>
#include <cmath>
#include <cassert>
using namespace std;
typedef long long LL;

#define N 100005
int n , m , T , S , E;
int a[N] , b[N];
int f[N][302] , g[N];
int p[N][302];

void work() {
    int i , j ;
    scanf("%d%d%d%d",&n,&m,&S,&E);
    for (i = 1 ; i <= n ; ++ i) {
        scanf("%d",&a[i]);
    }
    for (i = 1 ; i <= m ; ++ i) {
        scanf("%d",&b[i]);
    }
    T = S / E;
    memset(f , 63 , sizeof(f));
    for (i = 0 ; i <= T ; ++ i)
        g[i] = m + 1;
    for (i = 0 ; i <= T ; ++ i)
        for (j = 1 ; j <= 100000 ; ++ j)
            p[j][i] = m + 1;
    for (j = m ; j >= 1 ; -- j) {
        p[b[j]][0] = j;
    }
    f[0][0] = 0 , g[0] = 0;
    for (i = 1 ; i <= n ; ++ i) {
        for (j = T ; j >= 0 ; -- j) {
            f[i][j] = f[i - 1][j];
            if (j) {
                int k = p[a[i]][j - 1];
                if (k <= m)
                    f[i][j] = min(f[i][j] , k);
            }
            while (f[i][j] < g[j]) {
                p[b[g[j]]][j] = g[j];
                -- g[j];
            }
        }
    }
    int ans = 0;
    for (i = 0 ; i <= n ; ++ i)
        for (j = 0 ; j <= T ; ++ j) {
            if (i + f[i][j] + j * E <= S)
                ans = max(ans , j);
        }
    printf("%d\n" , ans);
}

int main(){
    work();
    return 0;
}