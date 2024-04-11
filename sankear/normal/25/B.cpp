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

typedef unsigned long long ll;
typedef long double ld;

char a[1000];

int main(){
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
  int n;
  scanf("%d\n", &n);
  for(int i = 0; i < n; i++){
    scanf("%c", &a[i]);
  }
  for(int i = 0; i < n; i += 2){
    if(i > 0 && i < n - 1){
      printf("-");
    }
    printf("%c", a[i]);
    if(i + 1 < n){
      printf("%c", a[i + 1]);
    }
  }
  printf("\n");
  return 0;
}