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
#define fi first
#define se second
using namespace std;
#define N 100002
int n , a[N] , m , p[N] , sum;
long long ans;
void work()
{
  int i , j , x , d = 0;
  scanf("%d%d",&n,&m);
  for (i = 0 ;i < n ;i ++)
  {
    scanf("%d",&a[i]);
    d = __gcd(d , a[i] - 1);
  }
  for (i = 1 ; i * i <= d ; ++ i)
    if (d % i == 0)
    {
      p[sum ++] = i;
      if (i * i != d)
        p[sum ++] = d / i;
    }
  for (i = 0 ; i < sum ; ++ i)
  {
    x = p[i];
    if (x & 1)
      for (j = 0 ; (long long)x << j < m ; ++ j)
        ans += m - (x << j);
  }
  cout << ans << endl;
}

int main()
{
  work();
  return 0;
}