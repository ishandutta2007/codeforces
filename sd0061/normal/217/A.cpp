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
#include <set>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
#define N 100005
int n;
pair<int , int> a[N];
int f[N] , ans;
int getf(int x) {return x == f[x] ? x : f[x] = getf(f[x]);}

void work()
{
  int i , j;
  scanf("%d",&n);
  for (i = 1 ; i <= n ; ++ i)
    scanf("%d%d",&a[i].fi , &a[i].se) , f[i] = i;
  for (i = 1 ; i <= n ; ++ i)
    for (j = i + 1 ; j <= n ; ++ j)
      if (a[i].fi == a[j].fi || a[i].se == a[j].se)
        if (getf(i) != getf(j))
          f[getf(i)] = getf(j) , -- ans;
  printf("%d" , n + ans - 1);
}

int main()
{
  work();
  return 0;
}