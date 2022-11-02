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

char s[100], w[100];
int a[3000];

int main(){
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
  scanf("%s\n", s);
  for(int i = 0; i < 10; i++){
    scanf("%s\n", w);
    int cur = 0;
    for(int j = 0; j < 10; j++){
      cur = cur * 2 + w[j] - '0';
    }
    a[cur] = i;
  }
  int cur = 0;
  int sz = 0;
  for(int i = 0; i < 80; i++){
    cur = cur * 2 + s[i] - '0';
    sz++;
    if(sz == 10){
      printf("%d", a[cur]);
      cur = 0;
      sz = 0;
    }
  }
  printf("\n");
  return 0;
}