#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <set>
#include <map>
using namespace std;
#define N 200005
int n , m , a , b;
void work()
{
  int i , l , r;
  scanf("%d%d",&n,&m);
  for (i = 1 ; i <= n ; ++ i)
    scanf("%d",&l) , a += (l == 1) , b += (l == -1);
  while (m --)
  {
    scanf("%d%d",&l,&r);
    l = r - l + 1;
    if (l & 1)
        puts("0");
    else if (l <= min(a , b) * 2)
        puts("1");
    else puts("0");
  }

}

int main()
{
    work();
  return 0;
}