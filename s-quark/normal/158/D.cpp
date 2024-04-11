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

int s[1<<20];
int sum[1<<20];

int main()
{
  #ifdef __FIO
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  #endif
  int n, i, j;
  int ans = 0;
  scanf("%d", &n);
  for(i = 0; i < n; i++){
    scanf("%d", &s[i]);
    ans += s[i];
  }
  for(i = 1; 3*i <= n; i++){
    if(n%i == 0){
      for(j = 0; j < i; j++)
        sum[j] = 0;
      for(j = 0; j < n; j++)
        sum[j%i] += s[j];
      for(j = 0; j < i; j++)
        ans = max(ans, sum[j]);
    }
  }
  printf("%d\n", ans);
  return 0;
}