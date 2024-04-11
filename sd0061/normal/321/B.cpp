#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <map>
using namespace std;
#define N 105
#define sqr(x) ((long long)(x)*(x))
int n , m , K;
int p[N];
int d[N] , a[N];
char s[N];

int f[N][N][N][2];

int main()
{
   int i , j , k , x , v = 0;
   scanf("%d%d",&j,&K);
   while (j --)
   {
     scanf("%s %d" , s , &x);
     if (s[0] == 'A')
       a[++ m] = x;
     else d[++ v] = x;
   }
   for (i = 1 ; i <= K ; ++ i)
     scanf("%d",&p[i]);
   sort(p + 1 , p + K + 1);
   sort(a + 1 , a + m + 1);
   sort(d + 1 , d + v + 1);
   for (k = 0 ; k <= K ; ++ k)
     for (i = 0 ; i <= m ; ++ i)
       for (j = 0 ; j <= v ; ++ j)
         f[k][i][j][1] = f[k][i][j][0] = -1 << 30;
   f[0][0][0][0] = f[0][0][0][1] = 0;
   int ans = -1 << 30; p[K + 1] = -1 << 30;
   for (i = 0 ; i < K ; ++ i)
     for (j = 0 ; j <= m ; ++ j)
       for (k = 0 ; k <= v ; ++ k)// if (f[i][j][k] >= 0)
       {
         f[i + 1][j][k][0] = max(f[i + 1][j][k][0] , f[i][j][k][0]);
         f[i + 1][j][k][1] = max(f[i + 1][j][k][1] , f[i][j][k][1] + p[i + 1]);
         if (p[i + 1] >= a[j + 1])
            f[i + 1][j + 1][k][0] = max(f[i + 1][j + 1][k][0] , f[i][j][k][0] + p[i + 1] - a[j + 1]),
            f[i + 1][j + 1][k][1] = max(f[i + 1][j + 1][k][1] , f[i][j][k][1] + p[i + 1] - a[j + 1]);
         if (p[i + 1]  > d[k + 1])
            f[i + 1][j][k + 1][0] = max(f[i + 1][j][k + 1][0] , f[i][j][k][0]),
            f[i + 1][j][k + 1][1] = max(f[i + 1][j][k + 1][1] , f[i][j][k][1]);
       }
   for (i = 0 ; i <= K ; ++ i)
     for (j = 0 ; j <= m ; ++ j)
       for (k = 0 ; k <= v ; ++ k)
         ans = max(f[i][j][k][0] , ans);
   ans = max(f[K][m][v][1] , ans);
   cout << ans << endl;
   return 0;
}