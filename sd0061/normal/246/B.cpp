#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;
#define N 100005
int n , a[N] , sum;

int main()
{
  int i , j;
  cin >> n;
  for (i = 1 ;i <= n ;i ++)
    cin >> a[i] , sum += a[i];
  if (sum % n == 0)
    cout << n;
  else cout << n - 1;     
  return 0;    
}