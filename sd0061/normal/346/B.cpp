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
#include <map>
#include <set>
#include <list>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
//#pragma comment(linker, "/STACK:16777216")
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define N 105

char s[N] , t[N] , v[N];
int f[N][N][N] , n1 , n2 , m , u[N] , pi , pj , pk , pre[N][N][N];
int tr[N][26];
void print(int i , int j , int k)
{
  if (i + j <= 0) return;
  if (pre[i][j][k] == 1)
    print(i - 1 , j , k);
  else if (pre[i][j][k] == 2)
    print(i , j - 1 , k);
  else
  {
    print(i - 1 , j - 1 , pre[i][j][k] - 300);
    printf("%c" , s[i - 1]);
  }
}

void work()
{
  int i , j , k , l , ans = 0x80808080;
  scanf("%s%s%s",s ,t,v);
  memset(f , 0x80 , sizeof(f));
  n1 = strlen(s) , n2 = strlen(t) , m = strlen(v);
  u[0] = u[1] = 0;
  for (i = 1 ; i < m ;i ++)
  {
    j = u[i];
    while (j && v[i] != v[j]) j = u[j];
    u[i + 1] = v[i] == v[j] ? j + 1 : 0;
  }

  for (i = 0 ; i <= m ; ++ i)
    for (j = 0 ; j < 26 ; ++ j)
    {
      k = i;
      while (k && j + 'A' != v[k]) k = u[k];
      if (j + 'A' == v[k]) ++ k;
      tr[i][j] = k;
    }


  f[0][0][0] = 0;
  for (i = 0 ; i <= n1 ; ++ i)
    for (j = 0 ; j <= n2 ; ++ j)
      for (k = 0 ; k < m ; ++ k) if (f[i][j][k] >= 0)
      {
        int x = f[i][j][k];
        if (x > f[i + 1][j][k])
          f[i + 1][j][k] = max(f[i + 1][j][k] , x) , pre[i + 1][j][k] = 1;
        if (x > f[i][j + 1][k])
          f[i][j + 1][k] = max(f[i][j + 1][k] , x) , pre[i][j + 1][k] = 2;
        if (s[i] == t[j])
        {
          l = tr[k][s[i] - 'A'];
          if (l != m && f[i + 1][j + 1][l] < x + 1)
            f[i + 1][j + 1][l] = max(f[i + 1][j + 1][l] , x + 1) , pre[i + 1][j + 1][l] = 300 + k;
        }
        if (f[i][j][k] > ans)
          ans = f[i][j][k] , pi = i , pj = j , pk = k;
      }
  if (ans > 0)
    print(pi , pj , pk);
  else puts("0");
}

int main()
{
  work();
  return 0;
}