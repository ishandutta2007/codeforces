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
struct strongly_connected_components{
  vector<int> scc;
  int cnt = 0;
  void dfs1(vector<vector<int>> &E, vector<int> &t, vector<bool> &used, int v){
    for (int w : E[v]){
      if (!used[w]){
        used[w] = true;
        dfs1(E, t, used, w);
      }
    }
    t.push_back(v);
  }
  void dfs2(vector<vector<int>> &E2, vector<bool> &used2, int v){
    scc[v] = cnt;
    for (int w : E2[v]){
      if (!used2[w]){
        used2[w] = true;
        dfs2(E2, used2, w);
      }
    }
  }
  strongly_connected_components(vector<vector<int>> &E){
    int N = E.size();
    vector<vector<int>> E2(N);
    for (int i = 0; i < N; i++){
      for (int j : E[i]){
        E2[j].push_back(i);
      }
    }
    vector<int> t;
    vector<bool> used(N, false);
    for (int i = 0; i < N; i++){
      if (!used[i]){
        used[i] = true;
        dfs1(E, t, used, i);
      }
    }
    reverse(t.begin(), t.end());
    vector<bool> used2(N, false);
    scc = vector<int>(N);
    for (int i = 0; i < N; i++){
      if (!used2[t[i]]){
        used2[t[i]] = true;
        dfs2(E2, used2, t[i]);
        cnt++;
      }
    }
  }
  int operator [](int k){
    return scc[k];
  }
};
int main(){
  int n1, n2, m, q;
  cin >> n1 >> n2 >> m >> q;
  vector<int> x(m), y(m);
  for (int i = 0; i < m; i++){
    cin >> x[i] >> y[i];
    x[i]--;
    y[i]--;
  }
  dinic<int> G(n1 + n2 + 2);
  for (int i = 0; i < n1; i++){
    G.add_edge(n1 + n2, i, 1);
  }
  for (int i = 0; i < n2; i++){
    G.add_edge(n1 + i, n1 + n2 + 1, 1);
  }
  for (int i = 0; i < m; i++){
    G.add_edge(x[i], n1 + y[i], 1);
  }
  int F = G.max_flow(n1 + n2, n1 + n2 + 1);
  vector<int> match(n1, -1);
  for (int i = 0; i < n1; i++){
    int cnt = G.G[i].size();
    for (int j = 0; j < cnt; j++){
      if (G.G[i][j].cap == 0){
        int w = G.G[i][j].to;
        if (w != n1 + n2){
          match[i] = w - n1;
        }
      }
    }
  }
  vector<int> match_id(n1, -1);
  for (int i = 0; i < m; i++){
    if (match[x[i]] == y[i]){
      match_id[x[i]] = i;
    }
  }
  vector<bool> used(m, false);
  for (int i = 0; i < n1; i++){
    if (match_id[i] != -1){
      used[match_id[i]] = true;
    }
  }
  vector<vector<int>> E(n1 + n2);
  for (int i = 0; i < m; i++){
    if (used[i]){
      E[x[i]].push_back(n1 + y[i]);
      E[n1 + y[i]].push_back(x[i]);
    } else{
      E[x[i]].push_back(n1 + y[i]);
    }
  }
  strongly_connected_components G2(E);
  vector<bool> used2(n1 + n2, false);
  queue<int> Q;
  for (int i = 0; i < n1; i++){
    if (match[i] == -1){
      used2[i] = true;
      Q.push(i);
    }
  }
  while (!Q.empty()){
    int v = Q.front();
    Q.pop();
    for (int w : E[v]){
      if (!used2[w]){
        used2[w] = true;
        Q.push(w);
      }
    }
  }
  int cnt = G2.cnt;
  vector<vector<int>> left(cnt), right(cnt), edge(cnt);
  for (int i = 0; i < m; i++){
    if (used[i]){
      int id = G2[x[i]];
      left[id].push_back(x[i]);
      right[id].push_back(y[i]);
      edge[id].push_back(i);
    }
  }
  long long sum = 0;
  for (int i = 0; i < m; i++){
    if (used[i]){
      sum += i + 1;
    }
  }
  int p = 0;
  for (int i = 0; i < q; i++){
    int t;
    cin >> t;
    if (t == 1){
      while (left[p].empty() || right[p].empty()){
        p++;
      }
      sum -= edge[p].back() + 1;
      if (used2[n1 + right[p][0]]){
        cout << 1 << endl;
        cout << -(right[p].back() + 1) << endl;
        cout << sum << endl;
      } else {
        cout << 1 << endl;
        cout << left[p].back() + 1 << endl;
        cout << sum << endl;
      }
      left[p].pop_back();
      right[p].pop_back();
      edge[p].pop_back();
    }
    if (t == 2){
      vector<int> ans;
      for (int j = 0; j < cnt; j++){
        for (int k : edge[j]){
          ans.push_back(k);
        }
      }
      int M = ans.size();
      cout << M << endl;
      for (int j = 0; j < M; j++){
        cout << ans[j] + 1;
        if (j < M - 1){
          cout << ' ';
        }
      }
      cout << endl;
    }
  }
}