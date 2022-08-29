#include <bits/stdc++.h>
using namespace std;
struct heavy_light_decomposition{
  vector<int> p, d, sz, in, next;
  heavy_light_decomposition(vector<int> &p, vector<vector<int>> &c, vector<int> &d): p(p), d(d){
    int N = p.size();
    sz = vector<int>(N, 0);
    dfs1(c);
    in = vector<int>(N, 0);
    next = vector<int>(N, 0);
    int t = 0;
    dfs2(c, t);
  }
  void dfs1(vector<vector<int>> &c, int v = 0){
    sz[v] = 1;
    for (int &w : c[v]){
      dfs1(c, w);
      sz[v] += sz[w];
      if (sz[w] > sz[c[v][0]]){
        swap(w, c[v][0]);
      }
    }
  }
  void dfs2(vector<vector<int>> &c, int &t, int v = 0){
    in[v] = t;
    t++;
    for (int w : c[v]){
      if (w == c[v][0]){
        next[w] = next[v];
      } else {
        next[w] = w;
      }
      dfs2(c, t, w);
    }
  }
  int lca(int u, int v){
    while (true){
      if (in[u] > in[v]){
        swap(u, v);
      }
      if (next[u] == next[v]){
        return u;
      }
      v = p[next[v]];
    }
  }
  int dist(int u, int v){
    return d[u] + d[v] - 2 * d[lca(u, v)];
  }
};
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N;
  cin >> N;
  vector<vector<int>> E(N);
  for (int i = 0; i < N - 1; i++){
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    E[u].push_back(v);
    E[v].push_back(u);
  }
  vector<int> p(N, -1);
  vector<vector<int>> c(N);
  vector<int> d(N, 0);
  queue<int> q;
  q.push(0);
  while (!q.empty()){
    int v = q.front();
    q.pop();
    for (int w : E[v]){
      if (w != p[v]){
        p[w] = v;
        c[v].push_back(w);
        d[w] = d[v] + 1;
        q.push(w);
      }
    }
  }
  heavy_light_decomposition T(p, c, d);
  int Q;
  cin >> Q;
  for (int i = 0; i < Q; i++){
    int K;
    cin >> K;
    vector<int> A(K);
    for (int j = 0; j < K; j++){
      cin >> A[j];
      A[j]--;
    }
    int mx1 = 0;
    int s = 0;
    for (int j = 0; j < K; j++){
      int d1 = T.dist(A[j], A[0]);
      if (d1 > mx1){
        mx1 = d1;
        s = j;
      }
    }
    int mx2 = 0;
    int t = s;
    for (int j = 0; j < K; j++){
      int d2 = T.dist(A[j], A[s]);
      if (d2 > mx2){
        mx2 = d2;
        t = j;
      }
    }
    bool ok = true;
    for (int j = 0; j < K; j++){
      if (T.dist(A[j], A[s]) + T.dist(A[j], A[t]) != mx2){
        ok = false;
      }
    }
    if (ok){
      cout << "YES" << "\n";
    } else {
      cout << "NO" << "\n";
    }
  }
}