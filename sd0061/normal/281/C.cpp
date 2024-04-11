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
LL L , H , b; double a;

void work()
{
  //cin >> L >> H >> b;
  if (L > H) swap(L , H);
  if (b > 90) b = 180 - b;
  a = b * acos(-1.0) / 180.0;
  double tan = 2 * atan(double(L) / double(H));
  if (tan <= a)
  {
    double p = L / sin(a);
    printf("%.15lf\n",L * p);
    return;
  }

  double x = cos(a) + 1 , y = sin(a);
  double det = x * x - y * y ,
         p1 = x * L - y * H ,
         p2 = x * H - y * L ;
  double A = p1 / det , B = p2 / det;
  x -= 1.0;
  double s = L * H - A * x * y * A - B * B * x * y;
  printf("%.15lf\n",s);
}


int main()
{
  while(cin >> L >> H >> b)
   work();
  return 0;
}