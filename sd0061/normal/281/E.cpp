#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <cctype>
#include <queue>
#include <cstdio>
#include <utility>
#include <map>
#include <algorithm>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define LL long long
#define N 100005
using namespace std;
int n , d[N];
vector<int> e[N];

void dfs(int x , int f)
{
  d[x] = d[f] + 1;
  for (int i = 0 ;i < e[x].size() ; ++ i) if (e[x][i] != f)
     dfs(e[x][i] , x);
}
void work()
{
  int x , y , i;
  cin >> n;
  for (i = 1 ; i < n ; i ++)
    scanf("%d%d",&x,&y) , e[x].pb(y) , e[y].pb(x);
  dfs(1 , 0);
  double ans = 0;
  for (i = 1 ; i <= n ;i ++)
    ans += 1.0 / d[i];
  printf("%.15lf", ans);
}

int main()
{
  //int _;cin>>_;while(_--)
   work();
  return 0;
}