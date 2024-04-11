#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
struct lazy_segment_tree{
  int N;
  vector<long long> sum1, sum2, lazy;
  lazy_segment_tree(){
  }
  lazy_segment_tree(vector<long long> A){
    int n = A.size();
    N = 1;
    while (N < n){
      N *= 2;
    }
    sum1 = vector<long long>(N * 2 - 1, 0);
    sum2 = vector<long long>(N * 2 - 1, 0);
    lazy = vector<long long>(N * 2 - 1, 0);
    for (int i = 0; i < n; i++){
      sum1[N - 1 + i] = A[i];
      sum2[N - 1 + i] = A[i] * A[i] % MOD;
    }
    for (int i = N - 2; i >= 0; i--){
      sum1[i] = (sum1[i * 2 + 1] + sum1[i * 2 + 2]) % MOD;
      sum2[i] = (sum2[i * 2 + 1] + sum2[i * 2 + 2]) % MOD;
    }
  }
  void eval(int i, int l, int r){
    if (i < N - 1){
      lazy[i * 2 + 1] = (lazy[i * 2 + 1] + lazy[i]) % MOD;
      lazy[i * 2 + 2] = (lazy[i * 2 + 2] + lazy[i]) % MOD;
    }
    sum2[i] = (sum2[i] + sum1[i] * lazy[i] * 2 + lazy[i] * lazy[i] % MOD * (r - l)) % MOD;
    sum1[i] = (sum1[i] + lazy[i] * (r - l)) % MOD;
    lazy[i] = 0;
  }
  void range_add(int L, int R, long long x, int i, int l, int r){
    eval(i, l, r);
    if (r <= L || R <= l){
      return;
    } else if (L <= l && r <= R){
      lazy[i] = x;
      eval(i, l, r);
    } else {
      int m = (l + r) / 2;
      range_add(L, R, x, i * 2 + 1, l, m);
      range_add(L, R, x, i * 2 + 2, m, r);
      sum1[i] = (sum1[i * 2 + 1] + sum1[i * 2 + 2]) % MOD;
      sum2[i] = (sum2[i * 2 + 1] + sum2[i * 2 + 2]) % MOD;
    }
  }
  void range_add(int L, int R, long long x){
    range_add(L, R, x, 0, 0, N);
  }
  long long range_sqsum(int L, int R, int i, int l, int r){
    eval(i, l, r);
    if (r <= L || R <= l){
      return 0;
    } else if (L <= l && r <= R){
      return sum2[i];
    } else {
      int m = (l + r) / 2;
      return (range_sqsum(L, R, i * 2 + 1, l, m) + range_sqsum(L, R, i * 2 + 2, m, r)) % MOD;
    }
  }
  long long range_sqsum(int L, int R){
    return range_sqsum(L, R, 0, 0, N);
  }
};
struct euler_tour{
  vector<int> p, in, out;
  lazy_segment_tree ST;
  void dfs(vector<vector<int>> &c, int &t, int v = 0){
    in[v] = t;
    t++;
    for (int w : c[v]){
      dfs(c, t, w);
    }
    out[v] = t;
  }
  euler_tour(vector<int> &p, vector<vector<int>> &c, vector<long long> &A): p(p){
    int N = p.size();
    in = vector<int>(N);
    out = vector<int>(N);
    int t = 0;
    dfs(c, t);
    vector<long long> B(N);
    for (int i = 0; i < N; i++){
      B[in[i]] = A[i];
    }
    ST = lazy_segment_tree(B);
  }
  void subtree_add(int v, long long x){
    ST.range_add(in[v], out[v], x);
  }
  long long subtree_sqsum(int v){
    return ST.range_sqsum(in[v], out[v]);
  }
};
void dfs(vector<int> &euler, vector<vector<int>> &c, int v = 0){
  euler.push_back(v);
  for (int w : c[v]){
    dfs(euler, c, w);
    euler.push_back(v);
  }
}
int main(){
  int n;
  cin >> n;
  vector<vector<pair<int, int>>> E(n);
  for (int i = 0; i < n - 1; i++){
    int a, b, c;
    cin >> a >> b >> c;
    a--;
    b--;
    E[a].push_back(make_pair(c, b));
    E[b].push_back(make_pair(c, a));
  }
  int q;
  cin >> q;
  vector<int> U(q), V(q);
  for (int i = 0; i < q; i++){
    cin >> U[i] >> V[i];
    U[i]--;
    V[i]--;
  }
  vector<int> p(n, -1);
  vector<vector<int>> c1(n);
  vector<vector<pair<int, int>>> c2(n);
  vector<long long> d(n, 0);
  queue<int> Q;
  Q.push(0);
  while (!Q.empty()){
    int v = Q.front();
    Q.pop();
    for (auto P : E[v]){
      int w = P.second;
      if (w != p[v]){
        p[w] = v;
        c1[v].push_back(w);
        c2[v].push_back(P);
        d[w] = (d[v] + P.first) % MOD;
        Q.push(w);
      }
    }
  }
  vector<int> euler;
  dfs(euler, c1);
  vector<int> pos(n, -1);
  for (int i = 0; i < n * 2 - 1; i++){
    if (pos[euler[i]] == -1){
      pos[euler[i]] = i;
    }
  }
  map<pair<int, int>, int> mp;
  for (int i = 0; i < n; i++){
    for (auto P : E[i]){
      mp[make_pair(i, P.second)] = P.first;
    }
  }
  vector<int> dist(n * 2 - 2);
  for (int i = 0; i < n * 2 - 2; i++){
    dist[i] = mp[make_pair(euler[i], euler[i + 1])];
  }
  vector<vector<pair<int, int>>> query(n);
  for (int i = 0; i < q; i++){
    query[U[i]].push_back(make_pair(V[i], i));
  }
  euler_tour T(p, c1, d);
  vector<long long> ans(q, 0);
  for (int i = 0; i < n * 2 - 2; i++){
    if (i == pos[euler[i]]){
      int v = euler[i];
      for (auto P : query[v]){
        int w = P.first;
        int id = P.second;
        ans[id] += T.subtree_sqsum(w) * 2;
        ans[id] -= T.subtree_sqsum(0);
        ans[id] += MOD;
        ans[id] %= MOD;
      }
    }
    if (euler[i + 1] == p[euler[i]]){
      T.subtree_add(0, (MOD - dist[i]) % MOD);
      T.subtree_add(euler[i], dist[i] * 2 % MOD);
    } else {
      T.subtree_add(0, dist[i]);
      T.subtree_add(euler[i + 1], (MOD - dist[i]) * 2 % MOD);
    }
  }
  for (int i = 0; i < q; i++){
    cout << ans[i] << endl;
  }
}