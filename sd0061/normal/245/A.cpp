#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;
#define N 100005
int n , sa , sb , x , a , b , i, j;
int main()
{
  cin >> n;
  while (n --)
  {
    cin >> x >> i >> j;
    if (x == 1)
      sa += 10 , a += i;
    else sb += 10 , b += i;      
  }
  if (a * 2 >= sa)
    printf("LIVE\n");
  else printf("DEAD\n");
  if (b * 2 >= sb)
    printf("LIVE\n");
  else printf("DEAD\n");
    
  return 0;    
}