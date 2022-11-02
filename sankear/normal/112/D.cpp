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

const int maxch = (int)1e5;

int sz;
int a[100100], b[100100], ans[100100], first[100100];
int pos[31700000], next[31700000];

inline void add(int a, int b){
  pos[++sz] = b;
  next[sz] = first[a];
  first[a] = sz;
}

int main(){
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
  int n;
  scanf("%d", &n);
  for(int i = 1; i <= n; i++){
    scanf("%d %d", &a[i], &b[i]);
  }
  sz = 0;
  for(int i = n; i > 0; i--){
    for(int j = 1; j * j <= a[i]; j++){
      if(a[i] % j == 0){
	add(j, i);
	ans[i]++;
	if(j * j < a[i]){
	  add(a[i] / j, i);
	  ans[i]++;
	}
      }
    }
  }
  for(int i = 1; i <= maxch; i++){
    int last = -1;
    for(int j = first[i]; j > 0; j = next[j]){
      if(last > -1 && last >= pos[j] - b[pos[j]]){
	ans[pos[j]]--;
      }
      last = pos[j];
    }
  }
  for(int i = 1; i <= n; i++){
    printf("%d\n", ans[i]);
  }
  return 0;
}