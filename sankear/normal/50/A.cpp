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

int sz[2];
int dx[5] = {-1, 0, 1, 0};
int dy[5] = {0, 1, 0, -1};
int col[20][20], num[20][20];
bool used[400];
int res[400];
bool r[400][400];

bool dfs(int a){
  if(used[a]){
    return false;
  }
  used[a] = true;
  for(int i = 0; i < sz[0]; i++){
    if(r[i][a] && (res[i] == -1 || dfs(res[i]))){
      res[i] = a;
      return true;
    }
  }
  return false;
}

int main(){
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
  int n, m;
  scanf("%d %d", &n, &m);
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      col[i][j] = (i + j) % 2;
      num[i][j] = sz[col[i][j]]++;
    }
  }
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      if(col[i][j] != 0){
	continue;
      }
      for(int z = 0; z < 4; z++){
	int x = i + dx[z];
	int y = j + dy[z];
	if(x >= 0 && x < n && y >= 0 && y < m){
	  r[num[i][j]][num[x][y]] = true;
	}
      }
    }
  }
  int ans = 0;
  for(int i = 0; i < sz[0]; i++){
    res[i] = -1;
  }
  for(int i = 0; i < sz[1]; i++){
    for(int j = 0; j < sz[1]; j++){
      used[j] = false;
    }
    if(dfs(i)){
      ans++;
    }
  }
  printf("%d\n", ans);
  return 0;
}