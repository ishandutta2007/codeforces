#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;
#define N 100005
int n , a[N] , d;
long long ans;

int find(int r , int x)
{
  int l = 1 , m;
  while (l <= r)
  {
    m = (l + r) >> 1;    
    if (a[m] >= x && a[m - 1] < x)    
      return m;
    if (a[m] < x)
      l = m + 1;
    if (a[m - 1] >= x)
      r = m - 1;    
  } 
}
int main()
{
  int i , j, x ,y;
  cin >> n >> d;
  a[0] = -1 << 30;
  for (i = 1 ; i <= n ;i ++)
    cin >> a[i];
  for (i = 1 ; i <= n ;i ++)
  {
    j = find(i , a[i] - d);
    ans += ((long long)(i - j) * (i - j - 1)) >> 1;  
  }
  cout << ans << endl;       
  return 0;    
}