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
typedef double du;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define FOR(i, s, t) for(i = (s); i < (t); i++)
#define RFOR(i, s, t) for(i = (s)-1; i >= (t); i--)
const int MAXN = 100005;

du a[MAXN*2];

du ans[MAXN];

int main()
{
  #ifdef __FIO
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  #endif
  int n;
  du l, v1, v2;
  int i;
  int h, t;
  du len;
  du pre;
  scanf("%d%lf%lf%lf", &n, &l, &v1, &v2);
  len = l/(v1+v2)*v2;
  for(i = 0; i < n; i++){
    scanf("%lf", &a[i]);
    a[i+n] = a[i]+l*2;
  }
  a[n*2] = 1e15;
  h = 0;
  t = 1;
  while(a[t]-a[h] < len)
    t++;
  h++;
  pre = a[0];
  while(h <= n){
    if(a[t]-a[h] > len){
      ans[t-h] += a[h]-pre;
      pre = a[h];
      h++;
    }
    else{
      ans[t-h] += a[t]-len-pre;
      pre = a[t]-len;
      t++;
    }
  }
  for(i = 0; i <= n; i++)
    printf("%.12lf\n", ans[i]/l/2);
  return 0;
}