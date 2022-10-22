#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
using namespace std;
#define LL long long
#define N 400005
int n , m , a[N];
map<int , int> h;
void work()
{
  int i , j; LL ans = 0;
  scanf("%d%d",&n,&m);
  for (i = 1 ; i <= n ; ++ i)
    scanf("%d",&a[i]);
  for (i = 1 , j = 0 ; i <= n ; ++ i)
  {
    ++ h[a[i]];
    while (h[a[i]] >= m)
      ++ j , -- h[a[j]];
    ans += j;
  }
  cout << ans << endl;
}

int main()
{
  //freopen("input.txt", "r" , stdin);
    work();
  return 0;
}