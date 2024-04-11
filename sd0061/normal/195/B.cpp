#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <cstdio>
#include <algorithm>
#define N 100005
using namespace std;
int n , m;

int main()
{
  int i , j, x;
  cin >> n >> m;
  x = (m + 1) / 2;
  for (i = 1 ,j = 1; i <= n ;i ++, j ++)
  {
    printf("%d\n",x);
    if (m & 1)
    {
      if (j & 1)
      {
        x = x - j;
        if (x < 1)
          x = (m + 1) / 2 ,j = 0;
      }
      else       
      {
        x = x + j;     
        if (x > m)
          x = (m + 1) / 2 ,j = 0;    
      }
    }  
    else
    {
      if (j & 1)
      {
        x += j;   
        if (x > m)
          x = (m + 1) / 2 ,j = 0; 
      }  
      else
      {
        x -= j;  
        if (x < 1)
          x = (m + 1) / 2 ,j = 0;
      }
    }
  }
  return 0;  
}