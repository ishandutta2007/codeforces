#include <bits/stdc++.h>
using namespace std;
bool is_eulerian(vector<vector<pair<int, int>>> &E, int s){
  int n = E.size();
  vector<int> odd;
  for (int i = 0; i < n; i++){
    if (E[i].size() % 2 == 1){
      odd.push_back(i);
    }
  }
  if (odd.size() >= 4){
    return false;
  }
  if (odd.size() == 2){
    if (odd[0] != s && odd[1] != s){
      return false;
    }
  }
  vector<bool> used(n, false);
  used[s] = true;
  queue<int> Q;
  Q.push(s);
  while (!Q.empty()){
    int v = Q.front();
    Q.pop();
    for (auto P : E[v]){
      int w = P.first;
      if (!used[w]){
        used[w] = true;
        Q.push(w);
      }
    }
  }
  for (int i = 0; i < n; i++){
    if (!used[i] && E[i].size() > 0){
      return false;
    }
  }
  return true;
}
void dfs(vector<vector<pair<int, int>>> &E, vector<bool> &used, vector<int> &ans, vector<int> &next, int v){
  int d = E[v].size();
  while (next[v] < d){
    int w = E[v][next[v]].first;
    int id = E[v][next[v]].second;
    next[v]++;
    if (!used[id]){
      used[id] = true;
      dfs(E, used, ans, next, w);
    }
  }
  ans.push_back(v);
}
vector<int> eulerian_trail(vector<vector<pair<int, int>>> &E, int m, int s){
  int n = E.size();
  vector<bool> used(m, false);
  vector<int> next(n, 0);
  vector<int> ans;
  dfs(E, used, ans, next, s);
  return ans;
}
int main(){
  int n, m;
  cin >> n >> m;
  vector<vector<pair<int, int>>> E(n);
  for (int i = 0; i < m; i++){
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    E[x].push_back(make_pair(y, i));
    E[y].push_back(make_pair(x, i));
  }
  bool ok = false;
  for (int i = 0; i < n; i++){
    vector<int> r;
    for (auto P : E[i]){
      int j = P.first;
      if (E[j].size() % 2 == 1){
        r.push_back(j);
      }
    }
    int cnt = E[i].size();
    for (int j = 0; j <= cnt; j++){
      int v = -1;
      if (j < cnt){
        v = E[i][j].first;
      }
      vector<vector<pair<int, int>>> E2(n);
      for (int k = 0; k < n; k++){
        for (auto P : E[k]){
          int w = P.first;
          if (k == i && E[w].size() % 2 == 1 || w == i & E[k].size() % 2 == 1){
            if ((k == i && w == v) || (k == v && w == i)){
              E2[k].push_back(P);
            }
          } else {
            E2[k].push_back(P);
          }
        }
      }
      if (is_eulerian(E2, i)){
        vector<int> ans = eulerian_trail(E2, m, i);
        ans.push_back(-2);
        for (int k : r){
          if (k != v){
            ans.push_back(k);
            ans.push_back(i);
          }
        }
        int k = ans.size();
        cout << k << endl;
        for (int l = 0; l < k; l++){
          cout << ans[l] + 1;
          if (l < k - 1){
            cout << ' ';
          }
        }
        cout << endl;
        ok = true;
        break;
      }
    }
    if (ok){
      break;
    }
  }
  if (!ok){
    cout << 0 << endl;
  }
}