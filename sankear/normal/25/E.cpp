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

const int inf = (int)1e9;

int ans;
char s[3][300300];
char res1[300300], res2[300300], sw[300300];
bool used[3];
int cur[3];
int p[300300];

inline void doit(char *s, char *t, char *res){
  int n = strlen(s);
  int m = strlen(t);
  int k = 0;
  for(int i = 0; i < m; i++){
    sw[++k] = t[i];
  }
  sw[++k] = '#';
  for(int i = 0; i < n; i++){
    sw[++k] = s[i];
  }
  p[1] = 0;
  for(int i = 2; i <= k; i++){
    int j = p[i - 1];
    while(j > 0 && sw[j + 1] != sw[i]){
      j = p[j];
    }
    if(sw[j + 1] == sw[i]){
      p[i] = j + 1;
    }
    else{
      p[i] = 0;
    }
  }
  k = 0;
  for(int i = 0; i < n; i++){
    res[k++] = s[i];
  }
  for(int i = p[n + m + 1]; i < m; i++){
    res[k++] = t[i];
  }
  res[k] = '\0';
}

inline bool check(char *s, char *t){
  int n = strlen(s);
  int m = strlen(t);
  int k = 0;
  for(int i = 0; i < n; i++){
    sw[++k] = s[i];
  }
  sw[++k] = '#';
  for(int i = 0; i < m; i++){
    sw[++k] = t[i];
  }
  p[1] = 0;
  for(int i = 2; i <= k; i++){
    int j = p[i - 1];
    while(j > 0 && sw[j + 1] != sw[i]){
      j = p[j];
    }
    if(sw[j + 1] == sw[i]){
      p[i] = j + 1;
    }
    else{
      p[i] = 0;
    }
  }
  for(int i = n + 2; i <= k; i++){
    if(p[i] == n){
      return true;
    }
  }
  return false;
}

void gen(int x){
  if(x >= 3){
    if(check(s[cur[1]], s[cur[0]])){
      if(check(s[cur[2]], s[cur[0]])){
	ans = min(ans, (int)strlen(s[cur[0]]));
      }
      else{
	doit(s[cur[0]], s[cur[2]], res1);
	ans = min(ans, (int)strlen(res1));
	doit(s[cur[2]], s[cur[0]], res1);
	ans = min(ans, (int)strlen(res1));
      }
    }
    doit(s[cur[0]], s[cur[1]], res1);
    doit(res1, s[cur[2]], res2);
    ans = min(ans, (int)strlen(res2));
    return;
  }
  for(int i = 0; i < 3; i++){
    if(!used[i]){
      cur[x] = i;
      used[i] = true;
      gen(x + 1);
      used[i] = false;
    }
  }
}

int main(){
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
  for(int i = 0; i < 3; i++){
    scanf("%s\n", s[i]);
  }
  ans = inf;
  gen(0);
  printf("%d\n", ans);
  return 0;
}