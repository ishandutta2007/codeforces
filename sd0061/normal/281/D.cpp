#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <cctype>
#include <queue>
#include <cstdio>
#include <utility>
#include <map>
#include <algorithm>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define LL long long
#define N 100005
using namespace std;
int n , a[N] , ans;
int s[N] , top;

void work()
{
  int i;
  scanf("%d",&n);
  for (i = 1 ; i <= n ; ++ i)
    scanf("%d",&a[i]);
  top = 0;
  for (i = 1 ; i <= n ; i ++)
  {
    while (top && a[s[top]] < a[i])
      ans = max(ans , a[i] ^ a[s[top]]) , -- top;
    s[++ top] = i;
  }
  top = 0;
  for (i = n ; i > 0 ; i --)
  {
    while (top && a[s[top]] < a[i])
      ans = max(ans , a[i] ^ a[s[top]]) , -- top;
    s[++ top] = i;
  }
  cout << ans << endl;
}

int main()
{
  work();
  return 0;
}