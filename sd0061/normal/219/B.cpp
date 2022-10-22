#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
using namespace std;
unsigned long long l , r;
unsigned long long p[20];
int main()
{
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
  int i ;
  cin >> r >> l ; l = r - l;
  p[0] = 1;
  for (i = 1 ;i <= 19 ;i ++)
    p[i] = p[i - 1] * 10;
  for (i = 0 ; ;i ++)
  {
    while (l + p[i] <= r && ((l / p[i]) % 10) < 9)
      l += p[i];
    if (((l / p[i]) % 10) != 9)
      break;    
  }
  cout << l;
  return 0;
}