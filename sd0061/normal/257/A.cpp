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
#define N 1025
#define M 20005
using namespace std;
int n , m , k , a[N];


bool work()
{
  int i , x;
  scanf("%d%d%d",&n,&m,&k);
  for (i = 1 ; i <= n ;i ++)
    scanf("%d",&a[i]);
  sort(a + 1 , a + n + 1);
  x = 0;
  while (k < m && x < n)
    k -- , k += a[n - x] , ++ x;
  if (k < m)
    printf("-1");
  else printf("%d",x);
}

int main()
{
 // freopen("~input.txt","r",stdin);
 // freopen("~output.txt","w",stdout);
  work();
  return 0;
}