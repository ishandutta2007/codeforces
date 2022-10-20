#include <iostream>
#include <cstring>
#include <algorithm>
#include <deque>
using namespace std;

const int inf = 1e9;

struct MinCostMaxFlow{
  static const int Node = 105, Edge = 2 * (105 * 4);
  int to[Edge], nt[Edge], hd[Node], f[Edge], w[Edge], h[Node], cur[Node], fromE[Node], ec = 0;
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
          fromE[to[i]] = i;
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
} G;

const int N = 105;

int in[N];

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int n, m;
  cin >> n >> m;
  int adj_cap = 0;
  G.S = n + 1; G.T = n + 2;
  for (int i = 1; i <= m; ++i) {
    int u, v, c, f;
    cin >> u >> v >> c >> f;
    if (f <= c) {
      G.link(u, v, c - f, 1);
      G.link(u, v, inf, 2);
      G.link(v, u, f, 1);
    }
    else {
      G.link(u, v, inf, 2);
      G.link(v, u, f - c, 0);
      G.link(v, u, c, 1);
      adj_cap += f - c;
    }
    in[u] -= f; in[v] += f;
  }
  G.link(n, 1, inf, 0);
  for (int i = 1; i <= n; ++i)
    if (in[i] > 0) G.link(G.S, i, in[i], 0);
    else G.link(i, G.T, -in[i], 0);
  printf("%d\n", G.mcmf().second + adj_cap);
  return 0;
}