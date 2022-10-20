#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <bitset>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <iostream>
#include <string>
#include <array>
#include <random>
#include <chrono>
#include <vector>
using namespace std;
#ifndef ONLINE_JUDGE
#define File(s) freopen(s".in", "r", stdin), freopen(s".out", "w", stdout)
#else
#define File(s)
#endif

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define mkp make_pair
#define pb push_back
#define SP putchar(' ')
#define EL putchar('\n')

mt19937 rnd(chrono :: steady_clock :: now().time_since_epoch().count());
mt19937_64 rnd64(chrono :: steady_clock :: now().time_since_epoch().count()) ;

template<class T> inline void gi(T &x){
  char ch; x = 0;int f = 1;
  while(isspace(ch = getchar()));
  if(ch == '-') ch = getchar(), f = -1;
  do x = x * 10 + ch - '0'; while(isdigit(ch = getchar()));
  x *= f;
}
template<class T> inline void wi(T x){
  static char stk[128]; int top = 0;
  if(x == 0) putchar('0');
  if(x < 0) putchar('-'), x = -x;
  while(x) stk[++top] = x % 10, x /= 10;
  while(top) putchar(stk[top--] + '0');
}
template<class T, class ...Args>
inline void gi(T &x, Args&... args) {gi(x); gi(args...);}
template<class T, class ...Args>
inline void wi(T x, Args... args) {wi(x); SP; wi(args...);}
template<class T> void upmax(T &x, T y) {x = x > y ? x : y;}
template<class T> void upmin(T &x, T y) {x = x < y ? x : y;}

const int N = 300005;

vector<int> G[N];
bool vis[N], inq[N];
int sum = 0;

void dfs(int x) {
  vis[x] = true; ++sum;
  for (int v : G[x]) if (!vis[v]) dfs(v);
}

int main(){
  File("d");
  int T;
  gi(T);
  while (T--) {
    int n, m;
    gi(n, m);
    for (int i = 1; i <= n; ++i) G[i].clear();
    for (int i = 1; i <= m; ++i) {
      int u, v;
      gi(u); gi(v);
      G[u].push_back(v); G[v].push_back(u);
    }
    fill(vis + 1, vis + 1 + n, false);
    sum = 0;
    dfs(1);
    if (sum != n) { puts("NO"); continue; }
    puts("YES");
    fill(vis + 1, vis + 1 + n, false);
    fill(inq + 1, inq + 1 + n, false);
    queue<int> q;
    vector<int> res;
    q.push(1);
    while (!q.empty()) {
      int x = q.front(); q.pop();
      if (!vis[x]) {
        res.push_back(x), vis[x] = true;
        for (int v : G[x]) {
          if (!vis[v]) q.push(v);
          vis[v] = true;
        }
      }
      else
        for (int v : G[x])
          if (!vis[v] && !inq[v]) q.push(v), inq[v] = true;
    }
    wi(res.size()), EL;
    for (int x : res) wi(x), SP;
    EL;
  }
  return 0;
}