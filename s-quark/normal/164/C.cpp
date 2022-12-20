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
const int MAXN = 1004;

map<int, int> tmap;
int s1[MAXN], t[MAXN], c[MAXN];
int s[MAXN*2];
int b[MAXN*6], r[MAXN*6], w[MAXN*6], next[MAXN*6];
queue<int> q;
bool inq[MAXN*2];
int d[MAXN*2], pre[MAXN*2], pree[MAXN*2];
int cnt;
int T;

void insert(int u, int v, int f, int c){
  b[cnt] = v;
  r[cnt] = f;
  w[cnt] = c;
  next[cnt] = s[u];
  s[u] = cnt++;
  b[cnt] = u;
  r[cnt] = 0;
  w[cnt] = -c;
  next[cnt] = s[v];
  s[v] = cnt++;
}

int main()
{
  #ifdef __FIO
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  #endif
  int i, j;
  int n, k;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d%d%d", &s1[i], &t[i], &c[i]);
    t[i] += s1[i];
    tmap[s1[i]];
    tmap[t[i]];
  }
  i = 0;
  for(map<int, int>::iterator it = tmap.begin(); it != tmap.end(); it++, i++)
    (*it).se = i;
  T = i-1;
  memset(s, -1, sizeof s);
  for(i = 0; i < n; i++)
    insert(tmap[s1[i]], tmap[t[i]], 1, c[i]);
  for(i = 0; i < T; i++)
    insert(i, i+1, k, 0);
  while(k--){
    memset(d, -1, sizeof d);
    d[0] = 0;
    q.push(0);
    while(!q.empty()){
      i = q.front();
      inq[i] = 0;
      q.pop();
      for(j = s[i]; j != -1; j = next[j]){
        if(r[j] && d[b[j]] < d[i]+w[j]){
          d[b[j]] = d[i]+w[j];
          pre[b[j]] = i;
          pree[b[j]] = j;
          if(!inq[b[j]]){
            q.push(b[j]);
            inq[b[j]] = 1;
          }
        }
      }
    }
    i = T;
    while(i){
      r[pree[i]]--;
      r[pree[i]^1]++;
      i = pre[i];
    }
  }
  for(i = 0; i < n; i++)
    printf("%d ", r[i*2+1]);
  return 0;
}