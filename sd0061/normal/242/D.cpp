#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <map>
#include <queue>
#include <utility>
using namespace std;
#define N 100005
int n , m , cnt[N] , num[N];
vector<int> e[N] ,ans;
queue<int> q;

void BFS()
{
  int i , x , y;   
  for (i = 1 ;i <= n ;i ++)
    if (num[i] == cnt[i])
      q.push(i);
  while (!q.empty())
  {
    x = q.front(), q.pop();
    if (num[x] != cnt[x]) continue;
    num[x] ++ ,ans.push_back(x);
    for (i = 0 ;i < e[x].size() ; i ++)
    {
      y = e[x][i] , num[y] ++;
      if (num[y] == cnt[y])
        q.push(y);    
    }     
  }   
  printf("%d\n",ans.size());
  for (i = 0 ; i < ans.size() ; i ++)
    printf("%d ",ans[i]);    
}

int main()
{
  int i , x , y;
  scanf("%d %d",&n,&m);
  while (m --)
  {
    scanf("%d %d",&x,&y);
    e[x].push_back(y);
    e[y].push_back(x);    
  }   
  for (i = 1 ; i <= n ;i ++)
    scanf("%d",&cnt[i]);
  BFS();
  return 0;    
}