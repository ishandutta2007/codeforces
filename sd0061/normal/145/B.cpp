#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
using namespace std;
#define LL long long
#define N 2000005

int a , b , c , d;
int len , f[N];
void work()
{
  int i , j;
  cin >> a >> b >> c >> d;
  if (abs(c - d) > 1) {puts("-1");return;}
  if (c + d >= a + b) {puts("-1");return;}
  if (c == d)
  {
    if (a < c) {puts("-1");return;}
    if (a == c)
    {
      if (b <= c) {puts("-1");return;}
      for (i = 0 ; i < c ; ++ i)
        f[len ++] = 7 , f[len ++] = 4 , -- a , -- b ; f[len ++] = 7 , -- b;
    }
    else
    {
      if (b < c) {puts("-1");return;}
      for (i = 0 ; i < c ; ++ i)
        f[len ++] = 4 , f[len ++] = 7 , -- a , -- b ; f[len ++] = 4 , -- a;
    }
  }
  else if (c > d)
  {
    if (a < c) {puts("-1");return;}
    if (b < c) {puts("-1");return;}
    for (i = 0 ;i < c ; ++ i)
      f[len ++] = 4 , f[len ++] = 7 , -- a , -- b;
  }
  else
  {
    if (a < d) {puts("-1");return;}
    if (b < d) {puts("-1");return;}
    for (i = 0 ;i < d ; ++ i)
      f[len ++] = 7 , f[len ++] = 4 , -- a , -- b;
  }
  int l , r;
  for (l = 0 ; l < len ; ++ l) if (f[l] == 4) break;
  for (r = len - 1 ; r >= 0 ; -- r) if (f[r] == 7) break;

  for (i = 0 ; i < len ; ++ i)
  {
    printf("%d" , f[i]);
    if (i == l)
      while (a --)
        printf("4");
    if (i == r)
      while (b --)
        printf("7");
  }
}

int main()
{
  work();
  return 0;
}