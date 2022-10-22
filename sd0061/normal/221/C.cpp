#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <cstdio>
#include <algorithm>
#define N 100005
using namespace std;
int n , a[N] , b[N];
int main()
{
  int i , x;
  cin >> n;
  for (i = 0 ;i < n ;i ++)
    cin >> a[i] , b[i] = a[i];
  sort(a, a + n);
  x = 0;
  for (i = 0 ;i < n ;i ++)
    if (a[i] != b[i])
      x ++;
  if (x == 0 || x == 2)
    printf("YES");
  else printf("NO");      
  return 0;
}