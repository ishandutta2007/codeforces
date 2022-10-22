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
#include <map>
#include <set>
#include <list>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
//#pragma comment(linker, "/STACK:16777216")
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define N 100005

int n , A , B , a[N];
vector<int> fac[2];
void work()
{
  int ans = 0 , cur = 0 , nxt = 1;
  int i , x;
  scanf("%d",&n);

  for (i = 1 ; i <= n ; ++ i)
    scanf("%d",&a[i]);
  sort(a + 1 , a + n + 1);
  n = unique(a + 1 , a + n + 1) - a - 1;
  for (i = 1 ; i <= n ; ++ i)
    fac[cur].push_back(a[i]);
  scanf("%d%d",&A,&B);
  while (A != B)
  {
    x = A - 1;
    fac[nxt].clear();
    for (i = 0 ; i < fac[cur].size() ; ++ i)
    {
      int y = A / fac[cur][i] * fac[cur][i];
      if (y >= B)
        fac[nxt].push_back(fac[cur][i]) , x = min(x , y);
    }
    ++ ans , A = x , swap(cur , nxt);
  }
  cout << ans << endl;
}

int main()
{
  work();
  return 0;
}