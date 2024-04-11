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

#define N 40005
int n , ans , h[N] , a[N];


void work()
{
  int i , j;
  scanf("%d",&n);
  for (i = 1 ; i <= n ;i ++)
    cin >> h[i] >> a[i];
  for (i = 1 ; i <= n ;i ++)
    for (j = 1 ; j <= n ;j ++)
      if (i != j)
      {
        if (h[i] == a[j])
          ++ ans;
      }
  printf("%d",ans);
}

int main()
{
  work();
  return 0;
}