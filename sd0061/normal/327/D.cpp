#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <string>
#include <map>
using namespace std;
#define N 505
#define LL long long
LL Q = 1000000007;
int n , m;
char s[N][N];
bool f[N][N];
int dx[] =  {0 , 1 , 0 , -1} , dy[] = {1 , 0 , -1 , 0};
vector < pair<char , pair<int , int> > > ans;


void dfs(int x , int y , int ds)
{
  f[x][y] = 1;
  ans.push_back(make_pair('B' , make_pair(x , y)));
  for (int i = 0 ; i < 4 ; ++ i) if (x + dx[i] > 0 && x + dx[i] <= n) if (y + dy[i] > 0 && y + dy[i] <= m)
    if (s[x + dx[i]][y + dy[i]] != '#' && !f[x + dx[i]][y + dy[i]])
      dfs(x + dx[i] , y + dy[i] , ds + 1);
  if (ds)
    ans.push_back(make_pair('D' , make_pair(x , y))),
    ans.push_back(make_pair('R' , make_pair(x , y)));
}

void work()
{
  int i , j;
  scanf("%d%d",&n,&m);
  for (i = 1 ; i <= n ; ++ i)
    scanf("%s" , s[i] + 1);
  for (i = 1 ; i <= n ; ++ i)
    for (j = 1 ; j <= m ; ++ j)
      if (s[i][j] != '#' && !f[i][j])
        dfs(i , j , 0);
  printf("%d\n" , ans.size());
  for (i = 0 ; i < ans.size() ; ++ i)
    printf("%c %d %d\n" , ans[i].first , ans[i].second.first , ans[i].second.second);
}

int main()
{
   work();
   return 0;
}