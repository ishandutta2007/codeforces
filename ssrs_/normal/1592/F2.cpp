#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000;
template <typename Cap>
struct dinic{
  struct edge{
    int to, rev;
    Cap cap;
    edge(int to, int rev, Cap cap): to(to), rev(rev), cap(cap){
    }
  };
  int N;
  vector<vector<edge>> G;
  dinic(){
  }
  dinic(int N): N(N), G(N){
  }
  void add_edge(int from, int to, Cap cap){
    G[from].push_back(edge(to, G[to].size(), cap));
    G[to].push_back(edge(from, G[from].size() - 1, 0));
  }
  Cap dfs(vector<int> &d, vector<int> &iter, int v, int t, Cap f){
    if (v == t){
      return f; 
    }
    while (iter[v] < G[v].size()){
      int w = G[v][iter[v]].to;
      if (G[v][iter[v]].cap > 0 && d[v] < d[w]){
        Cap f2 = dfs(d, iter, w, t, min(f, G[v][iter[v]].cap));
        if (f2 > 0){
          G[v][iter[v]].cap -= f2;
          G[w][G[v][iter[v]].rev].cap += f2;
          return f2;
        }
      }
      iter[v]++;
    }
    return 0;
  }
  Cap max_flow(int s, int t){
    Cap flow = 0;
    while (true){
      vector<int> d(N, -1);
      d[s] = 0;
      queue<int> Q;
      Q.push(s);
      while (!Q.empty()){
        if (d[t] != -1){
          break;
        }
        int v = Q.front();
        Q.pop();
        for (auto &e : G[v]){
          int w = e.to;
          if (e.cap > 0 && d[w] == -1){
            d[w] = d[v] + 1;
            Q.push(w);
          }
        }
      }
      if (d[t] == -1){
        break;
      }
      vector<int> iter(N, 0);
      while (true){
        Cap f = dfs(d, iter, s, t, INF);
        if (f == 0){
          break;
        }
        flow += f;
      }
    }
    return flow;
  }
};
int main(){
  int n, m;
  cin >> n >> m;
  vector<string> s(n);
  for (int i = 0; i < n; i++){
    cin >> s[i];
  }
  vector<vector<int>> a(n, vector<int>(m, 0));
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      int cnt = 0;
      if (s[i][j] == 'B'){
        cnt++;
      }
      if (i < n - 1){
        if (s[i + 1][j] == 'B'){
          cnt++;
        }
      }
      if (j < m - 1){
        if (s[i][j + 1] == 'B'){
          cnt++;
        }
      }
      if (i < n - 1 && j < m - 1){
        if (s[i + 1][j + 1] == 'B'){
          cnt++;
        }
      }
      a[i][j] = cnt % 2;
    }
  }
  int cnt = 0;
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      if (a[i][j] == 1){
        cnt++;
      }
    }
  }
  dinic<int> G(n + m);
  for (int i = 0; i < n - 1; i++){
    G.add_edge(n + m - 2, i, 1);
  }
  for (int i = 0; i < m - 1; i++){
    G.add_edge(n - 1 + i, n + m - 1, 1);
  }
  for (int i = 0; i < n - 1; i++){
    for (int j = 0; j < m - 1; j++){
      if (a[i][j] == 1 && a[i][m - 1] == 1 && a[n - 1][j] == 1){
        G.add_edge(i, n - 1 + j, 1);
      }
    }
  }
  int f = G.max_flow(n + m - 2, n + m - 1);
  int ans = cnt - f / 2 * 2;
  if (f % 2 == 1){
    if (a[n - 1][m - 1] == 1){
      ans -= 2;
    }
  }
  cout << ans << endl;
}