#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
#define N 100005
typedef long long LL;

int n , m , q , M;
int a[N] , size[N];
vector<int> s[N];
int id1[N] , cnt1 , p1[N];
int cnt[320][N];
bool f[N];
LL sum[320] , d[N] , tot[N];
int main()
{
    int i , j , x , y;
    scanf("%d%d%d",&n,&m,&q);
    for (i = 1 ; i <= n ; ++ i)
        scanf("%d",&a[i]);
    for (i = 1 ; i <= m ; ++ i)
    {
        scanf("%d",&j) , size[i] = j , M += j;
        while (j --)
            scanf("%d",&x) , s[i].push_back(x) , tot[i] += a[x];
    }
    M = sqrt(M);
    for (i = 1 ; i <= m ; ++ i)
        if (size[i] >= M)
            id1[++ cnt1] = i , p1[i] = cnt1;

    for (i = 1 ; i <= cnt1 ; ++ i)
    {
        memset(f , 0 , sizeof(f));
        x = id1[i];
        for (j = 0 ; j < size[x] ; ++ j)
            f[s[x][j]] = 1;
        for (j = 1 ; j <= m ; ++ j)
            for (int k = 0 ; k < size[j] ; ++ k)
                cnt[i][j] += f[s[j][k]];
    }
    char str[5];
    while (q --)
    {
        scanf("%s" , str);
        if (*str == '+')
        {
            scanf("%d%d",&x,&y);
            if (size[x] >= M)
                sum[p1[x]] += y;
            else
            {
                for (i = 0 ; i < size[x] ; ++ i)
                    d[s[x][i]] += y;
                for (i = 1 ; i <= cnt1 ; ++ i)
                    tot[id1[i]] += (LL)cnt[i][x] * y;
            }
        }
        else
        {
            scanf("%d",&x);
            LL ans = tot[x];
            if (size[x] >= M)
            {
                for (i = 1 ; i <= cnt1 ; ++ i)
                    ans += (LL)cnt[i][x] * sum[i];
                printf("%I64d\n" , ans);
            }
            else
            {
                for (i = 0 ; i < size[x] ; ++ i)
                    ans += d[s[x][i]];
                for (i = 1 ; i <= cnt1 ; ++ i)
                    ans += (LL)cnt[i][x] * sum[i];
                printf("%I64d\n" , ans);
            }
        }
    }
    return 0;
}