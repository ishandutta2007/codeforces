#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <ctype.h>
#include <cstdlib>
#include <cstring>
#include <functional>

#define pi M_PI
#define maxn 400

using namespace std;

int n;
int pr[maxn][maxn], al[maxn], used[maxn], t[maxn];

int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            scanf("%d", &pr[i][j]);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &al[i]);
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= n; ++j){used[j] = 0; t[j] = 0;}
        for (int j = 1; j <= n; ++j){
            int k = 1;
            while ((al[k] == i || al[k] > j) && k <= n) ++k;
            if (k <= n){
                used[al[k]] = 1;
                t[al[k]] = j;
            }
        }
        int j = 1;
        while (used[pr[i][j]] == 0) ++j;
        /*for (int j = 1; j <= n; ++j)
            printf("t[%d] = %d\n", j, t[j]);*/
        printf("%d ", t[pr[i][j]]);
    }
    return 0;
}