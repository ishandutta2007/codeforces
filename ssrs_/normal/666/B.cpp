#include <bits/stdc++.h>
using namespace std;
int INF = 1000000;
int main(){
  int n, m;
  cin >> n >> m;
  vector<vector<int>> E(n);
  for (int i = 0; i < m; i++){
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    E[u].push_back(v);
  }
  vector<vector<int>> dist(n, vector<int>(n, INF));
  for (int i = 0; i < n; i++){
    dist[i][i] = 0;
    queue<int> Q;
    Q.push(i);
    while (!Q.empty()){
      int v = Q.front();
      Q.pop();
      for (int w : E[v]){
        if (dist[i][w] == INF){
          dist[i][w] = dist[i][v] + 1;
          Q.push(w);
        }
      }
    }
    for (int j = 0; j < n; j++){
      if (dist[i][j] == 0 || dist[i][j] == INF){
        dist[i][j] = -INF;
      }
    }
  }
  vector<vector<pair<int, int>>> A(n);
  for (int i = 0; i < n; i++){
    vector<pair<int, int>> tmp;
    for (int j = 0; j < n; j++){
      tmp.push_back(make_pair(dist[j][i], j));
    }
    sort(tmp.rbegin(), tmp.rend());
    for (int j = 0; j < 4; j++){
      A[i].push_back(tmp[j]);
    }
  }
  vector<vector<pair<int, int>>> D(n);
  for (int i = 0; i < n; i++){
    vector<pair<int, int>> tmp;
    for (int j = 0; j < n; j++){
      tmp.push_back(make_pair(dist[i][j], j));
    }
    sort(tmp.rbegin(), tmp.rend());
    for (int j = 0; j < 4; j++){
      D[i].push_back(tmp[j]);
    }
  }
  int mx = 0;
  vector<int> ans(4);
  for (int b = 0; b < n; b++){
    for (int c = 0; c < n; c++){
      if (b != c){
        for (int i = 0; i < 4; i++){
          for (int j = 0; j < 4; j++){
            int a = A[b][i].second;
            int d = D[c][j].second;
            if (a != b && a != c && a != d && b != d && c != d){
              int L = dist[b][c] + A[b][i].first + D[c][j].first;
              if (L > mx){
                mx = L;
                ans = {a, b, c, d};
                break;
              }
            }
          }
        }
      }
    }
  }
  for (int i = 0; i < 4; i++){
    cout << ans[i] + 1;
    if (i < 3){
      cout << ' ';
    }
  }
  cout << endl;
}