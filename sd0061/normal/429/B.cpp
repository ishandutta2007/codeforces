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
using namespace std;
typedef long long LL;
#define N 1005
int n , m;
int a[N][N];
int A[N][N] , B[N][N] , C[N][N] , D[N][N];


void work()
{
    int i , j , x , y;
    scanf("%d%d",&n,&m);
    for (i = 1 ; i <= n ; ++ i)
        for (j = 1 ; j <= m ; ++ j)
            scanf("%d" , &a[i][j]);
    memset(A , 0x80 , sizeof(A));
    memset(B , 0x80 , sizeof(A));
    memset(C , 0x80 , sizeof(A));
    memset(D , 0x80 , sizeof(A));

    A[1][1] = 0;
    for (i = 1 ; i <= n ; ++ i)
        for (j = 1 ; j <= m ; ++ j) {
            if (i > 1) A[i][j] = max(A[i - 1][j] , A[i][j]);
            if (j > 1) A[i][j] = max(A[i][j - 1] , A[i][j]);
            A[i][j] += a[i][j];
        }
    C[n][m] = 0;
    for (i = n ; i > 0 ; -- i)
        for (j = m ; j > 0 ; -- j) {
            if (i < n) C[i][j] = max(C[i + 1][j] , C[i][j]);
            if (j < m) C[i][j] = max(C[i][j + 1] , C[i][j]);
            C[i][j] += a[i][j];
        }
    B[n][1] = 0;
    for (i = n ; i > 0 ; -- i)
        for (j = 1 ; j <= m ; ++ j) {
            if (i < n) B[i][j] = max(B[i + 1][j] , B[i][j]);
            if (j > 1) B[i][j] = max(B[i][j - 1] , B[i][j]);
            B[i][j] += a[i][j];
        }
    D[1][m] = 0;
    for (i = 1 ; i <= n ; ++ i)
        for (j = m ; j > 0 ; -- j) {
            if (i > 1) D[i][j] = max(D[i - 1][j] , D[i][j]);
            if (j < m) D[i][j] = max(D[i][j + 1] , D[i][j]);
            D[i][j] += a[i][j];
        }
    int ans = -1 << 30;
    for (i = 2 ; i <= n - 1 ; ++ i)
        for (j = 2 ; j <= m - 1 ; ++ j) {
            ans = max(ans , A[i][j - 1] + C[i][j + 1] + B[i + 1][j] + D[i - 1][j]);
            ans = max(ans , B[i][j - 1] + D[i][j + 1] + C[i + 1][j] + A[i - 1][j]);
        }
    printf("%d\n" , ans);
}

int main()
{
    work();
    return 0;
}