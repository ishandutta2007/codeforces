#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;
#define N 405
int n , m , K ;
long long ans;
int s[N][N] , w[N];
char a[N][N];
int t[26][N];
int top[26] , bot[26];

int main()
{
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  int i , j, k ,x , y ;
  scanf("%d%d%d\n",&n,&m,&K);
  for (i = 1 ;i <= n ;i ++)
    scanf("%s\n",a[i] + 1);
  for (i = 1 ;i <= n ;i ++)
    for (j = 1 ; j <= m ;j ++)
      s[i][j] = s[i][j - 1] + (a[i][j] == 'a');

  for (i = 1 ;i <= m ;i ++)
    for (j = i + 1 ;j <= m ;j ++)
    {
       memset(w, 0 , sizeof(w));
       for (k = 0 ;k < 26 ;k ++)
         top[k] = 1 , bot[k] = 0;
       for (k = 1 ; k <= n; k ++)
       {
          if (a[k][i] == a[k][j])
          {
            y = a[k][i] - 'a';
            w[k] = w[k - 1] + s[k][j] - s[k][i - 1];
            while (top[y] <= bot[y] && w[k] - w[t[y][top[y]]] > K)
              top[y] ++;
            ans += bot[y] - top[y] + 1;
            t[y][++ bot[y]] = k - 1;
          }
          else
            w[k] = w[k - 1] + s[k][j] - s[k][i - 1];
       }
    }
  cout << ans << endl;
  return 0;
}