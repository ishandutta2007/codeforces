#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long LL;
#define N 200002
int n , a[N] , m ;
int cnt[1000002];
#define P 9
struct query
{
  int l , r , id;
  bool operator < (const query& p) const{
    int ll = l >> P , rr = p.l >> P;
    if (ll != rr) return ll < rr;
    return r < p.r;  }
}q[N];
LL ans[N];

void work()
{
    int i , l , r , x , y;
    scanf("%d%d",&n,&m);
    for (i = 1 ; i <= n ; ++ i)
        scanf("%d",&a[i]);
    for (i = 1 ; i <= m ; ++ i)
        scanf("%d%d",&q[i].l , &q[i].r) , q[i].id = i;
    sort(q + 1 , q + 1 + m);

    l = 1 , r = 1 , ++ cnt[a[1]];
    LL res = a[1];
    for (i = 1 ; i <= m ; ++ i)
    {
        x = q[i].l , y = q[i].r;
        //printf("%d\n" , i);
        while (l < x)
        {
            -- cnt[a[l]];
            res -= (LL) (cnt[a[l]] << 1 | 1) * a[l];
            ++ l;
        }
        while (l > x)
        {
            -- l;
            res += (LL) (cnt[a[l]] << 1 | 1) * a[l];
            ++ cnt[a[l]];
        }
        while (r < y)
        {
            ++ r;
            res += (LL) (cnt[a[r]] << 1 | 1) * a[r];
            ++ cnt[a[r]];
        }
        while (r > y)
        {
            -- cnt[a[r]];
            res -= (LL) (cnt[a[r]] << 1 | 1) * a[r];
            -- r;
        }
        ans[q[i].id] = res;
    }
    for (i = 1 ; i <= m ; ++ i)
        printf("%I64d\n" , ans[i]);
}

int main()
{
    work();
    return 0;
}