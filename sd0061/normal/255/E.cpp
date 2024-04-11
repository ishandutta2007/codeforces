#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;
int n , s;
long long x;
int SG(long long x)
{
  if (x >= 2562991876LL) return 2;
  if (x >= 50626) return 1;
  if (x >= 6724) return 3;
  if (x >= 82) return 0;
  if (x >= 16) return 2;
  if (x >= 4) return 1;
  return 0;
}
int main()
{
  cin >> n;
  while (n --)
    cin >> x , s ^= SG(x);
  puts(s ? "Furlo":"Rublo");  
  return 0;
}