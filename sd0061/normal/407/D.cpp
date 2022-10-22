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

#define N 405
using namespace std;
int n , m , a[N][N];
int f[N][N];
int L[160000][N];
void work()
{
    int i , j , k , ans = 0;
    scanf("%d%d",&n,&m);
    for (i = 1 ; i <= n ; ++ i)
        for (j = 1 ; j <= m ; ++ j)
            scanf("%d",&a[i][j]) , -- a[i][j];
    for (i = 1 ; i <= m ; ++ i)
        for (j = 1 ; j <= m ; ++ j)
            f[i][j] = 1;
    for (i = 1 ; i <= n ; ++ i) {
        for (j = 1 ; j <= m ; ++ j) {
            for (k = 1 ; k <= j ; ++ k)
                f[k][j] = max(f[k][j] , L[a[i][j]][k]);
            for (k = j + 1 ; k <= m ; ++ k)
                f[j][k] = max(f[j][k] , L[a[i][j]][k]);
            L[a[i][j]][j] = i + 1;
        }
        for (j = 2 ; j <= m ; ++ j) {
            for (k = 1 ; k + j - 1 <= m ; ++ k) {
                f[k][k + j - 1] = max(f[k][k + j - 1] , f[k + 1][k + j - 1]);
                f[k][k + j - 1] = max(f[k][k + j - 1] , f[k][k + j - 2]);
            }
        }
        for (j = 1 ; j <= m ; ++ j)
            for (k = j ; k <= m ; ++ k)
                ans = max(ans , (k - j + 1) * (i - f[j][k] + 1));
    }
    cout << ans << endl;
}

int main()
{
    work();
    return 0;
}