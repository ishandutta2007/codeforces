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
const double inf = 1e4;
const int op = 100;

double d[200], p[200];
double f[200][200];

inline bool leq(double a, double b){
  return b - a > -eps;
}

inline double sqr(double a){
  return a * a;
}

int main(){
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
  int n, k, ie, x0, y0;
  scanf("%d %d %d %d %d", &n, &k, &ie, &x0, &y0);
  double e = (double)ie / 1000;
  for(int i = 1; i <= n; i++){
    int x, y;
    scanf("%d %d", &x, &y);
    d[i] = sqr(x - x0) + sqr(y - y0);
  }
  double ans = -1;
  double l = 0;
  double r = inf;
  for(int it = 0; it < op; it++){
    double mid = (l + r) / 2;
    double mmid = mid * mid;
    for(int i = 1; i <= n; i++){
      if(leq(d[i], mmid)){
	p[i] = 1;
	continue;
      }
      p[i] = exp(1 - d[i] / mmid);
    }
    for(int i = 0; i <= n; i++){
      for(int j = 0; j <= n; j++){
	f[i][j] = 0;
      }
    }
    f[0][0] = 1;
    for(int i = 1; i <= n; i++){
      f[i][0] = f[i - 1][0] * p[i];
      for(int j = 1; j <= i; j++){
	f[i][j] = f[i - 1][j - 1] * (1 - p[i]) + f[i - 1][j] * p[i];
      }
    }
    double cur = 0;
    for(int i = n - k + 1; i <= n; i++){
      cur += f[n][i];
    }
    if(leq(cur, e)){
      ans = mid;
      r = mid;
    }
    else{
      l = mid;
    }
  }
  printf("%.18lf\n", ans);
  return 0;
}