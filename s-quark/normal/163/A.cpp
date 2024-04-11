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
const int N = 5004;
const int MOD = 1000000007;

int f[N][N];
char s[N], t[N];

int main()
{
  #ifdef __FIO
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  #endif
  int n, m;
  ll ret = 0;
  scanf("%s%s", s, t);
  n = strlen(s);
  m = strlen(t);
  for(int i = 0; i <= n; i++)
    for(int j = 0; j <= m; j++)
      if(i == 0 || j == 0)
        f[i][j] = 0;
      else{
        if(s[i-1] == t[j-1])
          ret += f[i][j] = f[i-1][j-1]+1;
        f[i][j] += f[i][j-1];
        f[i][j]%=MOD;
      }
  ret %= MOD;
  printf("%d\n", ret);
  return 0;
}