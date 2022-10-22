#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;
#define N 500005
char s[N] , t[N];
int len , sz , cnt , sum;
char stack[N];

void work()
{
  gets(s);s[strlen(s)] = '"';
  for (int i = 0 ; s[i] ; ++ i)
  {
    if (s[i] == '"')
    {
      if (sum)
      {
        sz = 0;
        while (stack[cnt] != '"')
          t[sz ++] = stack[cnt] , stack[cnt --] = 0;
        stack[cnt --] = 0 , t[sz] = 0;
        reverse(t , t + sz);
        printf("<%s>\n" , t);
        -- sum;
      }
      else
      {
        for (int j = 1 ; j <= cnt ; ++ j)
          if (stack[j] != ' ')
          {
            int k = j;
            while (k <= cnt && stack[k] != ' ')
              ++ k;
            -- k;
            putchar('<');
            for ( ; j <= k ; ++ j)
              putchar(stack[j]);
            -- j;
            putchar('>');
            putchar('\n');
          }
        cnt = 0;
        stack[++ cnt] = '"';
        ++ sum;
      }
    }
    else
    {
      stack[++ cnt] = s[i];
    }
  }
}

int main()
{
  //freopen("~input.txt" , "r", stdin);
  work();
  return 0;
}