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
const int MAXN = 1000004;

int num[MAXN];
int a[MAXN*2], b[MAXN];

int main()
{
  #ifdef __FIO
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  #endif
  int n, m;
  int i, j;
  int ans = 0;
  scanf("%d%d", &n, &m);
  for(i = 0; i < n; i++)
    scanf("%d", &a[i]);
  for(i = 0; i < m; i++)
    scanf("%d", &b[i]);
  for(i = 0; i < m; i++)
    num[b[i]] = i+1;
  for(i = 0; i < n; i++)
    a[i] = a[i+n] = num[a[i]];
  a[n*2] = 0;
  i = 1;
  if(a[0] == 0)
    j = 1;
  else{
    j = 0;
    ans = 1;
  }
  while(i < 2*n){
    if(a[i] == 0){
      j = i+1;
    }
    else if(a[i-1] == 0){
      j = i;
    }
    else if(a[i] > a[i-1]){
      while(a[i-1] < a[j] && a[i] >= a[j])
        j++;
    }
    else{
      while(a[j] > a[i-1])
        j++;
      while(a[j] <= a[i])
        j++;
    }
    ans = max(i-j+1, ans);
    i++;
  }
  printf("%d\n", ans);
  return 0;
}