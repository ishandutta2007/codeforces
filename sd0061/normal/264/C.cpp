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
int n , c[N] , v[N] , A , B , m;
typedef long long ll;
ll f[N] , ans;

void work()
{
  int i;
  scanf("%d%d",&n,&m);
  for (i = 1 ; i <= n ;i ++) scanf("%d",&v[i]);
  for (i = 1 ; i <= n ;i ++) scanf("%d",&c[i]);
  while (m --)
  {
    scanf("%d%d",&A,&B);
    //memset(f , 0 , sizeof(f));
    for (i = 1 ; i <= n ;i ++)
      f[i] = -1LL << 60;
    ans = 0;
    int p = 0, q = 0;
    for (i = 1 ; i <= n ;i ++)
    {
      ll x = max(f[c[i]] + (ll)A * v[i] , f[q] + (ll)B * v[i]);
      if (p != c[i])
      {
        x = max(x , f[p] + (ll)B * v[i]);
        if (f[p] < x)
          q = p , p = c[i];
        else if (f[q] < x)
          q = c[i];
      }
      f[c[i]] = max(f[c[i]] , x);
      ans = max(f[c[i]] , ans);
    }
    cout << ans << endl;
  }
}

int main()
{
  work();
  return 0;
}