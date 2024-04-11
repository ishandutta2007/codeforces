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
#include <set>
#include <map>
#define pb push_back
#define mp make_pair
#define N 1005
using namespace std;
int n , m , sx , sy , ex , ey , d[N][N];
char s[N][N];
int dx[] = {0 , 1 , 0 , -1} , dy[] = {1, 0 , -1 , 0};
void work()
{
  int i , j , x , y;
  scanf("%d%d",&n,&m);
  for (i = 1 ; i <= n ; ++ i)
    scanf("%s" , s[i] + 1);
  for (i = 1 ; i <= n ; ++ i)
    for (j = 1 ; j <= m ; ++ j)
    {
      if (s[i][j] == 'S') sx = i , sy = j;
      if (s[i][j] == 'E') ex = i , ey = j;
    }
  queue< pair<int ,int> > q;
  memset(d , -1 , sizeof(d));
  q.push(mp(ex , ey)) , d[ex][ey] = 0;

  while (!q.empty())
  {
    x = q.front().first , y = q.front().second , q.pop();
    for (i = 0 ; i < 4 ; ++ i) if (x + dx[i] > 0 && x + dx[i] <= n && y + dy[i] > 0 && y + dy[i] <= m)
      if (!~d[x + dx[i]][y + dy[i]] && s[x + dx[i]][y + dy[i]] != 'T')
      {
        d[x + dx[i]][y + dy[i]] = d[x][y] + 1;
        q.push(mp(x + dx[i] ,y + dy[i]));
      }
  }
  int ans = 0;
  for (i = 1 ; i <= n ; ++ i)
    for (j = 1 ; j <= m ; ++ j)
      if (~d[i][j] && isdigit(s[i][j]) && d[i][j] <= d[sx][sy])
        ans += s[i][j] - '0';
  cout << ans << endl;
}

int main()
{
    work();
  return 0;
}