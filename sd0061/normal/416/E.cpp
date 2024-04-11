#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <stack>
#include <cmath>
#include <cassert>
using namespace std;
typedef long long LL;

#define N 505
int n , m;
int g[N][N] , f[N][N];
int cnt[N][N] , res[N][N];

void work() {
    int i , j , k,  x , y , z;
    scanf("%d%d",&n,&m);
    memset(g , 63 , sizeof(g));
    for (i = 0 ; i < m ; ++ i) {
        scanf("%d%d%d",&x,&y,&z);
        g[x][y] = g[y][x] = z;
    }
    memcpy(f , g , sizeof(f));
    for (i = 1 ; i <= n ; ++ i)
        f[i][i] = 0;
    for (k = 1 ; k <= n ; ++ k)
       for (i = 1 ; i <= n ; ++ i)
           for (j = 1 ; j <= n ; ++ j) {
               f[i][j] = min(f[i][j] , f[i][k] + f[k][j]);
           }
    //for (i = 1 ; i <= n ; ++ i) {
    //    for (j = 1 ; j <= n ; ++ j)
    //        printf("%d%c" , g[i][j] , " \n"[j == n]);
    //} puts("");
    for (i = 1 ; i <= n ; ++ i)
        for (j = 1 ; j <= n ; ++ j) if (f[i][j] < 0x3f3f3f3f) {
            for (k = 1 ; k <= n ; ++ k)
                if (g[i][k] + f[k][j] == f[i][j])
                    ++ res[i][j];
        }
    for (i = 1 ; i <= n ; ++ i)
        for (j = 1 ; j <= n ; ++ j) if (f[i][j] < 0x3f3f3f3f) {
            for (k = 1 ; k <= n ; ++ k)
                if (f[i][k] + f[k][j] == f[i][j])
                    cnt[i][j] += res[k][j];
        }
    /*for (k = 0 ; k < m ; ++ k) {
        z = e[k].first;
        x = e[k].second.first , y = e[k].second.second;
        for (i = 1 ; i <= n ; ++ i)
            for (j = 1 ; j <= n ; ++ j) {
                if (g[i][x] + z + g[y][j] == g[i][j])
                    ++ cnt[i][j];
                if (g[i][y] + z + g[x][j] == g[i][j])
                    ++ cnt[i][j];
            }
    }*/
    for (i = 1 ; i <= n ; ++ i) {
        for (j = i + 1 ; j <= n ; ++ j)
            printf("%d%c" , cnt[i][j] , " \n"[j == n]);
    }




}

int main(){
    work();
    return 0;
}