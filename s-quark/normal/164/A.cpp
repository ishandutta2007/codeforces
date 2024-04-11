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
const int MAXN = 100004;

int f[MAXN];
vector<int> s[MAXN], r[MAXN];
bool vis1[MAXN], vis2[MAXN];
int q[MAXN];

int main()
{
  #ifdef __FIO
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  #endif
  int i, j;
  int n, m;
  int h, t;
  scanf("%d%d", &n, &m);
  for(i = 1; i <= n; i++)
    scanf("%d", &f[i]);
  for(i = 0; i < m; i++){
    int a, b;
    scanf("%d%d", &a, &b);
    s[a].pb(b);
    r[b].pb(a);
  }
  h = t = 0;
  for(i = 1; i <= n; i++){
    if(f[i] == 1){
      vis1[i] = 1;
      q[t++] = i;
    }
  }
  while(h < t){
    i = q[h++];
    for(j = 0; j < s[i].size(); j++)
      if(!vis1[s[i][j]]){
        vis1[s[i][j]] = 1;
        q[t++] = s[i][j];
      }
  }
  h = t = 0;
  for(i = 1; i <= n; i++)
    if(f[i] == 2){
      vis2[i] = 1;
      q[t++] = i;
    }
  while(h < t){
    i = q[h++];
    if(f[i] == 1)
      continue;
    for(j = 0; j < r[i].size(); j++)
      if(!vis2[r[i][j]]){
        vis2[r[i][j]] = 1;
        q[t++] = r[i][j];
      }
  }
  for(i = 1; i <= n; i++)
    printf("%d\n", vis1[i]&&vis2[i]);
  return 0;
}