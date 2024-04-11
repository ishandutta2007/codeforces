#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
#define LL long long
int n;
int a[305] , b[305];

int ans;
int xx[1000005];

void work()
{
  int i , j , x;
  scanf("%d",&n);
  for (i = 1 ; i <= n ; ++ i)
    scanf("%d",&a[i]);
  for (i = 1 ; i <= n ; ++ i)
    scanf("%d",&b[i]);
  for (i = 1 ; i <= n ; ++ i)
  {
    for (j = i ; j <= n ; ++ j)
      if (b[j] == a[i])
        break;
    x = j;
    for (j = x ; j > i ; -- j)
      b[j] = b[j - 1] , xx[ans ++] = j - 1;
  }
  printf("%d\n", ans);
  for (i = 0 ; i < ans ; ++ i)
    printf("%d %d\n" , xx[i] , xx[i] + 1);
}

int main()
{
  work();
  return 0;
}