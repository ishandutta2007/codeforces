#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <cstdio>
#include <algorithm>
#define N 25005
using namespace std;
int n , m , d , pos;
long long ans;
char s[101][10001];
int main()
{
  int i ,j , x , y;
  scanf("%d %d",&n,&m);
  for (i = 1 ;i <= n ;i ++)
    scanf("%s\n",s[i] + 1);
    
  pos = 1 , d = 1;  
  for (i = 1 ;i < n ;i ++)
  {
    int l = pos - 1 , r = pos + 1;
    if (s[i + 1][pos] == '.')
    {
      ans ++;
      continue;      
    }  
    pos = -1;
    while (l && s[i][l] != '#' || r <= m && s[i][r] != '#')
      if (d)
      {
        ans += r - l - 2;
        while (r <= m && s[i + 1][r] != '.' && s[i][r] =='.')
          r ++ , ans ++;
        if (s[i][r] == '.' && s[i + 1][r] == '.')
        {
          pos = r;
          break;          
        }       
        d = 0 , ans ++;
        if (s[i][r] == '+')
          s[i][r] = '.'; 
      }
      else
      {
        ans += r - l -2;
        while (l && s[i + 1][l] != '.' && s[i][l] == '.')
          l -- , ans ++;
        if (s[i][l] == '.' && s[i + 1][l] == '.')
        {
          pos = l;
          break;          
        }   
        d = 1 , ans ++;
        if (s[i][l] == '+')
          s[i][l] = '.'; 
      }
    if (pos < 0)
    {
      printf("Never\n");
      return 0;      
    }  
    ans += 2;
  }  
  cout << ans << endl;
  return 0;
}