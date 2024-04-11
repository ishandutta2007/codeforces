#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define FOR(i, s, t) for(i = (s); i < (t); i++)
#define RFOR(i, s, t) for(i = (s)-1; i >= (t); i--)

char s[20][20];
char word[20];
int a[500004];
int next[500004][20];
int t[1<<15][15*15/2];
int size[1<<15];

int main()
{
  #ifdef __FIO
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  #endif
  int n, m, l, m1;
  int i, j, k, x;
  int ans = 0, ans1;
  scanf("%d", &n);
  ans1 = n*(n-1)/2+1;
  for(i = 0; i < n; i++)
    scanf("%s", s[i]);
  size[0] = 0;
  for(i = 1; i < 1<<n; i++)
    size[i] = size[i^(i&-i)]+1;
  scanf("%d", &m);
  m1 = m;
  while(m--){
    scanf("%d", &l);
    for(i = 0; i < l; i++){
      scanf("%s", word);
      for(j = 0; j < n; j++)
        if(strcmp(word, s[j]) == 0)
          break;
      if(j == n)
        j = -1;
      a[i] = j;
    }
    for(j = 0; j < n; j++)
      next[l][j] = l;
    for(i = l-1; i >= 0; i--){
      for(j = 0; j < n; j++)
        next[i][j] = next[i+1][j];
      if(a[i] != -1)
        next[i][a[i]] = i;
    }
    for(i = 0; i < 1<<n; i++){
      for(j = 0; j <= n*(n-1)/2; j++){
        t[i][j] = l;
      }
    }
    t[0][0] = 0;
    for(i = 1; i < 1<<n; i++){
      for(j = 0; j <= size[i]*(size[i]-1)/2; j++){
        x = 0;
        for(k = n-1; k >= 0 && x <= j; k--){
          if(i&1<<k){
            t[i][j] = min(t[i][j], next[t[i^1<<k][j-x]][k]);
            x++;
          }
        }
      }
    }
    for(j = 0; j <= n*(n-1)/2; j++)
      if(t[(1<<n)-1][j] < l)
        break;
    if(j < ans1){
      ans = m1-m;
      ans1 = min(ans1, j);
    }
  }
  if(ans1 <= n*(n-1)/2){
    printf("%d\n", ans);
    printf("[:");
    while(ans1 <= n*(n-1)/2){
      printf("|");
      ans1++;
    }
    printf(":]\n");
  }
  else{
    printf("Brand new problem!\n");
  }
  return 0;
}