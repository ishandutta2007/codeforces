#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
using namespace std;
#define LL long long
#define N 1000005
int n , a[N];
int f[1 << 22];

void work()
{
  int i , j , x = (1 << 22) - 1;
  scanf("%d",&n);
  for (i = 1 ;i <= n ; ++ i)
    scanf("%d",&a[i]) , f[a[i]] = a[i];
  for (i = 0 ; i < 1 << 22 ; ++ i)
    for (j = 0 ; j < 22 ; ++ j) if (i & (1 << j))
      if (f[i - (1 << j)])
        f[i] = f[i - (1 << j)];
  for (i = 1 ; i <= n ; ++ i)
    if (f[a[i] ^ x])
      printf("%d " ,f[a[i] ^ x]);
    else printf("-1 ");

}

int main()
{
  //freopen("output.txt", "w" , stdout);
 // int _; scanf("%d",&_) ; while (_ --)
    work();
  return 0;
}