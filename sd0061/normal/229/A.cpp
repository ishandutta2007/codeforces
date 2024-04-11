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
#define N 105
#define LL long long
int n , m , p[N];
vector<int> a[N];
char s[N * N];
void work()
{

  int i , j , ans = 1 << 30;
  scanf("%d%d",&n,&m);
  for (i = 1 ; i <= n ; ++ i)
  {
    scanf("%s", s + 1);
    for (j = m ; j > 0 ; -- j)
      if (s[j] == '1')
        break;
    if (j <= 0) break;
    a[i].pb(j - m);
    for (j = 1 ; j <= m ; ++ j)
      if (s[j] == '1')
        a[i].pb(j);
    for (j = 1 ; j <= m ; ++ j)
      if (s[j] == '1')
        break;
    a[i].pb(j + m);
  }
  if (i <= n) {puts("-1");return;}
  for (i = 1 ; i <= m ; ++ i)
  {
    int sum = 0;
    for (j = 1 ; j <= n ; ++ j)
    {
      while (i > a[j][p[j] + 1])
        ++ p[j];
      sum += min(i - a[j][p[j]] , a[j][p[j] + 1] - i);
    }
    ans = min(ans , sum);
  }
  cout << ans << endl;
}

int main()
{
  work();
  return 0;
}