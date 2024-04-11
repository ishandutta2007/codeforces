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
#define N 505
#define LL long long
char str[N];
int f[N][N] , p[N][N] , m , n;
string s[N][N];
void print(int i , int j)
{
  if (i == 0) return;
  for (int k = 1 ; k <= i ; ++ k)
    if (f[i][j] == f[k - 1][j - 1] + p[k][i])
    {
      print(k - 1 , j - 1);
      cout << s[k][i];
      if (i != n) putchar('+');
      break;
    }
}

void work()
{
  int i , j , k , x;
  scanf("%s%d" , str + 1 , &m);
  n = strlen(str + 1);
  for (k = 1 ; k <= n ; ++ k)
    for (i = 1 ; i + k - 1 <= n ; ++ i)
    {
      j = i + k - 1;
      if (str[i] != str[j])
      {
        p[i][j] = p[i + 1][j - 1] + 1;
        s[i][j] += str[i];
        s[i][j] += s[i + 1][j - 1];
        if (i != j) s[i][j] += str[i];
      }
      else
      {
        p[i][j] = p[i + 1][j - 1];
        s[i][j] += str[i];
        s[i][j] += s[i + 1][j - 1];
        if (i != j) s[i][j] += str[j];
      }
    }
  for (j = 1 ; j <= n; ++ j) f[j][0] = 1 << 30;

  for (i = 1 ; i <= n ; ++ i)
    for (j = 1 ; j <= min(i , m); ++ j)
    {
      f[i][j] = 1 << 30;
      for (k = 1 ; k <= i ; ++ k)
        f[i][j] = min(f[i][j] , f[k - 1][j - 1] + p[k][i]);
    }
  x = 1;
  for (i = 2 ; i <= m ; ++ i)
    if (f[n][i] < f[n][x])
      x = i;
  cout << f[n][x] << endl;
  print(n , x);
}


int main()
{
    work();
  return 0;
}