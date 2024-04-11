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

struct tp{
  ll x, y, len;
};

inline ll sqr(ll a){
  return a * a;
}

inline ll calc(const tp &a){
  return sqr(a.x) + sqr(a.y);
}

inline ll vec(const tp &a, const tp &b){
  return a.x * b.y - b.x * a.y;
}

bool operator < (const tp &a, const tp &b){
  ll v = vec(a, b);
  if(v == 0){
    return a.len < b.len; 
  }
  return v > 0;
}

bool operator == (const tp &a, const tp &b){
  return a.x == b.x && a.y == b.y;
}

tp v1, v2, cp;
tp p[500500];
int stack[500500];
int dx[5] = {0, -1, 0, 1, 0};
int dy[5] = {0, 0, 1, 0, -1};

inline bool better(const tp &a, const tp &b){
  if(a.x != b.x){
    return a.x < b.x;
  }
  return a.y < b.y;
}

inline bool bad(const tp &a, const tp &b, const tp &c){
  v1.x = b.x - a.x;
  v1.y = b.y - a.y;
  v2.x = c.x - a.x;
  v2.y = c.y - a.y;
  ll v = vec(v1, v2);
  if(v == 0){
    return calc(v1) < calc(v2);
  }
  return v < 0;
}

int main(){
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
  int n = 0, m;
  scanf("%d", &m);
  for(int i = 0; i < m; i++){
    ll x, y;
    scanf("%I64d %I64d", &x, &y);
    for(int j = 0; j < 5; j++){
      p[n].x = x + dx[j];
      p[n++].y = y + dy[j];
    }
  }
  sort(p, p + n, better);
  n = unique(p, p + n) - p;
  for(int i = 1; i < n; i++){
    p[i].x -= p[0].x;
    p[i].y -= p[0].y;
    p[i].len = calc(p[i]);
  }
  sort(p + 1, p + n);
  for(int i = 1; i < n; i++){
    p[i].x += p[0].x;
    p[i].y += p[0].y;
  }
  int k = 0;
  for(int i = 0; i < n; i++){
    while(k > 1 && bad(p[stack[k - 2]], p[stack[k - 1]], p[i])){
      k--;
    }
    stack[k++] = i;
  }
  for(int i = 0; i < n; i++){
    p[i].x += cp.x;
    p[i].y += cp.y;
  }
  stack[k] = stack[0];
  ll ans = 0;
  for(int i = 0; i < k; i++){
    ans += max(abs(p[stack[i]].x - p[stack[i + 1]].x), abs(p[stack[i]].y - p[stack[i + 1]].y));
  }
  printf("%I64d\n", ans);
  return 0;
}