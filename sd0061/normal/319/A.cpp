#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <set>
#include <climits>
using namespace std;
#define N 100005
#define M 500005
#define LL long long

int n ;
char s[105];
LL Q = 1e9 + 7;

LL power(int x)
{
  LL ans = 1 , a = 2;
  while (x)
  {
    if (x & 1) ans *= a , ans %= Q;
    a *= a , a %= Q , x >>= 1;
  }
  return ans;
}

void work()
{
  int i , j; LL ans = 0;
  scanf("%s",s);
  n = strlen(s);
  for (i = 0 ; i < n ; ++ i)
  {
    if (s[i] == '1')
    {
      ans += power(2 * n - i - 2) , ans %= Q;
    }
  }
  cout << ans << endl;
}

int main()
{
  //freopen("~input.txt","r",stdin);
  //freopen("~output.txt","w",stdout);
 //while (~scanf("%d%d",&n,&m))
    work();
  return 0;
}