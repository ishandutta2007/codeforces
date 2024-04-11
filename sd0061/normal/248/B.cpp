#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;
#define N 100005
int n , a[6] = {170,20,200,110,50,80}
      , b[6] = {4,3,4,4,3,3};
int main()
{
  int i , j;
  cin >> n;
  if (n <= 2)
  {
    cout << -1;
    return 0;    
  }  
  if (n == 3)
  {
    cout << 210;
    return 0;    
  }  
  for (i = 0 ;i < 6 ;i ++)
    if (n % 6 == i)
    {
      cout << 1;
      for (j = 1 ; j <= n - b[i] ; j ++)
        cout << 0;
      cout << a[i];           
    }
  return 0;  
}