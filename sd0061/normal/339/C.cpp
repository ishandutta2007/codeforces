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
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define N 100005

int n , m ;
char s[15];
bool f[1005][21][11];
pair<int , int> p[1005][21][11];

void print(int i , int j , int k)
{
  if (i > 1)
    print(i -1 , p[i][j][k].fi , p[i][j][k].se);
  printf("%d " , k);
}
void work()
{
  int i , j = 0 , k , l , x , y = 0 , z;
  scanf("%s" , s + 1);
  scanf("%d",&m);
  f[0][10][0] = 1;
  for (i = 0 ; i < m ; ++ i)
  {
    int top , bot;
    if (!i) top = bot = 0;
    else if (i & 1) top = 1 , bot = 10;
    else top = -10 , bot = -1;
    for (j = top ; j <= bot ; ++ j)
      for (k = 0 ; k <= 10 ; ++ k) if (f[i][j + 10][k])
      {
        //printf("%d %d %d\n" , i , j , k);
        for (l = 1 ; l <= 10 ; ++ l) if (s[l] == '1' && l != k)
        {
          if (!(i & 1))
          {
            if (j + l <= 10)
              f[i + 1][j + l + 10][l] = 1 , p[i + 1][j + l + 10][l] = make_pair(j + 10 , k);
          }
          else
          {
            if (j - l >= -10)
              f[i + 1][j - l + 10][l] = 1 , p[i + 1][j - l + 10][l] = make_pair(j + 10 , k);
          }
        }
      }
  }
         int top , bot;
    if (i & 1) top = 1 , bot = 10;
    else top = -10 , bot = -1;
      x = 1 << 30;
  for (j = top ; j <= bot ; ++ j)
    for (k = 1 ; k <= 10 ; ++ k)
      if (f[m][j + 10][k])
        x = j , y = k;
   if (x != 1 << 30)
     puts("YES") , print(m , x + 10 , y);
   else
      puts("NO");
}

int main()
{
    work();
  return 0;
}