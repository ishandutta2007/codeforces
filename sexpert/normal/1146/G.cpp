#include <bits/stdc++.h>
using namespace std;

struct edge {
  int to, rev, f, cap;
};

const int MAX = 1e5;
const int INF = 1e9;
vector<edge> adj[MAX];

void add_edge(int u, int v, int cap, int rcap = 0) {
  // cout << "connected " << u << " to " << v << " with capacity " << cap << '\n';
  edge a = {v, (int)adj[v].size(), 0, cap};
  edge b = {u, (int)adj[u].size(), 0, rcap};
  adj[u].push_back(a);
  adj[v].push_back(b);
}

int ptr[MAX], dis[MAX], src, dst;

bool bfs() {
  fill(dis, dis + MAX, -1);
  queue<int> q({src});
  dis[src] = 0;
  while(!q.empty()) {
    int u = q.front(); q.pop();
    for(edge e : adj[u]) {
      int v = e.to;
      if(dis[v] == -1 && e.f < e.cap) {
	dis[v] = dis[u] + 1;
	q.push(v);
      }
    }
  }
  return dis[dst] != -1;
}

int dfs(int s, int f) {
  if(!f || s == dst)
    return f;
  for(int &i = ptr[s]; i < adj[s].size(); i++) {
    edge &e = adj[s][i];
    int v = e.to;
    if(dis[v] != dis[s] + 1)
      continue;
    if(int df = dfs(v, min(f, e.cap - e.f))) {
      e.f += df;
      adj[v][e.rev].f -= df;
      return df;
    }
  }
  return 0;
}

int flow() {
  int tot = 0;
  while(bfs()) {
    fill(ptr, ptr + MAX, 0);
    while(int df = dfs(src, INF))
      tot += df;
  }
  return tot;
}

int n, m, h;

int main() {
  cin >> n >> h >> m;
  src = n*h + m + 1;
  dst = n*h + m + 2;
  for(int i = 0; i < m; i++) {
    int l, r, x, c;
    cin >> l >> r >> x >> c;
    l--;
    r--;
    for(int city = l; city <= r; city++) {
      for(int ht = x; ht < h; ht++)
	add_edge(i, m + city*h + ht, INF);
    }
    add_edge(src, i, c);
  }
  for(int city = 0; city < n; city++) {
    for(int ht = 0; ht < h; ht++) {
      add_edge(m + city*h + ht, dst, 2*ht + 1);
    }
  }
  cout << n*h*h - flow() << '\n';
}