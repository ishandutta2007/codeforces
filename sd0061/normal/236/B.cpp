#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;
int a , b, c , sum ,p[105] , cnt[105][105];
#define Q 1073741824
long long ans, w;
bool f[105];
int main()
{
  cin >> a >> b >> c;
  int i ,j, k, x , l;
  for (i = 2 ; i <= 100 ;i ++)
    if (!f[i])
      for (j = 2 ; i * j <= 100 ; j ++)
        f[i * j] = 1;
  for (i = 2 ; i <= 100 ;i ++)
    if (!f[i])
      p[++ sum] = i;
  for (i = 2 ; i <= 100 ;i ++)
  {
    x = i;
    for (j = 1; j <= sum ;j ++)
      while (x % p[j] == 0)
        x /= p[j] , cnt[i][j] ++;  
  }    
  for (i = 1 ; i <= a ; i ++)
    for (j = 1 ; j <= b ; j ++)
      for (k = 1 ; k <= c ; k ++)
      {
        w = 1;
        for (l = 1 ; l <= sum ; l ++)
          w *= (cnt[i][l] + cnt[j][l] + cnt[k][l] + 1) , sum %= Q;
        ans += w , ans %= Q;  
      }
  cout << ans;
  return 0;  
}