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
#define N 100005
int n , a[N], f[N] , ans = 1;
vector<int> p;
char s[N];
void work()
{
  int i , j , x , y;
  for (i = 2 ; i * i <= 316 ;i ++) if (!f[i])
    for (j = i + i ; j <= 316 ;j += i)
      f[j] = 1;
  for (i = 316; i > 1 ; -- i) if (!f[i]) p.pb(i);

  memset(f , 0 , sizeof(f));
  scanf("%d",&n);
  for (i = 1 ; i <= n ;i ++)
  {
    scanf("%d",&x) , y = 0;
    vector<int> q;
    for (j = p.size() - 1 ; j >= 0 ; -- j)
      if (x % p[j] == 0)
      {
        y = max(y , f[p[j]]);
        q.pb(p[j]);
        while (x % p[j] == 0) x /= p[j];
      }
    if (x > 1) y = max(y , f[x]) , q.pb(x);
    ans = max(ans , y + 1);
   for (j = q.size() - 1 ; j >= 0 ; -- j)
     f[q[j]] = y + 1;
  }
  cout << ans << endl;
}

int main()
{
  work();
  return 0;
}