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

const ll inf = (ll)1e18;

struct tr{
  int l, r;
  ll val, add;
};

struct tp{
  int l, r, cnt;
};

int maxv;
int first[200200], next[200200];
ll sum[200200], d[200200];
tr rmq[600600];
tp p[200200];

inline void push(int v){
  rmq[v].val += rmq[v].add;
  if(v < maxv){
    rmq[v * 2].add += rmq[v].add;
    rmq[v * 2 + 1].add += rmq[v].add;
  }
  rmq[v].add = 0;
}

inline void calc(int v){
  rmq[v].val = max(rmq[v * 2].val, rmq[v * 2 + 1].val);
}

void update(int v, int l, int r, ll add){
  push(v);
  if(rmq[v].l > r || rmq[v].r < l){
    return;
  }
  if(rmq[v].l >= l && rmq[v].r <= r){
    rmq[v].add = add;
    push(v);
    return;
  }
  update(v * 2, l, r, add);
  update(v * 2 + 1, l, r, add);
  calc(v);
}

ll get(int v, int l, int r){
  push(v);
  if(rmq[v].l > r || rmq[v].r < l){
    return -inf;
  }
  if(rmq[v].l >= l && rmq[v].r <= r){
    return rmq[v].val;
  }
  ll res = max(get(v * 2, l, r), get(v * 2 + 1, l, r));
  calc(v);
  return res;
}

int main(){
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
  int n, m;
  scanf("%d %d", &n, &m);
  for(int i = 1; i <= n; i++){
    int a;
    scanf("%d", &a);
    sum[i] = sum[i - 1] + a;
  }
  for(int i = 1; i <= m; i++){
    scanf("%d %d %d", &p[i].l, &p[i].r, &p[i].cnt);
    next[i] = first[p[i].r];
    first[p[i].r] = i;
  }
  maxv = 1;
  while(maxv < n + 1){
    maxv *= 2;
  }
  for(int i = 0; i < maxv; i++){
    rmq[i + maxv].l = i + 1;
    rmq[i + maxv].r = i + 1;
  }
  for(int i = maxv - 1; i > 0; i--){
    rmq[i].l = rmq[i * 2].l;
    rmq[i].r = rmq[i * 2 + 1].r;
  }
  update(1, 1, 1, 0);
  for(int i = 1; i <= n; i++){
    for(int j = first[i]; j > 0; j = next[j]){
      update(1, 1, p[j].l, p[j].cnt);
    }
    d[i] = max(d[i - 1], get(1, 1, i) - sum[i]);
    update(1, i + 1, i + 1, d[i] + sum[i]);
  }
  printf("%I64d\n", d[n]);
  return 0;
}