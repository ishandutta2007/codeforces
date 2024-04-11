#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define N 105
int n , k;
int q[N] , s[N] , a[N] , p[N];

int main()
{
    //freopen("~input.txt","r",stdin);
    int i , j , x , y;
    scanf("%d%d",&n,&k);
    for (i = 1 ; i <= n ; ++ i)
        scanf("%d" , &q[i]) , p[i] = i;
    for (i = 1 ; i <= n ; ++ i)
        scanf("%d" , &s[i]);
    for (j = 0 ; j <= k ; ++ j)
    {
      for (i = 1 ; i <= n ; ++ i)
         if (p[i] != s[i])
            break;
      if (i > n) break;
      for (i = 1 ; i <= n ; ++ i) a[i] = p[q[i]];
      memcpy(p , a , sizeof(a));
    }
    x = j;

    for (i = 1 ; i <= n ; ++ i) p[i] = i;
    for (j = 0 ; j <= k ; ++ j)
    {
      for (i = 1 ; i <= n ; ++ i)
         if (p[i] != s[i])
            break;
      if (i > n) break;
      for (i = 1 ; i <= n ; ++ i) a[q[i]] = p[i];
      memcpy(p , a , sizeof(a));
    }
    y = j;

    if (x == k || y == k) puts("YES");
    else if ((x % 2 == k % 2 || y % 2 == k % 2) && x + y > 2) puts("YES");
    else puts("NO");
    return 0;
}