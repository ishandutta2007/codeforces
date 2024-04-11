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
const int MAXN = 1000004;

int next[MAXN][26];
int pre[MAXN];
int l[MAXN];
int size[MAXN];
int q[MAXN];
int a[MAXN];
int pos[MAXN];
bool in[MAXN];
int cnt;
char s[MAXN];

inline int lowbit(int i){
  return i&(-i);
}

void insert(int i, int x){
  while(i < cnt){
    a[i] += x;
    i += lowbit(i);
  }
}

void insert(int i){
  if(in[i])
    return;
  in[i] = 1;
  insert(l[pos[i]], 1);
  insert(l[pos[i]]+size[pos[i]], -1);
}

void erase(int i){
  if(!in[i])
    return;
  in[i] = 0;
  insert(l[pos[i]], -1);
  insert(l[pos[i]]+size[pos[i]], 1);
}

ll query(int i){
  ll ret = 0;
  while(i){
    ret += a[i];
    i -= lowbit(i);
  }
  return ret;
}

int main()
{
  #ifdef __FIO
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  #endif
  int k;
  int i, j;
  int m, n;
  int h, t;
  scanf("%d%d", &m, &k);
  cnt = 1;
  memset(next, -1, sizeof next);
  for(i = 0; i < k; i++){
    scanf("%s", s);
    n = strlen(s);
    int p = 0;
    for(j = 0; j < n; j++){
      int x = s[j]-'a';
      if(next[p][x] == -1)
        next[p][x] = cnt++;
      p = next[p][x];
    }
    pos[i] = p;
  }
  h = t = 0;
  for(i = 0; i < 26; i++){
    if(next[0][i] != -1){
      pre[next[0][i]] = 0;
      q[t++] = next[0][i];
    }
    else
      next[0][i] = 0;
  }
  while(h < t){
    i = q[h++];
    for(j = 0; j < 26; j++){
      if(next[i][j] != -1){
        pre[next[i][j]] = next[pre[i]][j];
        q[t++] = next[i][j];
      }
      else{
        next[i][j] = next[pre[i]][j];
      }
    }
  }
  for(i = t-1; i >= 0; i--){
    size[q[i]]++;
    size[pre[q[i]]] += size[q[i]];
  }
  l[0] = 0;
  a[0] = 1;
  for(i = 0; i < t; i++){
    j = q[i];
    l[j] = l[pre[j]]+a[pre[j]];
    a[pre[j]] += size[j];
    a[j] = 1;
  }
  memset(a, 0, sizeof a);
  for(i = 0; i < k; i++){
    insert(i);
  }
  for(i = 0; i < m; i++){
    scanf("%s", s);
    if(s[0] == '+'){
      sscanf(s+1, "%d", &j);
      j--;
      insert(j);
    }
    else if(s[0] == '-'){
      sscanf(s+1, "%d", &j);
      j--;
      erase(j);
    }
    else{
      ll ans = 0;
      char *s1 = s+1;
      int p = 0;
      while(*s1){
        p = next[p][*s1-'a'];
        ans += query(l[p]);
        s1++;
      }
      cout<<ans<<endl;
    }
  }
  return 0;
}