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

int main(){
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
  int n;
  ll x, y;
  scanf("%d %I64d %I64d", &n, &x, &y);
  if(y >= n && (y - n + 1) * (y - n + 1) + n - 1 >= x){
    printf("%I64d\n", y - n + 1);
    for(int i = 0; i < n - 1; i++){
      printf("1\n");
    }
    return 0;
  }
  printf("-1\n");
  return 0;
}