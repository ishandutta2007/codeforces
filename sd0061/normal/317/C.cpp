#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <set>
using namespace std;
#define N 305
int n , v , m;
int a[N] , b[N];
vector<int> e[N];
pair<int , int> p[N];
vector< pair< pair<int,int> , int> > ans;
bool f[N] , d[N];

void add(int x , int y, int z)
{
  ans.push_back(make_pair(make_pair(x , y) , z));
  a[x] -= z , a[y] += z;
}

void dfs(int x , int flow)
{
  int i , y , z;
  f[x] = 1 , flow -= a[x];
  for (i = 0 ; i < e[x].size() ; ++ i)
    if (flow > 0 && !f[y = e[x][i]])
      if (!d[y])
      {
        dfs(y , flow);
        z = min(flow , a[y]);
        flow -= z;
        add(y , x , z);
      }
      else
      {
        add(y , x , flow);
        dfs(y , b[y]);
        flow = 0;
        if (a[y] < b[y])
        {
          flow = b[y] - a[y];
          add(x , y , flow);
        }
      }
}
void work()
{
  int i , j , x , y;
  cin >> n >> v >> m;
  for (i = 1 ; i <= n ; ++ i)
    cin >> a[i];
  for (i = 1 ; i <= n ; ++ i)
    cin >> b[i] , p[i] = make_pair(-b[i] , i);
  while (m --)
  {
    scanf("%d%d",&x,&y);
    e[x].push_back(y);
    e[y].push_back(x);
  }
  sort(p + 1 , p + n + 1);

  for (i = 1 ; i <= n ; ++ i)
  {
    memset(f , 0 , sizeof(f));
    dfs(p[i].second , -p[i].first);
    d[p[i].second] = 1;
  }
  for (i = 1 ; i <= n ; ++ i)
    if (a[i] != b[i])
    {
      puts("NO");
      return;
    }
  printf("%d\n", ans.size());
  for (i = 0 ; i < ans.size() ; ++ i)
    printf("%d %d %d\n" , ans[i].first.first , ans[i].first.second , ans[i].second);
}


int main()
{
  work();
  return 0;
}