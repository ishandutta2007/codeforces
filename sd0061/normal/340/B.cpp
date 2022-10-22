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
#include <map>
#include <set>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define N 305
int n ;
int xx[N] , yy[N];

void work()
{
  int i , j , k , ans = 0 , x;
  cin >> n;
  for (i = 1 ; i <= n; ++ i)
    cin >> xx[i] >> yy[i];
  for (i = 1 ; i <= n ; ++ i)
    for (j = 1 ; j <= n ; ++ j) if (i != j)
    {
      int mn = 1 << 30 , mx = -1 << 30;
      for (k = 1 ; k <= n ; ++ k) if (k != i && k != j)
      {
        x = (xx[i] - xx[j]) * (yy[i] - yy[k]) - (xx[i] - xx[k]) * (yy[i] - yy[j]);
        mn = min(x , mn) , mx = max(x , mx);
      }
      ans = max(ans , mx - mn);
    }
  printf("%f" , ans / 2.0);
}

int main()
{
  work();
  return 0;
}