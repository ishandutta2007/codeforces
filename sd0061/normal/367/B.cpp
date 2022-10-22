#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#include <set>
#include <string>
#define N 200005
using namespace std;
typedef long long LL;
int n , m , a[N] , b[N] , q;
vector<int> ans;
int c[N] , p;
int d[N] , D;
int num[N] , f[N];
void work()
{
    int i , j , k , x , y;LL l;
    scanf("%d%d%d",&n,&m,&q) , l =(LL) (m - 1) * q;
    for (i = 1 ; i <= n ; ++ i)
        scanf("%d",&a[i]);
    for (j = 1 ; j <= m ; ++ j)
        scanf("%d",&b[j]) , d[D ++] = b[j];
    sort(d , d + D) , D = unique(d , d + D) - d;
    for (j = 1 ; j <= m ; ++ j)
        b[j] = lower_bound(d , d + D , b[j]) - d , ++ f[b[j]];
    for (j = 1 ; j <= n ; ++ j)
    {
        x = lower_bound(d , d + D , a[j]) - d;
        if (d[x] != a[j]) a[j] = D;
        else a[j] = x;
    }
    for (i = 1 ; i <= q ; ++ i)
    {
        if (i + l > n) continue;
        memset(num , 0 , sizeof(num));
        for (j = i , k = 0 ; k < m ; j += q  , ++ k)
            ++ num[a[j]];
        for ( ; j <= n ; j += q)
        {
            for (k = D ; k >= 0 ; -- k)
                if (num[k] != f[k])
                    break;
            if (k < 0) ans.push_back(j - m * q);
            -- num[a[j - m * q]];
            ++ num[a[j]];
        }
            for (k = D ; k >= 0 ; -- k)
                if (num[k] != f[k])
                    break;
            if (k < 0) ans.push_back(j - m * q);
    }
    sort(ans.begin() , ans.end());
    printf("%d\n" , ans.size());
    for (i = 0 ; i < ans.size(); ++ i)
        printf("%d " , ans[i]);
}


int main()
{
    //freopen("~input.txt" , "r" , stdin);
        work();
    return 0;
}