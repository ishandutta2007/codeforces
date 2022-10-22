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
#define N 100005
using namespace std;
int n ;
long long a[N] , t , m = 1 << 30;

void work()
{
  int i , x = 1, ans = 0;
  cin >> n >> t;
  for (i = 1 ; i <= n ;i ++) scanf("%I64d",&a[i]), m = min(m , a[i]) , a[i] += a[i - 1] ;
  if (t < m) {cout << 0; return;}
  for (i = 1 ; i <= n ;i ++)
  {
    while (x != n && a[x] <= t + a[i - 1])
      ++ x;
    if (a[x] <= t + a[i - 1])
      ans = max(ans , x - i + 1);
    else  ans = max(ans , x - i);
  }
  cout << ans << endl;
}

int main()
{
  //int _;cin>>_;while (_--)
  work();
  return 0;
}