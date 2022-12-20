#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define FOR(i, s, t) for(i = (s); i < (t); i++)
#define RFOR(i, s, t) for(i = (s)-1; i >= (t); i--)
const int MAXN = 128;

int s[MAXN];
int b[MAXN*2], next[MAXN*2];
int d[MAXN];

void dfs(int i)
{
  int j;
  for(j = s[i]; j != -1; j = next[j])
  {
    if(d[b[j]] == -1)
    {
      d[b[j]] = d[i]+1;
      dfs(b[j]);
    }
  }
}

int main()
{
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int n;
  int i0;
  int ans = 0;
  cin>>n;
  FOR(i0, 0, n)
  {
    int m, i, t;
    t = 0;
    cin>>m;
    memset(s, -1, sizeof s);
    for(i = 1; i < m; i++)
    {
      int u, v;
      cin>>u>>v;
      b[i] = u;
      b[i+m] = v;
      next[i] = s[v];
      s[v] = i;
      next[i+m] = s[u];
      s[u] = i+m;
    }
    for(i = 1; i <= m; i++)
    {
      memset(d, -1, sizeof d);
      d[i] = 0;
      dfs(i);
      for(int j = 1; j <= m; j++)
        t = max(t, d[j]);
    }
    ans += t;
  }
  cout<<ans<<endl;
  return 0;
}