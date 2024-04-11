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
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
#define N 5005
#define M 100005
#define LL long long
void RD(int& x)
{
  x = 0; char c;
  for (c = getchar() ;!isdigit(c) ; c = getchar()); x = c - '0';
  for (c = getchar() ; isdigit(c) ; c = getchar()) x = x * 10 + c - '0';
}

int n , s[N] , f[N] , w[N];
vector< pair<int ,int> > e[N];

void dfs(int x , int fa)
{
  ++ s[x] ,  f[x] = fa;
  for (int i = 0 ; i < e[x].size() ; ++ i)
  {
    int y = e[x][i].fi;
    if (y != fa)
      w[y] = e[x][i].se , dfs(y , x) , s[x] += s[y];
  }
}

long long dp[N] , node[N] , minDis , sum;
bool vis[N];

void dfs1(int x , int ban , int sz)
{
    dp[x] = 0;
    node[x] = 1;
    vis[x] = true;
    int size = e[x].size();
    for (int i = 0; i < size; ++i)
    {
        int y = e[x][i].fi;
        if (y != ban && !vis[y])
        {
            dfs1(y , ban , sz);
            sum += node[y] * (sz - node[y]) * e[x][i].se;
            dp[x] += dp[y] + node[y] * e[x][i].se;
            node[x] += node[y];
        }
    }
}

/* 
 *  */
void dfs2(int x ,int ban , int sz)
{
    vis[x] = true;
    minDis = min(dp[x] , minDis);
    int size = e[x].size();
    for (int i = 0; i < size; ++i)
    {
        int y = e[x][i].fi;
        if (y != ban && !vis[y])
        {
            // xydp[y]
            dp[y] = dp[x] + (LL)(sz - 2 * node[y]) * e[x][i].se;
            dfs2(y , ban , sz);
        }
    }
}

LL cal(int x , int y , int sz)
{
    minDis = 1LL << 60;
    memset(vis, false, sizeof(vis));
    dfs1(x , y , sz); // 1
    memset(vis, false, sizeof(vis));
    dfs2(x , y , sz);
    return minDis;
}

void work()
{
  int i , x , y , z;
  LL ans = 1LL << 60;

  scanf("%d",&n);
  for (i = 1 ; i < n ; ++ i)
  {
    scanf("%d%d%d",&x , &y , &z);
    e[x].pb(mp(y , z));
    e[y].pb(mp(x , z));
  }
  dfs(1 , 0);
  for (i = 2 ; i <= n ; ++ i)
  {
    sum = 0;
    sum = (LL) w[i] * s[i] * (n - s[i]);
    sum += cal(i , f[i] , s[i]) * (n - s[i]);
    sum += cal(f[i] , i , n - s[i]) * s[i];
    ans = min(ans , sum);
  }
  cout << ans << endl;
}

int main()
{
  //freopen("~input.txt","r",stdin);
  //freopen("~output.txt","w",stdout);
  //init();
  //int _;cin>>_;while(_--)
  //while (scanf("%s" , s) , s[0] != '#')
    work();
  return 0;
}