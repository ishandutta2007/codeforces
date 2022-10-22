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
#define N 2005
typedef long long LL;
int n;
char s[N]; int t[26];
void work()
{
  int i , j , x , y; bool f = 1;
  scanf("%s", s) , n = strlen(s);
  for (i = 0 ; i < n ;i ++) ++ t[s[i] - 'a'];
  for (i = n ; i > 0 ; -- i , f = !f)
  {
    if (i & 1)
    {
      x = 0;
      for (j = 0 ;j < 26 ; ++ j)
        if (t[j] & 1) ++ x;
      if (x == 1) break;

      for (j = 0 ;j < 26 ; ++ j)
        if (t[j] & 1)
        {
          t[j] --;
          break;
        }
    }
    else
    {
      x = 0;
      for (j = 0 ;j < 26 ; ++ j)
        if (t[j] & 1) ++ x;
      if (x == 0) break;
      for (j = 0 ;j < 26 ; ++ j)
        if ((t[j] & 1))
        {
          t[j] --;
          break;
        }
    }
  }
  puts(f ? "First" : "Second");
}

int main()
{
  //while (scanf("%d%d",&n ,&m) , n || m)
    work();
  return 0;
}