#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <string>
#include <map>
using namespace std;
#define N 100003
#define ULL unsigned long long
int n , a[N] , s[N];

void work()
{
  int i , j;
  cin >> n;
  for (i = 1 ; i <= n ; ++ i)
     cin >> a[i] , s[i] = s[i - 1] + a[i];
  int ans = -1 << 30;
  for (i = 1 ; i <= n ; ++ i)
    for (j = i ; j <= n ; ++ j)
      ans = max(ans , s[n] + (j - i + 1) - 2 * s[j] + 2 * s[i - 1]);
  cout << ans ;
}

int main()
{
  // for (int i = 0 ; i < 1 << 12 ; ++ i) cnt[i] = cnt[i >> 1] + (i & 1);
  // int _; cin >> _;while (_ --)
   //while (~scanf("%d%d",&n,&m))
   work();
   return 0;
}