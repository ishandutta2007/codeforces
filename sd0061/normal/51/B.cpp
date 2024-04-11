#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
#define N 100005
#define LL long long

char s[N] , str[N];
int n , num[N] , ans[N];
void work()
{
  while (gets(str))
    strcat(s , str);
  n = strlen(s);
  int last = 0 , len = 0 , i;
  for (i = 0 ; i < n ; ++ i)
  {
    ++ i;
    bool f = 0;
    if (s[i] == '/') ++ i , f = 1;
    ++ i;
    char c = s[i];
    if (!f)
    {
      if (c == 'd') num[last] ++;
      if (c == 'a') num[++ last] = 0;
    }
    else
      if (c == 'a') ans[len ++ ] = num[last --];
    for(;s[i] != '>' ; i ++);
  }
  sort(ans , ans + len);
  for(i = 0;i < len; i ++)
	printf("%d ",ans[i]);
}

int main()
{
  work();
  return 0;
}