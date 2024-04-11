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
const int MAXN = 50004;

int dp[MAXN][504];
int s[MAXN];
int b[MAXN*2], next[MAXN*2];
int q[MAXN];
int vis[MAXN];

int main()
{
  #ifdef __FIO
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  #endif
  int n, k;
  int i, j;
  int h, t;
  ll ans = 0;
  cin>>n>>k;
  memset(s, -1, sizeof s);
  for(i = 1; i < n; i++){
    cin>>b[i]>>b[i+n];
    next[i+n] = s[b[i]];
    s[b[i]] = i+n;
    next[i] = s[b[i+n]];
    s[b[i+n]] = i;
  }
  h = t = 0;
  q[t++] = 1;
  vis[1] = true;
  while(h < t){
    i = q[h++];
    for(j = s[i]; j != -1; j = next[j]){
      if(!vis[b[j]]){
        vis[b[j]] = 1;
        q[t++] = b[j];
      }
    }
  }
  memset(vis, 0, sizeof vis);
  for(int x = n-1; x >= 0; x--){
    i = q[x];
    vis[i] = true;
    memset(dp[i], 0, sizeof dp[i]);
    dp[i][0] = 1;
    for(j = s[i]; j != -1; j = next[j]){
      if(vis[b[j]]){
        int u = b[j];
        for(int y = 0; y < k; y++)
          ans += (ll)dp[u][y]*dp[i][k-y-1];
        for(int y = 0; y < k; y++)
          dp[i][y+1] += dp[u][y];
      }
    }
  }
  cout<<ans<<endl;
  return 0;
}