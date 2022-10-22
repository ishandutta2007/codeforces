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
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
#define N 1005
#define M 100005
#define LL long long
void RD(int& x)
{
  x = 0; char c;
  for (c = getchar() ;!isdigit(c) ; c = getchar()); x = c - '0';
  for (c = getchar() ; isdigit(c) ; c = getchar()) x = x * 10 + c - '0';
}

int n , m;
bool f[N];
LL p[N] , v[N] , e[N];
const LL Q = 1e9 + 7;

LL inv(LL x)
{
  LL ans = 1 , b = Q - 2;
  while (b)
  {
    if (b & 1)
      ans *= x , ans %= Q;
    x *= x , x %= Q , b >>= 1;
  }
  return ans;
}

void work()
{
  int i , j , x;
  p[0] = e[0] = 1;
  scanf("%d%d",&n,&m);
  for (i = 1 ; i <= m ; ++ i)
    scanf("%d",&x) , f[x] = 1; f[0] = f[n + 1] = 1;
  for (i = 1 ; i <= n ; ++ i)
    p[i] = p[i - 1] * i , p[i] %= Q , v[i] = inv(p[i]) , e[i] = e[i - 1] << 1 , e[i] %= Q;
  LL ans = p[n - m];
  for (i = 1 ; i <= n ; i ++)
    if (!f[i])
    {
      j = i;
      while (!f[j])
        ++ j;-- j;
      x = j - i + 1;
      if (i != 1 && j != n)
        ans *= e[x - 1] , ans %= Q;
      ans *= v[x] , ans %= Q;
      i = j;
    }
  cout << ans ;
}

int main()
{
//  freopen("~input.txt","r",stdin);
  //freopen("~output.txt","w",stdout);
  //init();
  //int _;cin>>_;while(_--)
  //while (scanf("%s" , s) , s[0] != '#')
    work();
  return 0;
}