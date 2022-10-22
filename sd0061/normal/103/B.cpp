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
#define N 105
#define LL long long
int n , m , cnt;
vector<int> e[N];
bool f[N];

void dfs(int x)
{
  f[x] = 1 , ++ cnt;
  for (int i = 0 ; i < e[x].size() ; ++ i)
    if (!f[e[x][i]])
      dfs(e[x][i]);
}

void work()
{
  int i , x , y;
  scanf("%d%d",&n,&m);
  if (n != m) {puts("NO");return;}
  for (i = 1 ; i <= m ; ++ i)
  {
    scanf("%d%d",&x,&y);
    e[x].push_back(y);
    e[y].push_back(x);
  }
  dfs(1);
  if (cnt == n)
    puts("FHTAGN!");
  else puts("NO");

}

int main()
{
  work();
  return 0;
}