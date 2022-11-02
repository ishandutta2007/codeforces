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

bool used[2000];
int a[2000], b[2000];

int main(){
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
  int n, k;
  scanf("%d %d", &n, &k);
  for(int i = 1; i <= n; i++){
    scanf("%d", &b[i]);
  }
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= n; j++){
      if(!used[j] && b[j] == 0){
	a[i] = j;
	used[j] = true;
	for(int z = 1; z <= n; z++){
	  if(j >= z + k){
	    b[z]--;
	  }
	}
	break;
      }
    }
  }
  for(int i = 1; i <= n; i++){
    if(i > 1){
      printf(" ");
    }
    printf("%d", a[i]);
  }
  printf("\n");
  return 0;
}