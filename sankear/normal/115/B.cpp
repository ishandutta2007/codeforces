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

char a[200][200];
int l[200], r[200];
int d[200][200][2];
int queue[80000];

int main(){
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
  int n, m;
  scanf("%d %d\n", &n, &m);
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      scanf("%c", &a[i][j]);
    }
    scanf("\n");
  }
  for(int i = 0; i < n; i++){
    l[i] = inf;
    r[i] = -inf;
    for(int j = 0; j < m; j++){
      if(a[i][j] == 'W'){
	l[i] = min(l[i], j);
	r[i] = max(r[i], j);
      }
    }
  }
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      d[i][j][0] = inf;
      d[i][j][1] = inf;
    }
  }
  d[0][0][0] = 0;
  int ll = 0;
  int rr = 3;
  queue[0] = 0;
  queue[1] = 0;
  queue[2] = 0;
  while(ll < rr){
    int aa = queue[ll++];
    int bb = queue[ll++];
    int cc = queue[ll++];
    if(cc == 0){
      if(bb + 1 < m && d[aa][bb + 1][0] > d[aa][bb][0] + 1){
	d[aa][bb + 1][0] = d[aa][bb][0] + 1;
	queue[rr++] = aa;
	queue[rr++] = bb + 1;
	queue[rr++] = 0;
      }
      if(aa + 1 < n && bb >= r[aa] && bb >= r[aa + 1]){
	if(d[aa + 1][bb][1] > d[aa][bb][0] + 1){
	  d[aa + 1][bb][1] = d[aa][bb][0] + 1;
	  queue[rr++] = aa + 1;
	  queue[rr++] = bb;
	  queue[rr++] = 1;
	}
      }
      continue;
    }
    if(bb - 1 >= 0 && d[aa][bb - 1][1] > d[aa][bb][1] + 1){
      d[aa][bb - 1][1] = d[aa][bb][1] + 1;
      queue[rr++] = aa;
      queue[rr++] = bb - 1;
      queue[rr++] = 1;
    }
    if(aa + 1 < n && bb <= l[aa] && bb <= l[aa + 1]){
      if(d[aa + 1][bb][0] > d[aa][bb][1] + 1){
	d[aa + 1][bb][0] = d[aa][bb][1] + 1;
	queue[rr++] = aa + 1;
	queue[rr++] = bb;
	queue[rr++] = 0;
      }
    }
  }
  int ans = inf;
  bool fl = false;
  for(int i = n - 1; i >= 0; i--){
    if(l[i] != inf){
      for(int j = 0; j < m; j++){
	if(j <= l[i]){
	  ans = min(ans, d[i][j][1]);
	}
	if(j >= r[i]){
	  ans = min(ans, d[i][j][0]);
	}
      }
      fl = true;
      break;
    }
  }
  if(!fl){
    ans = 0;
  }
  printf("%d\n", ans);
  return 0;
}