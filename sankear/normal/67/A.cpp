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

char a[2000];
int res[2000];
int d[2000][2000], dd[2000][2000], ud[2000][2000];

int main(){
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
  int n;
  scanf("%d\n", &n);
  for(int i = 1; i < n; i++){
    scanf("%c", &a[i]);
  }
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= n; j++){
      d[i][j] = inf;
    }
  }
  for(int i = 1; i <= n; i++){
    d[1][i] = i;
  }
  for(int i = 1; i <= n; i++){
    if(i > 1){
      for(int j = 1; j <= n; j++){
	if(a[i - 1] == '='){
	  d[i][j] = min(d[i][j], d[i - 1][j] + j);
	  continue;
	}
	if(a[i - 1] == 'L'){
	  d[i][j] = min(d[i][j], ud[i - 1][j + 1] + j);
	  continue;
	}
	d[i][j] = min(d[i][j], dd[i - 1][j - 1] + j);
      }
    }
    dd[i][0] = inf;
    for(int j = 1; j <= n; j++){
      dd[i][j] = min(dd[i][j - 1], d[i][j]);
    }
    ud[i][n + 1] = inf;
    for(int j = n; j > 0; j--){
      ud[i][j] = min(ud[i][j + 1], d[i][j]);
    }
  }
  int ans = inf, num;
  for(int i = 1; i <= n; i++){
    if(d[n][i] < ans){
      ans = d[n][i];
      num = i;
    }
  }
  for(int i = n; i > 0; i--){
    res[i] = num;
    if(i == 1){
      break;
    }
    if(a[i - 1] == '='){
      continue;
    }
    if(a[i - 1] == 'L'){
      for(int j = num + 1; j <= n; j++){
	if(d[i - 1][j] + num == d[i][num]){
	  num = j;
	  break;
	}
      }
      continue;
    }
    for(int j = 1; j < num; j++){
      if(d[i - 1][j] + num == d[i][num]){
	num = j;
	break;
      }
    }
  }
  for(int i = 1; i <= n; i++){
    if(i > 1){
      printf(" ");
    }
    printf("%d", res[i]);
  }
  return 0;
}