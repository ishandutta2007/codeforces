#include <bits/stdc++.h>
using namespace std;
int INF = 100000000;
int main(){
  int n, m;
  cin >> n >> m;
  vector<int> d(n);
  bool negative_one = false;
  for (int i = 0; i < n; i++){
    cin >> d[i];
    if (d[i] == -1){
      negative_one = true;
    }
  }
  vector<vector<pair<int, int>>> E(n);
  for (int i = 0; i < m; i++){
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    E[u].push_back(make_pair(v, i));
    E[v].push_back(make_pair(u, i));
  }
  if (negative_one){
    //yes
    vector<int> dist(n, INF);
    queue<int> Q;
    for (int i = 0; i < n; i++){
      if (d[i] == -1){
        dist[i] = 0;
        Q.push(i);
      }
    }
    while (!Q.empty()){
      int v = Q.front();
      Q.pop();
      for (auto P : E[v]){
        int w = P.first;
        if (dist[w] == INF){
          dist[w] = dist[v] + 1;
          Q.push(w);
        }
      }
    }
    vector<pair<int, int>> order(n);
    for (int i = 0; i < n; i++){
      order[i] = make_pair(dist[i], i);
    }
    sort(order.begin(), order.end());
    reverse(order.begin(), order.end());
    vector<bool> subset(m, false);
    vector<bool> used(n, false);
    vector<int> deg(n, 0);
    for (int i = 0; i < n; i++){
      int v = order[i].second;
      if (d[v] != -1){
        if (deg[v] % 2 != d[v]){
          for (auto P : E[v]){
            int w = P.first;
            if (!used[w]){
              int id = P.second;
              subset[id] = true;
              deg[v]++;
              deg[w]++;
              break;
            }
          }
        }
      }
      used[v] = true;
    }
    vector<int> ans;
    for (int i = 0; i < m; i++){
      if (subset[i]){
        ans.push_back(i + 1);
      }
    }
    int k = ans.size();
    cout << k << endl;
    for (int i = 0; i < k; i++){
      cout << ans[i] << endl;
    }
  } else {
    //only 0 and 1
    int sum = 0;
    for (int i = 0; i < n; i++){
      sum += d[i];
    }
    if (sum % 2 != 0){
      cout << -1 << endl;
    } else {
      //yes
      vector<int> dist(n, INF);
      queue<int> Q;
      dist[0] = 0;
      Q.push(0);
      while (!Q.empty()){
        int v = Q.front();
        Q.pop();
        for (auto P : E[v]){
          int w = P.first;
          if (dist[w] == INF){
            dist[w] = dist[v] + 1;
            Q.push(w);
          }
        }
      }
      vector<pair<int, int>> order(n);
      for (int i = 0; i < n; i++){
        order[i] = make_pair(dist[i], i);
      }
      sort(order.begin(), order.end());
      reverse(order.begin(), order.end());
      vector<bool> subset(m, false);
      vector<bool> used(n, false);
      vector<int> deg(n, 0);
      for (int i = 0; i < n; i++){
        int v = order[i].second;
        if (deg[v] % 2 != d[v]){
          for (auto P : E[v]){
            int w = P.first;
            if (!used[w]){
              int id = P.second;
              subset[id] = true;
              deg[v]++;
              deg[w]++;
              break;
            }
          }
        }
        used[v] = true;
      }
      vector<int> ans;
      for (int i = 0; i < m; i++){
        if (subset[i]){
          ans.push_back(i + 1);
        }
      }
      int k = ans.size();
      cout << k << endl;
      for (int i = 0; i < k; i++){
        cout << ans[i] << endl;
      }
    }
  }
}