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
int n , a[N] , m;
int fl[N] , fr[N];

void work()
{
  int i , l , r;
  scanf("%d%d",&n,&m);
  for (i = 1 ; i <= n ; ++ i)
    scanf("%d",&a[i]);
  fl[1] = 1;
  for (i = 2 ; i <= n ; ++ i)
    if (a[i] <= a[i - 1])
      fl[i] = fl[i - 1] + 1;
    else fl[i] = 1;
  fr[n] = 1;
  for (i = n - 1 ; i > 0 ; -- i)
    if (a[i] <= a[i + 1])
      fr[i] = fr[i + 1] + 1;
    else fr[i] = 1;
  for (i = 1 ; i <= m ; ++ i)
  {
    scanf("%d%d",&l,&r);
    if (fl[r] + fr[l] >= r - l + 1)
      puts("Yes");
    else puts("No");
  }
}


int main()
{
    work();
  return 0;
}