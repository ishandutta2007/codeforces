#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <string.h>
#include <vector>
#include <set>
#include <map>

using namespace std;

typedef long long ll;
typedef long double ld;

const ll hx = (ll)(2e5 + 3);

char aa[2010], bb[2010], cc[2010];
ll a[2010], b[2010], c[2010], p[2010];
ll res[4000010];

inline void calc(char* s, ll* h, int len){
  h[0] = p[0] * s[0];
  for(int i = 1; i < len; i++){
    h[i] = h[i - 1] + p[i] * s[i];
  }
}

inline ll get(int l, int r){
  return a[r] - (l > 0 ? a[l - 1] : 0);
}

int main(){
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
  scanf("%s\n%s\n%s", aa, bb, cc);
  int n = strlen(aa);
  int m = strlen(bb);
  int k = strlen(cc);
  p[0] = 1;
  for(int i = 1; i <= n; i++){
    p[i] = p[i - 1] * hx;
  }
  calc(aa, a, n);
  calc(bb, b, m);
  calc(cc, c, k);
  ll hb = p[n] * b[m - 1];
  ll hc = p[n] * c[k - 1];
  int sz = 0;
  for(int i = 0; i < n; i++){
    if(i + m - 1 >= n){
      break;
    }
    for(int j = i; j < n; j++){
      if(j + k - 1 >= n){
	break;
      }
      if(j + k - 1 < i + m - 1){
	continue;
      }
      if(p[n - i] * get(i, i + m - 1) == hb && p[n - j] * get(j, j + k - 1) == hc){
	res[sz++] = p[n - i] * get(i, j + k - 1);
      }
    }
  }
  sort(res, res + sz);
  int ans = unique(res, res + sz) - res;
  printf("%d\n", ans);
  return 0;
}