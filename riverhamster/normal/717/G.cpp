#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <vector>
#include <deque>
using namespace std;
using ll = long long;
#define File(s) freopen(s".in", "r", stdin), freopen(s".out", "w", stdout)

const int N = 504, M = 104;
const int Node = N * 2, Edge = (N * M + N * 4) * 2;
char s[N], b[N];

bool Equal(char *s, char *t, int n) {
  for (int i = 0; i < n; ++i, ++s, ++t)
    if (*s != *t) return false;
  return true;
}

const int INF = 0x3f3f3f3f;
struct MinCostMaxFlow{
  int to[Edge], nt[Edge], hd[Node], f[Edge], w[Edge], h[Node], cur[Node], ec = 0;
  int S, T;
  void clear(){memset(hd, -1, sizeof(hd)); ec = 0;}
  MinCostMaxFlow(){clear();}
  void link(int x, int y, int flow, int cost){
    to[ec] = y; nt[ec] = hd[x]; hd[x] = ec; f[ec] = flow; w[ec] = cost; ++ec;
    to[ec] = x; nt[ec] = hd[y]; hd[y] = ec; f[ec] = 0; w[ec] = -cost; ++ec;
  }

  bool spfa(){
    deque<int> q;
    memset(h, 0x3f, sizeof(h));
    h[S] = 0; q.push_back(S);
    while(!q.empty()){
      int x = q.front(); q.pop_front();
      for(int i=hd[x]; i!=-1; i=nt[i]){
        if(f[i] && h[to[i]] > h[x] + w[i]){
          h[to[i]] = h[x] + w[i];
          if(!q.empty() && h[to[i]] <= h[q.front()]) q.push_front(to[i]);
          else q.push_back(to[i]);
        }
      }
    }
    return h[T] != 0x3f3f3f3f;
  }
  bool vis[Node];
  int dfs(int x, int flow){
    if(x == T || !flow) return flow;
    int res = 0;
    vis[x] = true;
    for(int i=hd[x]; i!=-1; i=nt[i]){
      if(vis[to[i]] || h[to[i]] != h[x] + w[i] || !f[i]) continue;
      int aug = min(flow, f[i]);
      if((aug = min(aug, dfs(to[i], aug)))){
        f[i] -= aug; f[i^1] += aug;
        flow -= aug; res += aug;
      }
      if(!flow) break;
    }
    vis[x] = false;
    if(!res) h[x] = 0x3f3f3f3f;
    return res;
  }
  pair<int, int> mcmf(){
    int flow = 0, cost = 0;
    while(spfa()){
      int fl = dfs(S, 0x3f3f3f3f);
      flow += fl; cost += fl * h[T];
    }
    return make_pair(flow, cost);
  }
}G;

int main() {
  int n, m;
  scanf("%d", &n);
  scanf("%s", s + 1);
  G.S = n + 2, G.T = n + 3;
  scanf("%d", &m);
  int all = 0;
  for (int i = 1; i <= m; ++i) {
    int q;
    scanf("%s%d", b, &q);
    int l = strlen(b);
    for (int j = 1; j <= n - l + 1; ++j)
      if (Equal(s + j, b, l)) {
        all += q;
        G.link(j, j + l, 1, q);
        G.link(G.S, j, 1, 0);
        G.link(j + l, G.T, 1, 0);
      }
  }
  int x;
  scanf("%d", &x);
  for (int i = 1; i <= n; ++i)
    G.link(i, i + 1, x, 0);
  printf("%d\n", all - G.mcmf().second);
  return 0;
}