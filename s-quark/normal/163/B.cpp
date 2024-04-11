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
typedef long double ld;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define FOR(i, s, t) for(i = (s); i < (t); i++)
#define RFOR(i, s, t) for(i = (s)-1; i >= (t); i--)
const int MAXN = 100004;
pair<int, pair<int, int> > a[MAXN];
int v[MAXN];

int main()
{
  #ifdef __FIO
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  #endif
  ld l, r;
  int n, k;
  int i, j;
  scanf("%d%d%*d", &n, &k);
  for(i = 0; i < n; i++){
    a[i].se.se = i+1;
  }
  for(i = 0; i < n; i++)
    scanf("%d", &a[i].fi);
  for(i = 0; i < n; i++)
    scanf("%d", &a[i].se.fi);
  sort(a, a+n);
  for(i = 0; i < n; i++)
    v[i] = a[i].se.fi;
  l = 0.;
  r = 1e6;
  int cnt = 0;
  while(cnt < 200){
    j = 1;
    ld mid = (l+r)/2;
    for(i = 0; i < n; i++)
      if(v[i]*mid >= j)
        j++;
    if(j > k)
      r = mid;
    else
      l = mid;
    cnt++;
  }
  j = 1;
  for(i = 0; j <= k; i++)
    if(v[i]*r >= j){
      printf("%d ", a[i].se.se);
      j++;
    }
  printf("\n");
  return 0;
}