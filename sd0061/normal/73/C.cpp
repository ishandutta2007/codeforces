#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <map>
using namespace std;

int n , m , K;
char s[1005];
int f[102][102][27];
int g[27][27];

int main()
{
   int i , j , k , l; char a[3] , b[3];
   scanf("%s%d%d" , s + 1 , &m ,&j);
   n = strlen(s + 1);
   while (j --)
   {
     scanf("%s%s%d",a,b,&i);
     g[a[0]-'a'][b[0]-'a'] = i;
   }
   for (i = 0 ; i <= m ; ++ i)
      for (j = 0 ; j < 26 ; ++ j)
        f[0][i][j] = -1 << 30;
   f[0][0][0] = 0;

   for (i = 1 ; i <= n ; ++ i)
     for (j = 0 ; j <= m ; ++ j)
        for (k = 0 ; k < 26 ; ++ k)
        {
          f[i][j][k] = -1 << 30;
          for (l = 0 ; l < 26 ; ++ l)
          {

            if (k == s[i] - 'a')
              f[i][j][k] = max(f[i][j][k] , f[i - 1][j][l] + (i != 1) * g[l][k]);
            else if (j > 0)
              f[i][j][k] = max(f[i][j][k] , f[i - 1][j - 1][l] + (i != 1) * g[l][k]);
          }
        }
   int ans = -1 << 30;
   for (i = 0 ; i <= m ; ++ i) for (j = 0 ; j < 26 ; ++ j)
     ans = max(ans , f[n][i][j]);
   cout << ans << endl;
   return 0;
}