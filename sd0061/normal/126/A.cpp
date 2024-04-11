#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
#define N 100005
#define LL long long

LL x1 , x2, t1 , t2 , t;
double abs(double x) {return x < 0 ? -x : x;}
void work()
{
  LL i , j , y1 , y2 , sum;
  double d ;
  cin >> t1 >> t2 >> x1 >> x2 >> t;
  y1 = 0 , y2 = x2 , sum = x2 , d = t2 - t;
  if (t1 == t2)
  {
    cout << x1 << ' ' << x2;
    return;
  }
  if (t2 == t)
  {
    cout << y1 << ' ' << y2;
    return;
  }
  for (i = 1 ; i <= x1 ; ++ i)
  {
     LL x = i * (t1 - t);
     j = x / (t - t2);
     if (x % (t - t2)) ++ j;
     if (j < 0 || j > x2)
       continue;
     if ((double)(i * t1 + j * t2) / (i + j) < d + t)
       y1 = i , y2 = j , sum = i + j , d = (double)(i * t1 + j * t2) / (i + j) - t;
     if (abs((double)(i * t1 + j * t2) / (i + j) - d - t) < 1e-8  && i + j > sum)
       y1 = i , y2 = j , sum = i + j;
  }
  cout << y1 << ' ' << y2;
}

int main()
{
  work();
  return 0;
}