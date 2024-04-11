#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <list>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
//#pragma comment(linker, "/STACK:16777216")
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define N 105
int n , a[N];
int f[N][10] , Q = 1e9 + 7;
int C[N][N];
/*
Recount:
- f(len,0) = sum(f(len-i,1)*C(len-1,i), i=a[0]..len);
- f(len,j) = sum(f(len-i,j+1)*C(len,i), i=a[j]..len), 0<j<9;
- f(len,9) = 1,  len>=a[9], 0  len<a[9].
C(n,k)  binomial coefficient.
*/

void work()
{
    int i , j , k;
    scanf("%d",&n);
    for (i = 0 ; i < 10 ; ++ i)
        scanf("%d",&a[i]);
    for (i = 0 ; i <= n ; ++ i)
    {
        C[i][0] = 1;
        for (j = 1 ; j <= i ; ++ j)
            C[i][j] = C[i - 1][j - 1] + C[i - 1][j] , C[i][j] %= Q;
    }
    for (i = 0 ; i <= n ; ++ i)
    {
        f[i][9] = i >= a[9];
        for (k = 8 ; k >= 1 ; -- k)
            for (j = a[k] ; j <= i ; ++ j)
                f[i][k] += (LL) f[i - j][k + 1] * C[i][j] % Q , f[i][k] %= Q;
        for (j = a[k] ; j <= i ; ++ j)
            f[i][k] += (LL) f[i - j][k + 1] * C[i - 1][j] % Q , f[i][k] %= Q;
    }
    int ans = 0;
    for (i = 0 ; i <= n ; ++ i)
        ans += f[i][0] , ans %= Q;
    printf("%d\n" , ans);
}

int main()
{
    work();
    return 0;
}