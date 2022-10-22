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
#include <set>
#include <map>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
#define N 100005
#define LL long long
int n , xx[N] , yy[N] , a[N];
unsigned LL ans , sum , sum2;

void work()
{
  int i ;
  scanf("%d",&n);
  for (i = 0 ;i < n ; ++ i)
    scanf("%d%d",&xx[i] , &yy[i]);
  sum = 0 , sum2 = 0;
  for (i = 0 ;i < n ; ++ i)
    sum += xx[i] , sum2 += xx[i] * xx[i];
  for (i = 0 ;i < n ; ++ i)
    ans += (LL) n * xx[i] * xx[i] ,
    ans -= 2 * sum * xx[i] ,
    ans += sum2 ;
  sum = 0 , sum2 = 0;
  for (i = 0 ;i < n ; ++ i)
    sum += yy[i] , sum2 += yy[i] * yy[i];
  for (i = 0 ;i < n ; ++ i)
    ans += (LL) n * yy[i] * yy[i] ,
    ans -= 2 * sum * yy[i],
    ans += sum2;
  cout << (ans >> 1) << endl;
}


int main()
{
    work();
  return 0;
}