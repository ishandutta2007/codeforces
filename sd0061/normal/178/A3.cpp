#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#define N 100005
using namespace std;
typedef long long LL;

#define sqr(x) ((x)*(x))
int n , a[N];

void work()
{
  int i , j;LL ans = 0;
  scanf("%d",&n);
  for (i = 1 ; i <= n ; ++ i)
    scanf("%d" , &a[i]);
  for (i = 1 ; i < n ; ++ i)
  {
    j = int(log2(n - i));
    a[i + (1 << j)] += a[i] , ans += a[i];
    printf("%I64d\n" , ans);
  }
}

int main()
{
    work();
  return 0;
}