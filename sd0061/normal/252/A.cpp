#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;
#define N 100005
int n , a[N];

int main()
{
  int i , j,x = 0;
  cin >> n ;
  for (i = 1 ; i <= n ;i ++)
    cin >> a[i] , a[i] ^= a[i - 1];
  for (i = 0 ;i < n ;i ++)
    for (j = i + 1 ;j <= n ;j ++)
      x = max(x , a[j] ^ a[i]);
  cout << x << endl;       
  return 0;    
}