#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <map>
#include <string>
#include <utility>
#define mp make_pair
#define pb push_back
#define N 100005
#define LL long long
using namespace std;
int n, sum;
char s[N] , t[N];
const LL Q = 1e9 + 7;
LL ans , pe;
void work()
{
  int i , x;
  scanf("%d%s%s",&n, s+1 , t+1);
  ans = 1;
  for (i = 1 ; i <= n ; ++ i)
  {
    if (s[i] == '?') ans *= 10 , ans %= Q;
    if (t[i] == '?') ans *= 10 , ans %= Q;
  }
  pe = 1;
  for (i = 1 ; i <= n ; ++ i)
  {
    if (s[i] != '?')
    {
      if (t[i] != '?')
      {
        if (s[i] >= t[i])
          x = 1;
        else x = 0;
      }
      else
        x = s[i] - '0' + 1;
    }
    else
    {
      if (t[i] != '?')
        x = 10 - t[i] + '0';
      else
        x = 55;
    }
    pe *= x , pe %= Q;
  }
  ans += (Q - pe) , ans %= Q;
  pe = 1;
  for (i = 1 ; i <= n ; ++ i)
  {
    if (s[i] != '?')
    {
      if (t[i] != '?')
      {
        if (s[i] <= t[i])
          x = 1;
        else x = 0;
      }
      else
        x = 10 - s[i] + '0';
    }
    else
    {
      if (t[i] != '?')
        x = t[i] - '0' + 1;
      else
        x = 55;
    }
    pe *= x , pe %= Q;
  }
  ans += (Q - pe) , ans %= Q;
  pe = 1;
  for (i = 1 ; i <= n ; ++ i)
    if (s[i] == '?' && t[i] == '?')
      pe *= 10 , pe %= Q;
    else if (s[i] != '?' && t[i] != '?' && s[i] != t[i])
      pe = 0;
  ans += pe , ans %= Q;
  cout << ans << endl;
}

int main()
{  
  work();
  return 0;
}