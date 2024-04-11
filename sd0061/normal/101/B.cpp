#include <iostream>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>
#include <set>
using namespace std;

#define N 200005
int n , m , d[N] , D;
pair<int , int> a[N >> 1];
int c[N] , Q = 1e9 + 7;
void work()
{
    int i , j , x , y , z , ans;
    scanf("%d%d",&n,&m);
    d[D ++] = 0 , d[D ++] = n;
    for (i = 0 ; i < m ; ++ i)
    {
        scanf("%d%d",&a[i].second , &a[i].first);
        d[D ++] = a[i].first , d[D ++] = a[i].second;
    }
    sort(a , a + m);
    sort(d , d + D) , D = unique(d , d + D) - d;
    for (j = 1 ; j <= D ; j += j & -j) ++ c[j];
    for (i = 0 ; i < m ; ++ i)
    {
        y = lower_bound(d , d + D , a[i].first) - d + 1;
        x = lower_bound(d , d + D , a[i].second) - d + 1;
        ans = 0;
        for (j = y - 1 ; j ; j -= j & -j)
            ans += c[j] , ans %= Q;
        for (j = x - 1 ; j ; j -= j & -j)
            ans += Q - c[j] , ans %= Q;
        for (j = y ; j <= D ; j += j & -j)
            c[j] += ans , c[j] %= Q;
    }
    ans = 0;
    x = y = D;
    for (j = y ; j ; j -= j & -j) ans += c[j] , ans %= Q;
    for (j = x - 1 ; j ; j -= j & -j) ans += Q - c[j] , ans %= Q;
    cout << ans << endl;
}

int main()
{
    //freopen("~input.txt" , "r" , stdin);
    //while (~scanf("%d%d%d%d",&n,&m,&C,&D))
    //int _; scanf("%d",&_); while (_ --)
        work();
    return 0;
}