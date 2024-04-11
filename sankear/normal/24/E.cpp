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

const double eps = 1e-18;
const double inf = 1e19;
const double infans = 2e9;
const int op = 100;

struct tp{
  int x, v;
};

bool operator < (const tp &a, const tp &b){
  return a.x < b.x;
}

tp p[500500];

inline bool leq(double a, double b){	
  return b - a > -eps;
}

int main(){
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; i++){
    scanf("%d %d", &p[i].x, &p[i].v);
  }
  sort(p, p + n);
  double ans = -1;
  double l = 0;
  double r = infans;
  for(int it = 0; it < op; it++){
    double mid = (l + r) / 2;
    double maxx = -inf;
    bool fl = false;
    for(int i = 0; i < n; i++){
      double cur = (double)p[i].v * mid + p[i].x;
      if(p[i].v < 0){
	if(leq(cur, maxx)){
	  fl = true;
	  break;
	}
	continue;
      }
      maxx = max(maxx, cur);
    }
    if(fl){
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