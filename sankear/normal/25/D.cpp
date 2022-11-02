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

int prev[2000], rank[2000], v[2000], u[2000], vv[2000], uu[2000];

int get(int a){
  if(prev[a] != a){
    prev[a] = get(prev[a]);
  }
  return prev[a];
}

inline void merge(int a, int b){
  if(rank[a] == rank[b]){
    prev[b] = a;
    rank[a]++;
    return;
  }
  if(rank[a] < rank[b]){
    prev[a] = b;
    return;
  }
  prev[b] = a;
}

int main(){
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; i++){
    prev[i] = i;
    rank[i] = 1;
  }
  int sz = 0;
  for(int i = 0; i < n - 1; i++){
    int a, b;
    scanf("%d %d", &a, &b);
    a--;
    b--;
    int aa = get(a);
    int bb = get(b);
    if(aa != bb){
      merge(aa, bb);
      continue;
    }
    v[sz] = a;
    u[sz++] = b;
  }
  int cur = 0;
  for(int i = 0; i < n - 1; i++){
    for(int j = i + 1; j < n; j++){
      int a = get(i);
      int b = get(j);
      if(a != b){
	vv[cur] = i;
	uu[cur++] = j;
	merge(a, b);
      }
    }
  }
  printf("%d\n", sz);
  for(int i = 0; i < sz; i++){
    printf("%d %d %d %d\n", v[i] + 1, u[i] + 1, vv[i] + 1, uu[i] + 1);
  }
  return 0;
}