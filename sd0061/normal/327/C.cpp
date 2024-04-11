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
#define LL long long
LL Q = 1000000007;
int n , m;

LL power(LL x)
{
  LL a = 2 , ans = 1;
  while (x)
  {
    if (x & 1) ans *= a , ans %= Q;
    a *= a , a %= Q , x >>= 1;
  }
  return ans;
}

LL cal(int x)
{
  if (x == 1) return 1;
  LL ans;
  if (x % 2 == 0)
    ans = (1 + power((LL)(x >> 1)*n)) % Q * cal(x >> 1) % Q;
  else ans = cal(x - 1) + power((LL)(x-1)* n) % Q;
  return ans;
}

char s[N];

void work()
{
  int i , j , k;
  LL ans = 0;
  scanf("%s" , s + 1);
  scanf("%d",&m) , n = strlen(s + 1);
  LL p = cal(m);
  for (i = n ; i > 0 ; -- i)
    if (s[i] == '5' || s[i] == '0')
    {
      ans += p * power(i - 1) % Q;
      ans %= Q;
    }
  cout << ans;

}

int main()
{
   work();
   return 0;
}