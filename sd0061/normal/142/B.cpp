#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
#define LL long long
#define N 1005
int n , m , s1 , s2;
bool f[N][N];

int dx[] = {1 , 1 , 2 , 2 , -1 , -1 , -2 , -2};
int dy[] = {2 , -2 , 1 , -1 , 2 , -2 , 1 , -1};
bool in(int x , int y) {return x > 0 && x <= n && y > 0 && y <= m;}

void dfs(int x , int y , int c)
{
  if (x < 1 || y < 1 || y > m || x > n) return;
  if (f[x][y]) return;
  f[x][y] = 1;
  c ? ++ s1 : ++ s2;
  for (int i = 0 ; i < 8 ; ++ i)
    //if (in(x + dx[i] , y + dy[i])) if (!f[x + dx[i]][y + dy[i]])
      dfs(x + dx[i] , y + dy[i] , !c);
}

void work()
{
  int i , j;
  scanf("%d%d",&n,&m);
  int ans = 0;
  for (i = 1 ; i <= n ; ++ i)
    for (j = 1 ; j <= m ; ++ j) if (!f[i][j])
    {
      s1 = s2 = 0;
      dfs(i , j , 0);
      ans += max(s1 , s2);
    }
  cout << ans << endl;

}

int main()
{
  //freopen("1.txt" , "r" , stdin);
  work();
  return 0;
}