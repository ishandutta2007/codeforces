#include <bits/stdc++.h>
using namespace std;
struct heavy_light_decomposition{
  vector<int> p, sz, in, next;
  heavy_light_decomposition(vector<int> &p, vector<vector<int>> &c): p(p){
    int N = p.size();
    sz = vector<int>(N, 1);
    dfs1(c);
    in = vector<int>(N);
    next = vector<int>(N, 0);
    int t = 0;
    dfs2(c, t);
  }
  void dfs1(vector<vector<int>> &c, int v = 0){
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
};
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<vector<pair<int, int>>> E(n);
  for (int i = 0; i < n - 1; i++){
    int u, v, x;
    cin >> u >> v >> x;
    u--;
    v--;
    x--;
    E[u].push_back(make_pair(x, v));
    E[v].push_back(make_pair(x, u));
  }
  vector<int> p(n, -1);
  vector<vector<int>> c(n);
  vector<int> d(n, 0);
  vector<vector<int>> id(n, vector<int>(1, 0));
  queue<int> Q;
  Q.push(0);
  vector<int> bfs;
  while (!Q.empty()){
    int v = Q.front();
    Q.pop();
    bfs.push_back(v);
    for (auto P : E[v]){
      int w = P.second;
      if (w != p[v]){
        p[w] = v;
        c[v].push_back(w);
        d[w] = d[v] + 1;
        id[P.first].push_back(w);
        Q.push(w);
      }
    }
  }
  reverse(bfs.begin(), bfs.end());
  vector<int> dp(n, 1);
  for (int v : bfs){
    for (int w : c[v]){
      dp[v] += dp[w];
    }
  }
  heavy_light_decomposition HLD(p, c);
  long long ans = 0;
  for (int i = 0; i < n; i++){
    int cnt = id[i].size();
    vector<pair<int, int>> V(cnt);
    for (int j = 0; j < cnt; j++){
      V[j] = make_pair(HLD.in[id[i][j]], id[i][j]);
    }
    sort(V.begin(), V.end());
    vector<vector<int>> c2(cnt);
    stack<pair<int, int>> st;
    st.push(make_pair(0, 0));
    for (int j = 1; j < cnt; j++){
      int v = V[j].second;
      int u = HLD.lca(get<1>(V[j - 1]), v);
      while (d[st.top().first] > d[u]){
        st.pop();
      }
      c2[st.top().second].push_back(j);
      st.push(make_pair(v, j));
    }
    vector<int> dp2(cnt);
    for (int j = 0; j < cnt; j++){
      dp2[j] = dp[V[j].second];
    }
    for (int j = 0; j < cnt; j++){
      for (int k : c2[j]){
        dp2[j] -= dp2[k];
      }
    }
    for (int j = 0; j < cnt; j++){
      for (int k : c2[j]){
        ans += (long long) dp2[j] * dp2[k];
      }
    }
  }
  cout << ans << endl;
}