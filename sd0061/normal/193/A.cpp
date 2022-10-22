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
#define N 55
#define LL long long
char s[N][N];
int n , m , cnt , sum;
bool f[N][N];

void dfs(int x , int y)
{
  f[x][y] = 1 , ++ sum;
  for (int i = -1 ; i <= 1 ;++ i)
    for (int j = -1 ; j <= 1 ; ++ j)
      if (abs(i) + abs(j) == 1)
        if (s[x + i][y + j] == '#' && !f[x + i][y + j])
          dfs(x + i , y + j);

}

void work()
{
  int i , j , h , e;
  cin >> n >> m;
  for (i = 1 ; i <= n ; ++ i)
    scanf("%s" , s[i] + 1);
  for (i = 1 ; i <= n ; ++ i)
    for (j = 1 ; j <= m ; ++ j)
      cnt += (s[i][j] == '#');
  if (cnt < 3) 
  {
    puts("-1");
    return;  
  }
  for (i = 1 ; i <= n ; ++ i)
    for (j = 1 ; j <= m ; ++ j)
      if (s[i][j] == '#')
      {
        s[i][j] = '.';
        memset(f , 0 , sizeof(f));
        sum = 0;
        for (h = 1 ; h <= n ; ++ h)
        for (e = 1 ; e <= m ; ++ e) if (s[h][e] == '#')
        {
          dfs(h , e);
          goto hehe;
        }
        hehe:
        s[i][j] = '#';
        if (sum + 1 != cnt)
        {
          puts("1");
          return;
        }
      }
  puts("2");
}


int main()
{
 // freopen("~input.txt","r",stdin);
 // freopen("~output.txt","w",stdout);
//  int _; cin >> _; while (_ --)
    work();
  return 0;
}