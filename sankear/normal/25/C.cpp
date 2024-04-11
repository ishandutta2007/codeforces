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

ll d[400][400];

int main(){
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      scanf("%I64d", &d[i][j]);
    }
  }
  int m;
  scanf("%d", &m);
  for(int i = 0; i < m; i++){
    int a, b;
    ll c;
    scanf("%d %d %I64d", &a, &b, &c);
    a--;
    b--;
    d[a][b] = min(d[a][b], c);
    d[b][a] = min(d[b][a], c);
    for(int j = 0; j < n; j++){
      for(int z = 0; z < n; z++){
	d[j][z] = min(d[j][z], min(d[j][a] + d[a][b] + d[b][z], d[j][b] + d[b][a] + d[a][z]));
      }
    }
    ll ans = 0;
    for(int j = 0; j < n - 1; j++){
      for(int z = j + 1; z < n; z++){
	ans += d[j][z];
      }
    }
    if(i > 0){
      printf(" ");
    }
    printf("%I64d", ans);
  }
  printf("\n");
  return 0;
}