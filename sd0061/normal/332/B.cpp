#include <iostream>
#include <cstring>
#include <cctype>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <cstdio>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#define N 200005
typedef long long LL;
#define fi first
#define se second
using namespace std;
int n , k , p[N];
LL a[N] , s[N] , t[N] , f[N] , l , r ;
pair<LL , pair<int , int> > ans;
void work()
{
  int i , j ;
  cin >> n >> k;
  for (i = 1 ; i <= n ; ++ i) cin >> a[i];
  for (i = 1 ; i <= n ; ++ i) s[i] = s[i - 1] + a[i];
  for (i = 1 ; i <= n ; ++ i) t[n - i + 1] = t[n - i + 2] + a[n - i + 1];
  for (i = 0 ; i < k ; ++ i) f[i] = -1LL << 60;
  for (i = k ; i <= n ; ++ i)
  {
    if (f[i - 1] < s[i] - s[i - k])
      f[i] = s[i] - s[i - k] , p[i] = i - k + 1;
    else f[i] = f[i - 1] , p[i] = p[i - 1];
  }

  LL x = 0; int y;
  for (j = n - k + 1; j > 0 ; -- j)
  {
    if (x <= t[j] - t[j + k])
      x = t[j] - t[j + k] , y = j;
    ans = max(ans , make_pair(x + f[j - 1] , make_pair(-p[j - 1] , -y)));
  }
  cout << -ans.se.fi << ' ' << -ans.se.se;
}

int main()
{
    work();
  return 0;
}