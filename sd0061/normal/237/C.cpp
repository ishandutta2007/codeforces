#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;
#define N 1000005
int a , b , k , p[N] , ans;
bool f[N];

int main()
{
  int i , j ,x , l, r , m;
  cin >> a >> b >> k;
  
  for (i = 2 ;i <= b ;i ++)
    if (!f[i])  
      for (j = 2 ;i * j <= b ;j ++)
        f[i * j] = 1;
  for (i = 2 ;i <= b ;i ++)
  {
    p[i] = p[i - 1];
    if (!f[i])
      ++ p[i];  
  }
  if (p[b] - p[a - 1] < k)
  {
    cout << -1;
    return 0;       
  }
  l = 1 , r = b - a + 1;
  while (l != r)
  {
    m = (l + r) >> 1;
    for (i = a ; i <= b - m + 1 ; i ++)
      if (p[i + m - 1] - p[i - 1] < k)
        break;
    if (i <= b - m + 1)
      l = m + 1;
    else r = m;        
  }
  cout << l;
  return 0;    
}