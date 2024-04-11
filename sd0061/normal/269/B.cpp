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
#define N 5005
#define LL long long
int n , a[N] , f[N] , ans , m;

void work()
{
  int i , j , x;double p;
  scanf("%d%d",&n,&m);
  for (i = 1 ; i <= n ;i ++)
    scanf("%d%lf",&a[i] , &p);
  for (i = 1 ; i <= n ;i ++)
  {
    for (j = 1 ; j < i ;j ++)
      if (a[i] >= a[j])
        f[i] = max(f[i] , f[j]);
    ans = max(++ f[i] , ans);
  }
  printf("%d", n - ans);
}

int main()
{
  work();
  return 0;
}