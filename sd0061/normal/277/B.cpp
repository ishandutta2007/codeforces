#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <queue>
#include <cstdio>
#include <utility>
#include <algorithm>
#define fi first
#define se second
#define N 5005
using namespace std;
int n , m;

void work()
{
  scanf("%d%d",&n,&m);
  if (m == 3 && n > 4) {puts("-1");return;}
  for (int i = 1 ; i <= m ;i ++)
    printf("%d %d\n", i , (1 << 20) + i * i);
  for (int i = 1 ; i <= n - m ;i ++)
    printf("%d %d\n", i , -(1 << 20) - i * i);
}

int main()
{
  work();
  return 0;
}