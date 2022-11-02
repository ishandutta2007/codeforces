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

int len[200000];
char cur[200000];
char* s[200000];

inline bool get(char* s){
  int len = 0;
  char ch;
  if(scanf("%c", &ch) != 1){
    return false;
  }
  while(!(ch >= 'a' && ch <= 'z')){
    if(scanf("%c", &ch) != 1){
      return false;
    }
  }
  while(ch >= 'a' && ch <= 'z'){
    s[len++] = ch;
    if(scanf("%c", &ch) != 1){
      break;
    }
  }
  s[len] = '\0';
  return true;
}

inline int f(char* s, int len){
  if(len >= 4 && s[len - 1] == 's' && s[len - 2] == 'o' && s[len - 3] == 'i' && s[len - 4] == 'l'){
    return 0;
  }
  if(len >= 5 && s[len - 1] == 'a' && s[len - 2] == 'l' && s[len - 3] == 'a' && s[len - 4] == 'i' && s[len - 5] == 'l'){
    return 0;
  }
  if(len >= 3 && s[len - 1] == 'r' && s[len - 2] == 't' && s[len - 3] == 'e'){
    return 1;
  }
  if(len >= 4 && s[len - 1] == 'a' && s[len - 2] == 'r' && s[len - 3] == 't' && s[len - 4] == 'e'){
    return 1;
  }
  if(len >= 6 && s[len - 1] == 's' && s[len - 2] == 'i' && s[len - 3] == 't' && s[len - 4] == 'i' && s[len - 5] == 'n' && s[len - 6] == 'i'){
    return 2;
  }
  if(len >= 6 && s[len - 1] == 's' && s[len - 2] == 'e' && s[len - 3] == 't' && s[len - 4] == 'i' && s[len - 5] == 'n' && s[len - 6] == 'i'){
    return 2;
  }
  return -1;
}

inline int g(char* s, int len){
  if(len >= 4 && s[len - 1] == 's' && s[len - 2] == 'o' && s[len - 3] == 'i' && s[len - 4] == 'l'){
    return 0;
  }
  if(len >= 5 && s[len - 1] == 'a' && s[len - 2] == 'l' && s[len - 3] == 'a' && s[len - 4] == 'i' && s[len - 5] == 'l'){
    return 1;
  }
  if(len >= 3 && s[len - 1] == 'r' && s[len - 2] == 't' && s[len - 3] == 'e'){
    return 0;
  }
  if(len >= 4 && s[len - 1] == 'a' && s[len - 2] == 'r' && s[len - 3] == 't' && s[len - 4] == 'e'){
    return 1;
  }
  if(len >= 6 && s[len - 1] == 's' && s[len - 2] == 'i' && s[len - 3] == 't' && s[len - 4] == 'i' && s[len - 5] == 'n' && s[len - 6] == 'i'){
    return 0;
  }
  if(len >= 6 && s[len - 1] == 's' && s[len - 2] == 'e' && s[len - 3] == 't' && s[len - 4] == 'i' && s[len - 5] == 'n' && s[len - 6] == 'i'){
    return 1;
  }
  return -1;
}

inline void fail(){
  printf("NO\n");
  exit(0);
}

inline void ok(){
  printf("YES\n");
  exit(0);
}

int main(){
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
  int n = 0;
  while(true){
    if(!get(cur)){
      break;
    }
    len[n] = strlen(cur);
    s[n] = (char*)malloc(sizeof(char) * len[n]);
    for(int i = 0; i < len[n]; i++){
      s[n][i] = cur[i];
    }
    n++;
  }
  if(n == 1){
    if(f(s[0], len[0]) != -1){
      ok();
    }
    fail();
  }
  for(int i = 0; i < n; i++){
    if(f(s[i], len[i]) == 1){
      for(int j = 0; j < i; j++){
	if(f(s[j], len[j]) != 0){
	  fail();
	}
      }
      for(int j = i + 1; j < n; j++){
	if(f(s[j], len[j]) != 2){
	  fail();
	}
      }
      int need = g(s[0], len[0]);
      for(int j = 1; j < n; j++){
	if(g(s[j], len[j]) != need){
	  fail();
	}
      }
      ok();
    }
  }
  fail();
  return 0;
}