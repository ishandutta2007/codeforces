#include <iostream>
#include <cstring>
#include <cctype>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <cstdio>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#define N 2005
typedef long long LL;
#define fi first
#define se second
using namespace std;
int n ;
LL f[N];

void work()
{
  int i , j , x , y , k;
  cin >> n;
  for (i = 0 ; i <= n ; ++ i)
    f[i] = 1LL << 60;
  f[0] = 0;
  for (i = 1 ; i <= n ; ++ i)
  {
    cin >> x >> y , ++ x;
    for (j = n - 1 ; j >= 0 ; -- j)
    {
      k = min(n , j + x);
      f[k] = min(f[k] , f[j] + y);
    }
  }
  cout << f[n] << endl;
}

int main()
{
 //int _; scanf("%d",&_); while (_--)
    work();
  return 0;
}