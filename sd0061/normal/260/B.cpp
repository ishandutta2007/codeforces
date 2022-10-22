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
#include <map>
#define pb push_back
#define mp make_pair
#define N 100002
using namespace std;
typedef long long LL;
//const LL Q = 1000000007LL;
int l , ay , ans , am , ad;
char s[N] , t[25] ;
int f[N];
int p[13] = {0 , 31 , 28, 31 , 30, 31 ,30 ,31 ,31 ,30, 31,30, 31};

int check()
{
  int sum = 0 , j;
  for (int i = 0 ;i < l ;i ++)
  {
    for (j = 0 ;j < 10 ; ++ j)
      if (s[i + j] != t[j])
        break;
    if (j == 10) sum ++;
  }
  return sum;
}

void work()
{
  l = strlen(s);
  int i , x;
  for (int y = 2013 ; y <= 2015 ; y ++)
    for (int m = 1 ; m <= 12 ; m ++)
      for (int d = 1 ; d <= p[m] ;d ++)
      {
        if (m > 9)
        {
          if (d > 9) sprintf(t , "%d-%d-%d",d,m,y);
          else sprintf(t , "0%d-%d-%d",d,m,y);
        }
        else
        {
          if (d > 9) sprintf(t , "%d-0%d-%d",d,m,y);
          else sprintf(t , "0%d-0%d-%d",d,m,y);
        }
        x = check();
        if (x > ans) ans = x , ay = y , am = m , ad = d;
      }
         if (am > 9)
        {
          if (ad > 9) printf( "%d-%d-%d",ad,am,ay);
          else printf( "0%d-%d-%d",ad,am,ay);
        }
        else
        {
          if (ad > 9) printf( "%d-0%d-%d",ad,am,ay);
          else printf( "0%d-0%d-%d",ad,am,ay);
        }
}

int main()
{
  while(~scanf("%s",s)) work();
  return 0;
}