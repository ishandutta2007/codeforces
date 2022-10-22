#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <cstdio>
#include <algorithm>
#define N 10
using namespace std;
int n, i;
bool f[N];
bool p(int x)
{
  while (x)
  {
    if (f[x % 10]) 
      return 1;
    x /= 10;
  } 
  return 0;
}

int main()
{
  int i , x , ans = 0;
  cin >> n;
  x = n;
  while (x)
  {
    f[x % 10] = 1;
    x /= 10;
  }
  for (i = 1 ; i * i <= n ;i ++)
    if (n % i == 0)
    {
      if (p(i)) ans ++;
      if (i * i != n &&p(n / i)) ans ++;
    }
  cout << ans;  
  return 0;
}