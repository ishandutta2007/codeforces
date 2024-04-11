#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
#define LL long long
#define N 100005
int n , a[N] , q;
LL s[N];
LL ans[N];
void work()
{
  int i , k;
  scanf("%d",&n);
  for (i = 1 ; i <= n ; ++ i)
    scanf("%d",&a[i]);
  sort(a + 1 , a + n + 1, greater<int>());
  for (i = 1 ; i <= n ; ++ i)
    s[i] = s[i - 1] + a[i];
  scanf("%d",&q);
  while (q --)
  {
    scanf("%d",&k);
    if (ans[k])
    {
      printf("%I64d " , ans[k]);
      continue;
    }
    LL j , x;
    for (i = 0 , x = 1 , j = 1 ; x <= n ; ++ i , x += j , j *= k)
      ans[k] += (s[min((LL)n , x + j - 1)] - s[x - 1]) * i;
    printf("%I64d " , ans[k]);
  }
}

int main()
{
  work();
  return 0;
}