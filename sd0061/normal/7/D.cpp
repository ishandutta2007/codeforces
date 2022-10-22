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
#define N 5000005
#define LL unsigned long long
#define MAGIC 67
int n , h[256] , f[N];
char s[N];
LL l[N] , r[N] , p[N] , ans;


void work()
{
  int i , j = 0;
  for (i = 0 ;i < 26 ; ++ i)
    h['a' + i] = ++ j;
  for (i = 0 ;i < 26 ; ++ i)
    h['A' + i] = ++ j;
  for (i = 0 ;i < 10 ; ++ i)
    h['0' + i] = ++ j;
  scanf("%s" , s + 1);
  n = strlen(s + 1);

  p[0] = 1;
  for (i = 1 ; i <= n ; ++ i)
    p[i] = p[i - 1] * MAGIC;
  for (i = 1 ; i <= n ; ++ i)
    l[i] = l[i - 1] * MAGIC + h[s[i]];
  for (i = n ; i > 0 ; -- i)
    r[i] = r[i + 1] * MAGIC + h[s[i]];

  for (i = 1 ; i <= n ; ++ i)
  {
    j = i / 2;
    LL x , y;
    x = l[i] , y = r[1] - r[i + 1] * p[i];
    if (x == y)
    {
      x = l[j] , y = l[i] - l[i - j] * p[j];
      if (x == y)
        f[i] = f[j] + 1;
      else f[i] = 1;
    }
    ans += f[i];
  }
  cout << ans << endl;

}


int main()
{
//  freopen("~input.txt","r",stdin);
 // freopen("~output.txt","w",stdout);
//  int _; cin >> _; while (_ --)
    work();
  return 0;
}