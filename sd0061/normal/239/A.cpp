#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;
#define N 100005
long long y , k , n ;
bool f;
int main()
{
  cin >> y >> k >> n;
  for (int x = (10000000LL * k - y) % k ; x + y <= n ;x += k)
    if (x >= 1)
    {
      cout << x << ' '; 
      f = 1; 
    }  
  if (!f)
    printf("-1");
  return 0;    
}