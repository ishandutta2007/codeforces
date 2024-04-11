#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;
#define N 105
int n,a[N][N];
int main()
{
  int i , j, x;
  cin >> n;
  for (i = 1 ;i <= n ;i ++)
    for (j = 1 ;j <= n ;j ++)
      cin >> a[i][j];
  for (i = 1 ;i <= n ;i ++)
  {
    x = 0;
    for (j = 1 ;j <= n ;j ++)
      if (i != j)
        x |= a[i][j] , x |= a[j][i];
    cout << x << ' ';      
  }
  return 0;    
}