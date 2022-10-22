#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <cctype>
#include <queue>
#include <cstdio>
#include <utility>
#include <map>
#include <algorithm>
#define fi first
#define se second
#define mp make_pair
#define pb push_back

#define N 1000005
using namespace std;
int n , ans , f[N];
char s[N];

void work()
{
  int i , j , sum = 0;
  scanf("%s", s) , n = strlen(s);
  while (n && s[n - 1] == '0') -- n;
  f[0] = (s[0] == '1');
  for (i = 1 ; i < n ; ++ i) f[i] = f[i - 1] + (s[i] == '1');
  ans = f[n - 1];
  while (n)
  {
    i = n;
    while (i && s[i - 1] == '1') i --;
    if (i == 0)
    {
      if (n == 1) sum ++;
      else sum += 2;
      break;
    }
    if (n - i == 1)
    {
      ++ sum;
      n = i - 1;
    }
    else
    {
      s[i - 1] = '1';
      n = i;
      ++ sum;
    }
    ans = min(ans , sum + f[n - 1] + 1);
    while (n && s[n - 1] == '0') -- n;
  }
  printf("%d",min(ans , sum));
}

int main()
{
  //int _;cin>>_;while (_--)
  work();
  return 0;
}