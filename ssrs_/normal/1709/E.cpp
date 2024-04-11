#include <bits/stdc++.h>
using namespace std;
struct xor_set{
  set<int> st;
  int X;
  xor_set(): X(0){
  }
  void clear(){
    st.clear();
  }
  void all_xor(int a){
    X ^= a;
  }
  int count(int a){
    return st.count(X ^ a);
  }
  void insert(int a){
    st.insert(X ^ a);
  }
  vector<int> get(){
    vector<int> ans;
    for (int x : st){
      ans.push_back(X ^ x);
    }
    return ans;
  }
};
int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  vector<vector<int>> E(n);
  for (int i = 0; i < n - 1; i++){
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    E[x].push_back(y);
    E[y].push_back(x);
  }
  vector<int> p(n, -1);
  vector<vector<int>> c(n);
  vector<int> bfs;
  queue<int> Q;
  Q.push(0);
  while (!Q.empty()){
    int v = Q.front();
    Q.pop();
    bfs.push_back(v);
    for (int w : E[v]){
      if (w != p[v]){
        p[w] = v;
        c[v].push_back(w);
        Q.push(w);
      }
    }
  }
  reverse(bfs.begin(), bfs.end());
  vector<int> sz(n, 1);
  for (int v : bfs){
    for (int w : c[v]){
      sz[v] += sz[w];
    }
    for (int &w : c[v]){
      if (sz[w] > sz[c[v][0]]){
        swap(w, c[v][0]);
      }
    }
  }
  vector<xor_set> dp(n);
  int ans = 0;
  for (int v : bfs){
    if (!c[v].empty()){
      swap(dp[v], dp[c[v][0]]);
    }
    bool ok = false;
    if (dp[v].count(a[v]) == 1){
      ok = true;
    }
    dp[v].insert(0);
    for (int w : c[v]){
      if (w != c[v][0]){
        vector<int> A = dp[w].get();
        for (int x : A){
          if (dp[v].count(x ^ a[v]) == 1){
            ok = true;
          }
        }
        for (int x : A){
          dp[v].insert(x);
        }
      }
    }
    if (ok){
      ans++;
      dp[v].clear();
    }
    dp[v].all_xor(a[v]);
  }
  cout << ans << endl;
}