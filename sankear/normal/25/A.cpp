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

int cnt[2], prev[2];

int main(){
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; i++){
    int a;
    scanf("%d", &a);
    cnt[a % 2]++;
    prev[a % 2] = i;
  }
  if(cnt[0] == 1){
    printf("%d\n", prev[0] + 1);
    return 0;
  }
  printf("%d\n", prev[1] + 1);
  return 0;
}