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

const double eps = 1e-9;

ll x[2000], y[2000], a[2000], b[2000], c[2000];

inline bool leq(double a, double b){
  return b - a > -eps;
}

inline ll getl(double a){
  ll b = (ll)a;
  for(int j = b - 10; j <= b + 10; j++){
    if(leq(a, j)){
      return j;
    }
  }
}

inline ll getr(double a){
  ll b = (ll)a;
  for(int j = b + 10; j >= b - 10; j--){
    if(leq(j, a)){
      return j;
    }
  }
}

inline ll gcd(ll a, ll b){
  while(b > 0){
    a %= b;
    swap(a, b);
  }
  return a;
}

inline void fail(){
  printf("0\n");
  exit(0);
}

inline ll vec(ll x1, ll y1, ll x2, ll y2){
  return x1 * y2 - x2 * y1;
}

inline int sgn(ll a){
  if(a < 0){
    return -1;
  }
  if(a == 0){
    return 0;
  }
  return 1;
}

int main(){
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; i++){
    scanf("%I64d %I64d", &x[i], &y[i]);
  }
  x[n] = x[0];
  y[n] = y[0];
  for(int i = 1; i < n; i++){
    a[i] = x[i] * y[i + 1] - y[i] * x[i + 1];
    b[i] = x[i + 1] - x[i];
    c[i] = y[i] - y[i + 1];
  }
  ll vx = x[1] - x[0];
  ll vy = y[1] - y[0];
  ll g = gcd(abs(vx), abs(vy));
  vx = sgn(vx) * (abs(vx) / g);
  vy = sgn(vy) * (abs(vy) / g);
  ll l = 0, r = abs(x[1] - x[0]) / abs(vx);
  if(vec(x[2] - x[0], y[2] - y[0], x[3] - x[0], y[3] - y[0]) > 0){
    for(int i = 1; i < n; i++){
      ll val1 = vy * b[i] + vx * c[i];
      ll val2 = -a[i] - y[0] * b[i] - x[0] * c[i];
      if(val1 == 0){
	if(val2 <= 0){
	  continue;
	}
	fail();
      }
      if(val1 < 0){
	r = min(r, getr((double)val2 / val1));
	continue;
      }
      l = max(l, getl((double)val2 / val1));
    }
  }
  else{
    for(int i = 1; i < n; i++){
      ll val1 = vy * b[i] + vx * c[i];
      ll val2 = -a[i] - y[0] * b[i] - x[0] * c[i];
      if(val1 == 0){
	if(val2 >= 0){
	  continue;
	}
	fail();
      }
      if(val1 < 0){
	l = max(l, getl((double)val2 / val1));
	continue;
      }
      r = min(r, getr((double)val2 / val1));
    }
  }
  if(l > r){
    fail();
  }
  printf("%I64d\n", r - l + 1);
  return 0;
}