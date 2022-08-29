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
  vector<int> t(n);
  for (int i = 0; i < n; i++){
    cin >> t[i];
  }
  sort(t.begin(), t.end());
  if (t[n - 1] * 2 + 1 > m){
    cout << -1 << endl;
  } else {
    vector<int> L, R;
    for (int i = 0; i < n; i++){
      if (t[i] * 3 > m){
        L.push_back(t[i]);
      } else {
        R.push_back(t[i]);
      }
    }
    int cnt1 = L.size();
    int cnt2 = R.size();
    dinic<int> G(cnt1 + cnt2 + 2);
    for (int j = 0; j < cnt1; j++){
      G.add_edge(cnt1 + cnt2, j, 1);
    }
    for (int j = 0; j < cnt2; j++){
      G.add_edge(cnt1 + j, cnt1 + cnt2 + 1, 1);
    }
    for (int j = 0; j < cnt1; j++){
      for (int k = 0; k < cnt2; k++){
        if (L[j] * 2 + R[k] <= m && L[j] % R[k] == 0){
          G.add_edge(j, cnt1 + k, 1);
        }
      }
    }
    int f = G.max_flow(cnt1 + cnt2, cnt1 + cnt2 + 1);
    if (f < cnt1){
      cout << -1 << endl;
    } else {
      vector<int> match(cnt1, 0);
      vector<bool> used(cnt2, false);
      for (int j = 0; j < cnt1; j++){
        for (dinic<int>::edge e : G.G[j]){
          if (e.to >= cnt1 && e.to != cnt1 + cnt2 && e.cap == 0){
            match[j] = e.to - cnt1;
            used[e.to - cnt1] = true;
          }
        }
      }
      int k = 0;
      vector<int> a, b;
      for (int j = 0; j < cnt1; j++){
        a.push_back(L[j] * 2 + R[match[j]]);
        b.push_back(L[j] + R[match[j]]);
        k++;
      }
      for (int j = 0; j < cnt2; j++){
        if (!used[j]){
          a.push_back(R[j] * 3);
          b.push_back(R[j] * 2);
          k++;
        }
      }
      cout << k << endl;
      for (int j = 0; j < k; j++){
        cout << a[j] << ' ' << b[j] << endl;
      }
    }
  }
}