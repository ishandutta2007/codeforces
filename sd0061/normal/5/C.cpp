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
#include <map>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
#define N 1000005
#define LL long long
char str[N];
int top , match[N] , s[N];

void work()
{
  int i ; char c;
  scanf("%s" , str);
  memset(match , -1 , sizeof(match));
  for (i = 0 ; str[i] ; ++ i)
  {
    c = str[i];
    if (c == '(')
      s[++ top] = i;
    else
    {
      if (!top) continue;
      if (str[s[top]] == '(')
        match[i] = s[top] , -- top;
      else top = 0;
    }
  }
  int ans = 0 , tot = 1;
  for (i = 0 ; str[i] ; ++ i) if (~match[i])
    if (~match[match[i] - 1])
      match[i] = match[match[i] - 1];

  for (i = 0 ; str[i] ; ++ i) if (~match[i])
  {
    if (i - match[i] + 1 > ans)
      ans = i - match[i] + 1 , tot = 0;
    if (i - match[i] + 1 == ans) ++ tot;
  }
  printf("%d %d\n" , ans , tot);
}

int main()
{
  work();
  return 0;
}