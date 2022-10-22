#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;
#define N 5005
#define LL long long
int n , a[N] , s[N];
int f[N][N];
int q[N] , top , bot;
int main()
{
   int i , j , x;
   scanf("%d",&n);
   for (i = 1 ; i <= n ; ++ i)
     scanf("%d",&a[i]) , s[i] = s[i - 1] + a[i] , f[i][1] = s[i];

   for (j = 2 ; j <= n ; ++ j)
   {
     top = 0 , bot = -1;
     for (i = j - 1 ; i <= n ; ++ i)
        if (f[i][j - 1])
          q[++ bot] = i;
     for (i = n ; i >= j ; -- i)
     {
       while (top <= bot && s[i] < f[q[bot]][j - 1] + s[q[bot]])
         -- bot;
       if (top <= bot)
         f[i][j] = s[i] - s[q[bot]];
      // printf("%d %d : %d\n" , i , j , f[i][j]);
     }
   }
   for (i = n ; i > 0 ; -- i)
     if (f[n][i])
       break;
   printf("%d" , n - i);
   return 0;
}