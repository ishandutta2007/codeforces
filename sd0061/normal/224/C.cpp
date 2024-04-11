#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;
#define N 100005
int n,p[N],f[N],stack[N],sum , ans;
string s;
int main()
{
  int i , x;
  cin >> s;
  n = s.size();
  memset(p,-1,sizeof(p));
  stack[0] = n , s[n] = '0';
  for (i = 0 ;i < n ;i ++)
  {
    if (s[i] == '(' || s[i] == '[')
      stack[++ sum] = i;
    if (s[i] == ')')
    {
      if (s[stack[sum]] == '(')
        p[stack[sum]] = i ,sum --;
      else stack[sum] = -1 ,sum = 0;         
    }    
    if (s[i] == ']')
    {
      if (s[stack[sum]] == '[')
        p[stack[sum]] = i ,sum --;
      else stack[sum] = -1 ,sum = 0;         
    }    
  }
  x = -1, sum = 0;
  int ansx = 0 , l , r , ansl , ansr ;
  for (i = 0 ;i < n ; i ++)
    if ((s[i] == '[' || s[i] == '(' ) && p[i] != -1)
    {
      if (x == -1 || i > r + 1)       
      {
        if (sum > ans)
        {
          ans = sum;
          ansx = x;
          ansl = l;
          ansr = r;      
        }    
        l = i;
        r = p[i];
        sum = s[i] == '[' ? 1 : 0;
        x = i;
      }
      else if (i == r + 1)
      {
        if (s[i] == '[')
          sum ++;
        r = p[i];
        x = i;   
      }
      else if (s[i] == '[')
        sum ++;      
    }

  if (sum > ans)
  {
    ans = sum;
    ansx = x;   
    ansl = l;
    ansr = r;     
  }        
  printf("%d\n",ans);    
  if (ans)
    for (i = ansl ; i <= ansr ; i ++)
      cout << s[i];
  return 0;    
}