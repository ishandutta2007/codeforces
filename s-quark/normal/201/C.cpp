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

int a[100004];
ll f[100004][3];

int main()
{
  #ifdef __FIO
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  #endif
  int n;
  int i, j;
  ll ans = 0LL;
  scanf("%d", &n);
  for(i = 1; i < n; i++)
    scanf("%d", &a[i]);
  f[0][0] = 0;
  f[0][1] = f[0][2] = -1LL<<60;
  for(i = 1; i < n; i++){
    f[i][0] = f[0][0];
    f[i][1] = f[0][1];
    f[i][2] = f[0][2];
    if(a[i] == 1){
      f[i][1] = max(f[i][1], max(f[i-1][0]+1, f[i-1][1]+1));
    }
    else if(a[i]){
      if(a[i]%2){
        a[i]--;
        j = 1;
      }
      else
        j = 0;
      f[i][0] = max(f[i][0], f[i-1][0]+a[i]);
      f[i][2] = max(f[i][2], f[i-1][1]+a[i]);
      f[i][2] = max(f[i][2], f[i-1][2]+a[i]);
      if(j)
        a[i]++;
      else
        a[i]--;
      f[i][1] = max(f[i][1], f[i-1][0]+a[i]);
      f[i][1] = max(f[i][1], f[i-1][1]+a[i]);
    }
    ans = max(ans, max(f[i][0], max(f[i][1], f[i][2])));
  }
  cout<<ans<<endl;
  return 0;
}