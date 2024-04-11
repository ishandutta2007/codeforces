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

const int inf = (int)1e9;

struct tp{
  int x, y;
};

bool operator < (const tp &a, const tp &b){
  return a.x < b.x;
}

int maxv;
tp p[1000010];
int y[1000010];
int rmq[2098010];

inline void update(int a, int b){
  a += maxv - 1;
  rmq[a] = b;
  while(a > 1){
    a /= 2;
    rmq[a] = max(rmq[a * 2], rmq[a * 2 + 1]);
  }
}

inline int get(int l, int r){
  int res = -inf;
  l += maxv - 1;
  r += maxv - 1;
  while(l <= r){
    res = max(res, rmq[l]);
    l = (l + 1) / 2;
    res = max(res, rmq[r]);
    r = (r - 1) / 2;
  }
  return res;
}

int main(){
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
  int n;
  scanf("%d", &n);
  for(int i = 1; i <= n; i++){
    int x;
    scanf("%d", &x);
    p[x].y = i;
  }
  for(int i = 1; i <= n; i++){
    int y;
    scanf("%d", &y);
    p[y].x = i;
  }
  sort(p + 1, p + n + 1);
  for(int i = 1; i <= n; i++){
    y[i] = p[i].y;
  }
  sort(y + 1, y + n + 1);
  maxv = 1;
  while(maxv < n){
    maxv *= 2;
  }
  for(int i = 1; i < 2 * maxv; i++){
    rmq[i] = -inf;
  }
  for(int i = 1; i <= n; i++){
    int res;
    int l = 1;
    int r = n;
    while(l <= r){
      int mid = (l + r) / 2;
      if(y[mid] == p[i].y){
	res = mid;
	break;
      }
      if(y[mid] < p[i].y){
	l = mid + 1;
      }
      else{
	r = mid - 1;
      }
    }
    update(res, max(get(res + 1, n) + 1, 1));
  }
  printf("%d\n", rmq[1]);
  return 0;
}