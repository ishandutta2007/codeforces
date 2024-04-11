#include <bits/stdc++.h>
using namespace std;
const int MAX = 200001;
const int MOD = 998244353;
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
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++){
    cin >> A[i];
  }
  vector<vector<int>> E(N);
  for (int i = 0; i < N - 1; i++){
    int U, V;
    cin >> U >> V;
    U--;
    V--;
    E[U].push_back(V);
    E[V].push_back(U);
  }
  vector<vector<int>> f(MAX);
  for (int i = 2; i < MAX; i++){
    if (f[i].empty()){
      for (int j = i; j < MAX; j += i){
        f[j].push_back(i);
      }
    }
  }
  vector<vector<int>> S(MAX);
  for (int i = 0; i < N; i++){
    for (int j : f[A[i]]){
      S[j].push_back(i);
    }
  }
  vector<int> p(N, -1);
  vector<vector<int>> c(N);
  vector<int> d(N, -1);
  queue<int> Q;
  Q.push(0);
  while (!Q.empty()){
    int v = Q.front();
    Q.pop();
    for (int w : E[v]){
      if (w != p[v]){
        p[w] = v;
        c[v].push_back(w);
        d[w] = d[v] + 1;
        Q.push(w);
      }
    }
  }
  heavy_light_decomposition HLD(p, c);
  long long ans = 0;
  for (int i = 2; i < MAX; i++){
    if (S[i].size() >= 3){
      int cnt = S[i].size();
      vector<tuple<int, int, int>> edge;
      vector<pair<int, int>> V;
      for (int j = 0; j < cnt; j++){
        V.push_back(make_pair(HLD.in[S[i][j]], S[i][j]));
      }
      sort(V.begin(), V.end());
      stack<int> st;
      st.push(V[0].second);
      for (int j = 1; j < cnt; j++){
        int v = HLD.lca(V[j - 1].second, V[j].second);
        while (!st.empty()){
          int w = st.top();
          if (d[v] < d[w]){
            st.pop();
            int pr = v;
            if (!st.empty()){
              if (d[pr] < d[st.top()]){
                pr = st.top();
              }
            }
            if (pr != w){
              long long D = d[w] - d[pr];
              edge.push_back(make_tuple(pr, w, D));
            }
          } else {
            break;
          }
        }
        if (st.empty()){
          st.push(v);
        } else if (st.top() != v){
          st.push(v);
        }
        if (st.top() != V[j].second){
          st.push(V[j].second);
        }
      }
      while (st.size() >= 2){
        int v = st.top();
        st.pop();
        int w = st.top();
        long long D = d[v] - d[w];
        edge.push_back(make_tuple(v, w, D));
      }
      int M = edge.size() + 1;
      vector<int> id;
      for (int j = 0; j < M - 1; j++){
        id.push_back(get<0>(edge[j]));
        id.push_back(get<1>(edge[j]));
      }
      sort(id.begin(), id.end());
      id.erase(unique(id.begin(), id.end()), id.end());
      vector<vector<pair<int, int>>> E2(M);
      for (int j = 0; j < M - 1; j++){
        int u = lower_bound(id.begin(), id.end(), get<0>(edge[j])) - id.begin();
        int v = lower_bound(id.begin(), id.end(), get<1>(edge[j])) - id.begin();
        int w = get<2>(edge[j]);
        E2[u].push_back(make_pair(w, v));
        E2[v].push_back(make_pair(w, u));
      }
      vector<int> p2(M);
      vector<int> a2(M);
      vector<vector<int>> c2(M);
      vector<int> bfs;
      queue<int> Q;
      Q.push(0);
      while (!Q.empty()){
        int v = Q.front();
        Q.pop();
        bfs.push_back(v);
        for (auto e : E2[v]){
          int w = e.second;
          if (w != p2[v]){
            p2[w] = v;
            a2[w] = e.first;
            c2[v].push_back(w);
            Q.push(w);
          }
        }
      }
      reverse(bfs.begin(), bfs.end());
      vector<int> dp(M, 0);
      for (int v : bfs){
        for (int w : c2[v]){
          dp[v] += dp[w];
        }
        if (A[id[v]] % i == 0){
          dp[v]++;
        }
      }
      for (int v = 1; v < M; v++){
        long long ca = 0;
        ca += (long long) dp[v] * (cnt - dp[v])  * (cnt - dp[v] - 1) / 2;
        ca += (long long) dp[v] * (dp[v] - 1) / 2 * (cnt - dp[v]);
        ca %= MOD;
        ans += ca * a2[v];
        ans %= MOD;
      }
    }
  }
  cout << ans << endl;
}