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
#define N 200005
using namespace std;
int n , d[N] , sz , a[N];
long long sum;

void work()
{
  int i , x , y;
  scanf("%d",&n); sz = 1;
  while (n --)
  {
    scanf("%d",&i);
    if (i == 3)
    {
      d[sz - 1] += d[sz];
      sum -= d[sz] , sum -= a[sz];
      -- sz;
    }
    if (i == 2)
    {
      scanf("%d",&x);
      d[++ sz] = 0 , a[sz] = x;
      sum += x;
    }
    if (i == 1)
    {
      scanf("%d%d",&x,&y);
      d[x] += y , sum += x * y;
    }
    printf("%.10lf\n" , double(sum) / double(sz));
  }
}

int main()
{
  work();
  return 0;
}