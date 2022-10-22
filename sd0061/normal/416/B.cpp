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

#define N 50000
int m , n , t[N][5];
int f[N][5];

void work() {
    int i , j;
    scanf("%d%d",&m,&n);
    for (i = 0 ; i < m ; ++ i)
        for (j = 0 ; j < n ; ++ j)
            scanf("%d",&t[i][j]);
    for (i = 0 ; i < m ; ++ i) {
        for (j = 0 ; j < n ; ++ j) {
            if (i == 0 && j == 0)
                f[i][j] = t[i][j];
            else if (i == 0) {
                f[i][j] = f[i][j - 1] + t[i][j];
            } else if (j == 0) {
                f[i][j] = f[i - 1][j] + t[i][j];
            }
            else {
                f[i][j] = max(f[i - 1][j] , f[i][j - 1]) + t[i][j];
            }
        }
        printf("%d " , f[i][n - 1]);
    }

}

int main(){
    //freopen("1.txt" , "r" , stdin);
        work();
    return 0;
}