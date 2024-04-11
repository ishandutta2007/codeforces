#include <bits/stdc++.h>
using namespace std;
const int INF = 10000000;
pair<int, int> get_diameter(vector<vector<int>> &E){
  int N = E.size();
  queue<int> Q;
  Q.push(0);
  vector<bool> used(N, false);
  used[0] = true;
  int s;
  while (!Q.empty()){
    s = Q.front();
    Q.pop();
    for (int w : E[s]){
      if (!used[w]){
        used[w] = true;
        Q.push(w);
      }
    }
  }
  Q.push(s);
  vector<bool> used2(N, false);
  used2[s] = true;
  int t;
  while (!Q.empty()){
    t = Q.front();
    Q.pop();
    for (int w : E[t]){
      if (!used2[w]){
        used2[w] = true;
        Q.push(w);
      }
    }
  }
  return make_pair(s, t);
}
struct lazy_segment_tree{
  int N;
  vector<int> ST1, ST2;
  vector<bool> lazy;
  lazy_segment_tree(){
  }
  lazy_segment_tree(vector<int> &a){
    int n = a.size();
    N = 1;
    while (N < n){
      N *= 2;
    }
    ST1 = vector<int>(N * 2 - 1, 0);
    for (int i = 0; i < n; i++){
      ST1[N - 1 + i] = a[i];
    }
    for (int i = N - 2; i >= 0; i--){
      ST1[i] = max(ST1[i * 2 + 1], ST1[i * 2 + 2]);
    }
    ST2 = vector<int>(N * 2 - 1, 0);
    lazy = vector<bool>(N * 2 - 1, false);
  }
  void eval(int i){
    if (lazy[i]){
      if (i < N - 1){
        lazy[i * 2 + 1] = !lazy[i * 2 + 1];
        lazy[i * 2 + 2] = !lazy[i * 2 + 2];
      }
      swap(ST1[i], ST2[i]);
      lazy[i] = false;
    }
  }
  void flip(int L, int R, int i, int l, int r){
    eval(i);
    if (r <= L || R <= l){
      return;
    } else if (L <= l && r <= R){
      lazy[i] = !lazy[i];
      eval(i);
    } else {
      int m = (l + r) / 2;
      flip(L, R, i * 2 + 1, l, m);
      flip(L, R, i * 2 + 2, m, r);
      ST1[i] = max(ST1[i * 2 + 1], ST1[i * 2 + 2]);
      ST2[i] = max(ST2[i * 2 + 1], ST2[i * 2 + 2]);
    }
  }
  void flip(int L, int R){
    flip(L, R, 0, 0, N);
  }
  int all(){
    eval(0);
    return ST1[0];
  }
};
struct euler_tour{
  vector<int> in, out, a;
  lazy_segment_tree ST;
  void dfs(vector<vector<int>> &E, int v, int dist){
    in[v] = a.size();
    a.push_back(dist);
    for (int w : E[v]){
      if (in[w] == -1){
        dfs(E, w, dist + 1);
      }
    }
    out[v] = a.size();
  }
  euler_tour(vector<vector<int>> &E, int r){
    int N = E.size();
    in = vector<int>(N, -1);
    out = vector<int>(N, -1);
    dfs(E, r, 0);
    ST = lazy_segment_tree(a);
  }
  int dist(int v){
    return a[in[v]];
  }
  void flip(int v){
    ST.flip(in[v], out[v]);
  }
  int query(){
    return ST.all();
  }
};
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> u(n - 1), v(n - 1), t(n - 1);
  for (int i = 0; i < n - 1; i++){
    cin >> u[i] >> v[i] >> t[i];
    u[i]--;
    v[i]--;
  }
  vector<vector<int>> E(n);
  for (int i = 0; i < n - 1; i++){
    E[u[i]].push_back(v[i]);
    E[v[i]].push_back(u[i]);
  }
  int r1, r2;
  tie(r1, r2) = get_diameter(E);
  euler_tour T1(E, r1);
  euler_tour T2(E, r2);
  vector<int> c1(n - 1);
  vector<int> c2(n - 1);
  for (int i = 0; i < n - 1; i++){
    if (T1.dist(u[i]) > T1.dist(v[i])){
      c1[i] = u[i];
    } else {
      c1[i] = v[i];
    }
    if (T2.dist(u[i]) > T2.dist(v[i])){
      c2[i] = u[i];
    } else {
      c2[i] = v[i];
    }
  }
  for (int i = 0; i < n - 1; i++){
    if (t[i] == 1){
      T1.flip(c1[i]);
      T2.flip(c2[i]);
    }
  }
  int m;
  cin >> m;
  for (int i = 0; i < m; i++){
    int id;
    cin >> id;
    id--;
    T1.flip(c1[id]);
    T2.flip(c2[id]);
    cout << max(T1.query(), T2.query()) << "\n";
  }
}