#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
typedef long long LL;
#define N 1005
int n , m , Q , a[N][N];
int U[N][N] , D[N][N] , L[N][N] , R[N][N];
int h[N] , ans , l[N] , r[N] , s[N] , top;

void cal(int M , int p) {
    int i ;
    for (i = 1 ; i <= M ; ++ i) {
        while (top && h[s[top]] > h[i])
            r[s[top --]] = i;
        s[++ top] = i;
    }
    while (top) r[s[top --]] = i;
    for (i = M ; i >= 1 ; -- i) {
        while (top && h[s[top]] > h[i])
            l[s[top --]] = i;
        s[++ top] = i;
    }
    while (top) l[s[top --]] = i;
    for (i = 1 ; i <= M ; ++ i) {
        if (l[i] < p && p < r[i])
            ans = max(ans , h[i] * (r[i] - l[i] - 1));
    }
}

void work() {
    int i , j , x , y;
    scanf("%d%d%d",&n,&m,&Q);
    for (i = 1 ; i <= n ; ++ i)
        for (j = 1 ; j <= m ; ++ j)
            scanf("%d" , &a[i][j]);
    for (i = 1 ; i <= n ; ++ i)
        for (j = 1 ; j <= m ; ++ j) {
            if (a[i][j])
                U[i][j] = U[i - 1][j] + 1 , L[i][j] = L[i][j - 1] + 1;
            else
                U[i][j] = L[i][j] = 0;
        }
    for (i = n ; i >= 1 ; -- i)
        for (j = m ; j >= 1 ; -- j) {
            if (a[i][j])
                D[i][j] = D[i + 1][j] + 1 , R[i][j] = R[i][j + 1] + 1;
            else
                D[i][j] = R[i][j] = 0;
        }
    while (Q --) {
        scanf("%d%d%d",&i,&x,&y);
        if (i == 1) {
            a[x][y] ^= 1;
            for (i = 1 ; i <= n ; ++ i)
                if (a[i][y])
                    U[i][y] = U[i - 1][y] + 1;
                else
                    U[i][y] = 0;
            for (i = n ; i >= 1 ; -- i)
                if (a[i][y])
                    D[i][y] = D[i + 1][y] + 1;
                else
                    D[i][y] = 0;
            for (i = 1 ; i <= m ; ++ i)
                if (a[x][i])
                    L[x][i] = L[x][i - 1] + 1;
                else
                    L[x][i] = 0;
            for (i = m ; i >= 1 ; -- i)
                if (a[x][i])
                    R[x][i] = R[x][i + 1] + 1;
                else
                    R[x][i] = 0;
        } else {
            ans = 0;
            for (i = 1 ; i <= n ; ++ i)
                h[i] = L[i][y];
            cal(n , x);
            for (i = 1 ; i <= n ; ++ i)
                h[i] = R[i][y];
            cal(n , x);
            for (i = 1 ; i <= m ; ++ i)
                h[i] = U[x][i];
            cal(m , y);
            for (i = 1 ; i <= m ; ++ i)
                h[i] = D[x][i];
            cal(m , y);
            printf("%d\n" , ans);
        }
    }

}

int main()
{
    work();
    return 0;
}