#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
using namespace std;
typedef long long LL;

#define N 100105
using namespace std;
int n , m , a[N];
int C[N][101] , Q = 1e9 + 7;
int ans[102][N];
void work()
{
    int i , j , l , r , k;
    scanf("%d%d",&n,&m);
    for (i = 1 ; i <= n ; ++ i)
        scanf("%d",&a[i]);
    for (i = 0 ; i <= n + 100 ; ++ i) {
        C[i][0] = 1;
        for (j = 1 ; j <= 100 && j <= i ; ++ j)
            C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % Q;
    }
    for (i = 0 ; i < m ; ++ i) {
        scanf("%d%d%d",&l,&r,&k);
        ++ ans[k][l] , ans[k][l] %= Q;
        for (j = 0 ; j <= k ; ++ j)
            ans[j][r + 1] += Q - C[r - l + k - j][k - j] , ans[j][r + 1] %= Q;
    }
    for (j = 100 ; j >= 0 ; -- j) {
        for (i = 1 ; i <= n ; ++ i) {
            ans[j][i] += ans[j + 1][i] , ans[j][i] %= Q;
            ans[j][i] += ans[j][i - 1] , ans[j][i] %= Q;
        }
    }
    for (i = 1 ; i <= n ; ++ i) {
        printf("%d%c" , (a[i] + ans[0][i]) % Q , " \n"[i == n]);
    }
}

int main()
{
    work();
    return 0;
}