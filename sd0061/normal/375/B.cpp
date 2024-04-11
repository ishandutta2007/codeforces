#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
const int N = 5002;
typedef unsigned long long ULL;
int n , m ;
char s[N][N];
int f[N][N] , cnt[N];

void work()
{
    int i , j , x , ans = 0;
    scanf("%d%d",&n,&m);
    for (i = 1 ; i <= n ; ++ i)
        scanf("%s" , s[i] + 1);
    for (i = 1 ; i <= n ; ++ i)
        for (j = 1 ; j <= m ; ++ j)
        {
            x = s[i][j] - '0';
            f[j][i] = x ? f[j - 1][i] + 1 : 0;
        }
    cnt[0] = n;
    for (i = 1 ; i <= m ; ++ i)
    {
        for (j = 1 ; j <= n ; ++ j)
            -- cnt[f[i - 1][j]] , ++ cnt[f[i][j]];
        x = 0;
        for (j = m ; j > 0 ; -- j)
        {
            x += cnt[j];
            ans = max(ans , x * j);
        }
    }
    printf("%d\n" , ans);
}

int main()
{
//    freopen("~input.txt" , "r" , stdin);
//    int _; scanf("%d",&_); while (_ --)
//    while (scanf("%d%d",&n,&k) , n || k)
        work();
    return 0;
}