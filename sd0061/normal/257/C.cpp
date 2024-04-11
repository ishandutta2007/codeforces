#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <queue>
#include <stack>
#include <utility>
#include <map>
#define pb push_back
#define mp make_pair
#define N 100005
using namespace std;
int n;
double a[N] , pi = 3.1415926535897932384626433832795;

bool work()
{
  int i , x , y;
  cin >> n;
  for (i = 1 ; i <= n ;i ++)
  {
    scanf("%d%d",&x,&y);
    a[i] = atan2(y , x);
  //  if (y < 0) a[i] += pi;
  }
  sort(a + 1 , a + n + 1);
  double ans = a[n] - a[1];
  for (i = 1 ; i < n ;i ++)
    ans = min(ans ,2 * pi - a[i + 1] + a[i]);
  ans = ans * 180.0 / pi;
  printf("%lf",ans);
}

int main()
{
  work();
  return 0;
}