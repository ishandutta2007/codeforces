#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <cstdio>
#include <algorithm>
#define N 100005
using namespace std;
#define Q 1000000007
int n , f[N] ;
long long d[N] , ans;

void m(long long& x)
{
  while (x < 0) x += Q;
  while (x >= Q) x -= Q;   
}
int getf(int x)
{
  if (f[x] == x)
    return x;
  int r = getf(f[x]);
  d[x] += d[f[x]] , m(d[x]);    
  return f[x] = r; 
}

int main()
{
  cin >> n;
  int i , x , y , z , j , k;
  for (i = 1 ; i <= n; i ++)
    f[i] = i , d[i] = 0;
  for (i = 1 ;i <= n ;i ++)
  {
    cin >> z;
    while (z --)
    {
      cin >> k >> j;
      y = getf(k) ;  
      f[y] = i , d[y] = d[k] + j;
      ans += d[y] , m(ans);       
    } 
  }  
  cout << ans << endl;  
  return 0;
}