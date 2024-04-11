#include <bits/stdc++.h>
using namespace std;
const int LOG = 18;
vector<int> bfs(vector<vector<int>> &E, int r){
  int N = E.size();
  vector<int> d(N, -1);
  d[r] = 0;
  queue<int> Q;
  Q.push(r);
  while (!Q.empty()){
    int v = Q.front();
    Q.pop();
    for (int w : E[v]){
      if (d[w] == -1){
        d[w] = d[v] + 1;
        Q.push(w);
      }
    }
  }
  return d;
}
pair<int, int> get_diameter(vector<vector<int>> &E){
  vector<int> d1 = bfs(E, 0);
  int r1 = max_element(d1.begin(), d1.end()) - d1.begin();
  vector<int> d2 = bfs(E, r1);
  int r2 = max_element(d2.begin(), d2.end()) - d2.begin();
  return make_pair(r1, r2);
}
struct lowest_common_ancestor{
  vector<int> d;
  vector<vector<int>> pp;
  lowest_common_ancestor(vector<int> &p, vector<vector<int>> &c){
    int N = p.size();
    d = vector<int>(N, 0);
    queue<int> Q;
    Q.push(0);
    while (!Q.empty()){
      int v = Q.front();
      Q.pop();
      for (int w : c[v]){
        d[w] = d[v] + 1;
        Q.push(w);
      }
    }
    pp = vector<vector<int>>(LOG, vector<int>(N, -1));
    for (int i = 0; i < N; i++){
      pp[0][i] = p[i];
    }
    for (int i = 0; i < LOG - 1; i++){
      for (int j = 0; j < N; j++){
        if (pp[i][j] != -1){
          pp[i + 1][j] = pp[i][pp[i][j]];
        }
      }
    }
  }
  int lca(int u, int v){
    if (d[u] > d[v]){
      swap(u, v);
    }
    for (int i = 0; i < LOG; i++){
      if (((d[v] - d[u]) >> i & 1) == 1){
        v = pp[i][v];
      }
    }
    if (u == v){
      return u;
    } else {
      for (int i = LOG - 1; i >= 0; i--){
        if (pp[i][u] != pp[i][v]){
          u = pp[i][u];
          v = pp[i][v];
        }
      }
      return pp[0][u];
    }
  }
  int dist(int u, int v){
    return d[u] + d[v] - d[lca(u, v)] * 2;
  }
};
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<vector<int>> E(n);
  for (int i = 0; i < n - 1; i++){
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    E[a].push_back(b);
    E[b].push_back(a);
  }
  pair<int, int> r = get_diameter(E);
  vector<int> pr(n, -1);
  vector<vector<int>> ch(n);
  queue<int> Q;
  Q.push(0);
  while (!Q.empty()){
    int v = Q.front();
    Q.pop();
    for (int w : E[v]){
      if (w != pr[v]){
        pr[w] = v;
        ch[v].push_back(w);
        Q.push(w);
      }
    }
  }
  lowest_common_ancestor T(pr, ch);
  vector<int> deg(n);
  for (int i = 0; i < n; i++){
    deg[i] = E[i].size();
  }
  queue<int> Q2;
  for (int i = 0; i < n; i++){
    if (deg[i] == 1 && i != r.first && i != r.second){
      Q2.push(i);
    }
  }
  long long ans = 0;
  vector<int> a, b, c;
  while (!Q2.empty()){
    int v = Q2.front();
    Q2.pop();
    int d1 = T.dist(v, r.first);
    int d2 = T.dist(v, r.second);
    a.push_back(v);
    if (d1 > d2){
      b.push_back(r.first);
      ans += d1;
    } else {
      b.push_back(r.second);
      ans += d2;
    }
    c.push_back(v);
    for (int w : E[v]){
      deg[w]--;
      if (deg[w] == 1){
        Q2.push(w);
      }
    }
  }
  int x = T.lca(r.first, r.second);
  while (r.first != x){
    ans += T.dist(r.first, r.second);
    a.push_back(r.first);
    b.push_back(r.second);
    c.push_back(r.first);
    r.first = pr[r.first];
  }
  while (r.second != x){
    ans += T.dist(x, r.second);
    a.push_back(x);
    b.push_back(r.second);
    c.push_back(r.second);
    r.second = pr[r.second];
  }
  cout << ans << "\n";
  for (int i = 0; i < n - 1; i++){
    cout << a[i] + 1 << ' ' << b[i] + 1 << ' ' << c[i] + 1 << "\n";
  }
}