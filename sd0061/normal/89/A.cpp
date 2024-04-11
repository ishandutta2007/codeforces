#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
using namespace std;
#define LL long long
#define N 100005
int n , m , k , a[N];
void work()
{
  int i , x ;
  LL ans;
  cin >> n >> m >> k;
  for (i = 1 ; i <= n ; ++ i)
    scanf("%d",&a[i]);
  if (n & 1)
  {
    m /= (n + 1) >> 1;
    ans = 1LL << 30;
    for (i = 1; i <= n ; i += 2)
      ans = min((LL)a[i] , ans);
    ans = min(ans , (LL) m * k);
  }
  else ans = 0;
  cout << ans;
}

int main()
{
 // freopen("input.txt", "r" , stdin);
  //freopen("output.txt", "w" , stdout);
 // int _; scanf("%d",&_) ; while (_ --)
    work();
  return 0;
}