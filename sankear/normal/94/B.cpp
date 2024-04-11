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

bool r[10][10];

inline void ok(){
  printf("WIN\n");
  exit(0);
}

int main(){
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; i++){
    int a, b;
    scanf("%d %d", &a, &b);
    r[a][b] = r[b][a] = true;
  }
  for(int i = 1; i <= 5; i++){
    for(int j = 1; j <= 5; j++){
      if(i == j){
	continue;
      }
      for(int z = 1; z <= 5; z++){
	if(i == z || j == z){
	  continue;
	}
	if(r[i][j] && r[j][z] && r[i][z]){
	  ok();
	}
	if(!r[i][j] && !r[j][z] && !r[i][z]){
	  ok();
	}
      }
    }
  }
  printf("FAIL\n");
  return 0;
}