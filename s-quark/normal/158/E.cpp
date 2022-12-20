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

int t[10240], d[10240];
int dp[2][10240];


int main()
{
  #ifdef __FIO
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  #endif
  int n, k;
  int i, j;
  int ans;
  int *prev, *cur;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++)
    scanf("%d%d", &t[i], &d[i]);
  for(i = 0; i <= k+5; i++)
    t[n+i] = 86401;
  prev = dp[0];
  cur = dp[1];
  for(i = 0; i <= k; i++)
    prev[0] = 0;
  ans = t[k]-1;
  for(i = 0; i < n; i++){
    cur[0] = prev[0]+d[i];
    for(j = 1; j <= k; j++)
      cur[j] = min(prev[j]+d[i], prev[j-1]);
    swap(cur, prev);
    for(j = 0; j <= k; j++)
      ans = max(ans, t[i+k-j+1]-t[i]-prev[j]);
    for(j = 0; j <= k; j++)
      prev[j] = max(0, prev[j]-t[i+1]+t[i]);
  }
  printf("%d\n", ans);
  return 0;
}