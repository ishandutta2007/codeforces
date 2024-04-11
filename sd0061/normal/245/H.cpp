#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;
#define N 5005
char s[N];
int d[N][N] , l , n ,ss[N][N];
bool f[N][N];
int main()
{
  int i , j , k , x , y;
  scanf("%s\n",s); 
  l = strlen(s);
  for (i = 1 ; i <= l ;i ++)
    f[i][i - 1] = f[i][i] = 1;
  for (k = 2 ; k <= l ; k ++)
    for (i = 1 ; i + k - 1 <= l ;i ++)
    {
      if (s[i - 1] == s[i + k - 2] && f[i + 1][i + k - 2]) 
        f[i][i + k - 1] = 1;   
    }       
  for (i = 1 ; i <= l ;i ++)
    for (j = i ; j <= l ;j ++)
      ss[i][j] = ss[i - 1][j] + f[i][j];
  for (i = 1 ; i <= l ;i ++)
    for (j = i ; j <= l ;j ++)
      d[i][j] = d[i][j - 1] + ss[j][j] - ss[i - 1][j];     
  cin >> n;
  while (n --)
  {
    scanf("%d%d",&x,&y);
    printf("%d\n",d[x][y]);    
  }        
  return 0;    
}