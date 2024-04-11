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

char s[200], t[200];

inline int f(char ch){
  if(ch >= 'a' && ch <= 'z'){
    return ch - 'a';
  }
  return ch - 'A';
}

int main(){
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
  scanf("%s\n%s", s, t);
  int n = strlen(s);
  for(int i = 0; i < n; i++){
    int a = f(s[i]);
    int b = f(t[i]);
    if(a != b){
      if(a < b){
	printf("-1\n");
	return 0;
      }
      printf("1\n");
      return 0;
    }
  }
  printf("0\n");
  return 0;
}