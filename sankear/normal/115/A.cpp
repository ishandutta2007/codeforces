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

int k;
int deg[3000], lst[3000];
int go[3000], next[3000], first[3000];
bool used[3000];

inline void add(int a, int b){
  go[++k] = b;
  next[k] = first[a];
  first[a] = k;
  deg[b]++;
}

int main(){
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
  int n;
  scanf("%d", &n);
  k = 0;
  for(int i = 0; i < n; i++){
    int p;
    scanf("%d", &p);
    if(p > -1){
      add(p - 1, i);
    }
  }
  int ans = 0;
  for(int i = 0; i < n; i++){
    int sz = 0;
    for(int j = 0; j < n; j++){
      if(!used[j] && deg[j] == 0){
	lst[sz++] = j;
      }
    }
    if(sz == 0){
      break;
    }
    for(int j = 0; j < sz; j++){
      used[lst[j]] = true;
      for(int z = first[lst[j]]; z > 0; z = next[z]){
	deg[go[z]]--;
      }
    }
    ans++;
  }
  printf("%d\n", ans);
  return 0;
}