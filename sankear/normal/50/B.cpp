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

char s[200200];
int sz[40];

inline int f(char ch){
  if(ch >= '0' && ch <= '9'){
    return ch - '0';
  }
  return ch - 'a' + 10;
}

int main(){
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
  scanf("%s", s);
  int n = strlen(s);
  for(int i = 0; i < n; i++){
    sz[f(s[i])]++;
  }
  ll ans = 0;
  for(int i = 0; i < 36; i++){
    ans += (ll)sz[i] * sz[i];
  }
  printf("%I64d\n", ans);
  return 0;
}