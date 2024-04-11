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
#define fi first
#define se second
using namespace std;
#define N 10
int n , K;
char s[N][N] , g[505][505];
int power[N];

void print(int x , int y , int d)
{
  if (d == 0) return;
  int i , j , k , l;
  for (i = 1 ; i <= n ; ++ i)
    for (j = 1 ; j <= n ; ++ j)
      if (s[i][j] == '*')
      {
        for (k = 1 ; k <= power[d - 1] ; ++ k)
          for (l = 1 ; l <= power[d - 1] ; ++ l)
            g[x + (i - 1) * power[d - 1] + k - 1][y + (j - 1) * power[d - 1] + l - 1] = '*';
      }
      else print(x + (i - 1) * power[d - 1] , y + (j - 1) * power[d - 1] , d - 1);
}

void work()
{
  int i , j;
  scanf("%d%d\n",&n,&K);

  power[0] = 1;
  for (i = 1 ; i <= K ; ++ i)
    power[i] = power[i - 1] * n;

  for (i = 1 ; i <= power[K] ; ++ i)
    for (j = 1 ; j <= power[K] ; ++ j)
      g[i][j] = '.';

  for (i = 1 ; i <= n ; ++ i)
    scanf("%s" , s[i] + 1);
  print(1 , 1 , K);

  for (i = 1 ; i <= power[K] ; ++ i)
    puts(g[i] + 1);
}

int main()
{
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  //while(scanf("%s", s) , s[0] != '#')
  //int _;cin>>_;while(_--)
    work();
  return 0;
}