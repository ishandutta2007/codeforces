#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
using namespace std;
#define LL long long
#define N 2005
int n , m , k;
int d[N][N];
bool f[N][N];
queue< pair<int,int> > q;


void work()
{
  int i , j , x , y;
  scanf("%d%d%d",&n,&m,&k);
  while (k --)
    scanf("%d%d",&x,&y) , f[x][y] = 1 , q.push(make_pair(x , y));
  while (!q.empty())
  {
    x = q.front().first , y = q.front().second , q.pop();
    for (i = -1 ; i <= 1 ; ++ i) for (j = -1 ; j <= 1 ; ++ j) if (abs(i) + abs(j) == 1)
      if (x + i > 0 && x + i <= n && y + j > 0 && y + j <= m && !f[x + i][y + j])
      {
        f[x + i][y + j] = 1;
        d[x + i][y + j] = d[x][y] + 1;
        q.push(make_pair(x + i , y + j));
      }
  }
  x = y = 1;
  for (i = 1 ; i <= n ; ++ i)
    for (j = 1 ; j <= m ; ++ j)
      if (d[i][j] > d[x][y])
        x = i , y = j;
  printf("%d %d", x , y);
}

int main()
{
  freopen("input.txt", "r" , stdin);
  freopen("output.txt", "w" , stdout);
    
  work();
  return 0;
}