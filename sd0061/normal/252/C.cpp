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
#include <map>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
#define N 100005
#define LL unsigned long long
int n , a[N] , d;
LL ans;
void work()
{
  int i , j;
  scanf("%d%d",&n,&d);
  for (i = 1 ; i <= n ; ++ i)
    scanf("%d",&a[i]);
  for (i = 1 , j = 1; i <= n ; ++ i)
  {
    while (a[i] - a[j] > d)
      ++ j;
    ans += (LL)(i - j) * (i - j - 1) / 2;
  }
  cout << ans << endl;
}


int main()
{
    work();
  return 0;
}