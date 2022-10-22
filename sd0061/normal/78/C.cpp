#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <map>
#include <string>
#include <utility>
#define mp make_pair
#define pb push_back
#define N 2505
using namespace std;
int n , m , k;
void work()
{
  int i , x , y;
  cin >> n >> m >> k;
  for (i = 1 ; i * i <= m ; ++ i)
    if (m % i == 0)
    {
      if (i >= k && m != i)
        break;
      if (m / i >= k && i > 1)
        break;
    }
  if (i * i > m)
    puts("Marsel");
  else
  {
    if (n & 1)
      puts("Timur");
    else puts("Marsel");
  }
}

int main()
{
  work();
  return 0;
}