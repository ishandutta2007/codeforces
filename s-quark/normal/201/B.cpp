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

int c[1024][1024];
int a[1024];

int sqr(int i){
  return i*i;
}

int main()
{
  #ifdef __FIO
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  #endif
  int n, m;
  int i, j;
  int li, lj;
  ll ans = 0, ans1;
  scanf("%d%d", &n, &m);
  for(i = 0; i < n; i++)
    for(j = 0; j < m; j++)
      scanf("%d", &c[i][j]);
  for(i = 0; i < n; i++){
    a[i] = 0;
    for(j = 0; j < m; j++)
      a[i] += c[i][j];
  }
  ans1 = 1LL<<60;
  for(i = 0; i <= n; i++){
    ll t = 0;
    for(j = 0; j < n; j++)
      t += (ll)sqr(j*2+1-i*2)*a[j];
    if(t < ans1){
      ans1 = t;
      li = i;
    }
  }
  ans += ans1;
  for(i = 0; i < m; i++){
    a[i] = 0;
    for(j = 0; j < n; j++)
      a[i] += c[j][i];
  }
  ans1 = 1LL<<60;
  for(i = 0; i <= m; i++){
    ll t = 0;
    for(j = 0; j < m; j++)
      t += (ll)sqr(j*2+1-i*2)*a[j];
    if(t < ans1){
      ans1 = t;
      lj = i;
    }
  }
  ans += ans1;
  printf("%I64d\n", ans*4);
  printf("%d %d\n", li, lj);
  return 0;
}