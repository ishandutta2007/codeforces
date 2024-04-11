#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <cctype>
#include <queue>
#include <cstdio>
#include <utility>
#include <map>
#include <algorithm>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define LL long long
#define N 1005
using namespace std;
LL a , b , n;
pair<LL , LL> an;
long double p , ans;
void work()
{
  LL i , x , y , z;
  cin >> a >> b >> n;
  p = double(a) / double(b);
  ans = 1e10;
  for (i = 1 ; i <= n; i ++)
  {
    x = a * i / b;
    y = x + 1;
    z = __gcd(x , i);
    if ( abs(double(x) / double(i) - p) < ans - 1e-17)
      ans = abs(double(x) / double(i) - p) , an = mp(i / z  , x / z);
    else if (abs(abs(double(x) / double(i) - p) - ans) < 1e-17)
      an = min(an , mp(i / z , x / z));

    z = __gcd(y , i);
    if ( abs(double(y) / double(i) - p) < ans - 1e-17)
      ans = abs(double(y) / double(i) - p) , an = mp(i / z  , y / z);
    else if (abs(abs(double(y) / double(i) - p) - ans) < 1e-17)
      an = min(an , mp(i / z  , y / z));
  }
  cout << an.se << '/' << an.fi;
}

int main()
{
  //int _;cin>>_;while(_--)
   work();
  return 0;
}