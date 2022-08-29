#include <bits/stdc++.h>
using namespace std;
//https://kokiymgch.hatenablog.com/entry/2017/12/07/193238
vector<int> eularian_trail(const int s, vector<unordered_map<int, int>> &g) {
        function<void (int, vector<int> &)> dfs = [&](int u, vector<int> &trail) {
                while (!g[u].empty()) {
                        auto itr = g[u].begin();
                        int v = (*itr).first;
                        if (g[u][v] == 1){
                          g[u].erase(v);
                        } else {
                          g[u][v]--;
                        }
                        if (g[v][u] == 1){
                          g[v].erase(u);
                        } else {
                          g[v][u]--;
                        }
                        dfs(v, trail);
                }
                trail.push_back(u);
        };
        vector<int> trail;
        dfs(s, trail);
        return trail;
}
pair<bool, vector<int>> possible(vector<pair<int, int>> &x, int d, int f){
  int V = 1 << d;
  int N = x.size();
  if (f == 0){
  vector<vector<int>> E(V);
  vector<int> deg(V, 0);
  //to, edge-id
  for (int i = 0; i < N; i++){
    int u = x[i].first & (V - 1);
    int v = x[i].second & (V - 1);
    E[u].push_back(v);
    E[v].push_back(u);
    deg[u]++;
    deg[v]++;
  }
    for (int i = 0; i < V; i++){
      if (deg[i] % 2 != 0){
        return make_pair(false, vector<int>());
      }
    }
    //connected components
    vector<bool> used(V, false);
    bool ok = true;
    int cnt = 0;
    for (int i = 0; i < V; i++){
      if (!E[i].empty()){
        if (cnt == 1 && !used[i]){
          ok = false;
          break;
        } else {
          cnt = 1;
          used[i] = true;
          queue<int> Q;
          Q.push(i);
          while (!Q.empty()){
            int v = Q.front();
            Q.pop();
            for (int w : E[v]){
              if (!used[w]){
                used[w] = true;
                Q.push(w);
              }
            }
          }
        }
      }
    }
    if (!ok){
      return make_pair(false, vector<int>());
    }
    return make_pair(true, vector<int>());
  }
  //f==1
  vector<unordered_map<int, int>> E(V);
  vector<int> deg(V, 0);
  map<pair<int, int>, vector<int>> E2;
  //to, edge-id
  for (int i = 0; i < N; i++){
    int u = x[i].first & (V - 1);
    int v = x[i].second & (V - 1);
    E[u][v]++;
    E[v][u]++;
    deg[u]++;
    deg[v]++;
    if (f == 1){
      E2[make_pair(u, v)].push_back(i * 2 + 1);
      E2[make_pair(v, u)].push_back(i * 2 + 2);
    }
  }
  //make permutation
  int start = 0;
  while (E[start].empty()){
    start++;
  }
  vector<int> ans = eularian_trail(start, E);
  vector<int> ans2;
  for (int i = 0; i < N; i++){
    ans2.push_back(E2[make_pair(ans[i], ans[i + 1])].back());
    E2[make_pair(ans[i], ans[i + 1])].pop_back();
    E2[make_pair(ans[i + 1], ans[i])].pop_back();
  }
  return make_pair(true, ans2);
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<pair<int, int>> x(n);
  for (int i = 0; i < n; i++){
    cin >> x[i].first >> x[i].second;
    x[i].first += (1 << 20);
    x[i].second += (1 << 20);
  }
  //binary search
  int tv = -1;
  int fv = 21;
  while (fv - tv > 1){
    int mv = (fv + tv) / 2;
    pair<bool, vector<int>> tmp = possible(x, mv, 0);
    if (tmp.first){
      tv = mv;
    } else {
      fv = mv;
    }
  }
  cout << tv << endl;
  vector<int> ans = possible(x, tv, 1).second;
  vector<int> ans2(n * 2);
  for (int i = 0; i < n; i++){
    if (ans[i] % 2 == 0){
      ans2[i * 2] = ans[i];
      ans2[i * 2 + 1] = ans[i] - 1;
    } else {
      ans2[i * 2] = ans[i];
      ans2[i * 2 + 1] = ans[i] + 1;
    }
  }
  for (int i = 0; i < n * 2; i++){
    cout << ans2[i];
    if (i < n * 2 - 1){
      cout << ' ';
    }
  }
  cout << endl;
}