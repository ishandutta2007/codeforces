#include <bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<vector<int>> E(n);
    for (int j = 0; j < n - 1; j++){
      int u, v;
      cin >> u >> v;
      u--;
      v--;
      E[u].push_back(v);
      E[v].push_back(u);
    }
    vector<int> d1(n, -1);
    d1[0] = 0;
    queue<int> Q1;
    Q1.push(0);
    while (!Q1.empty()){
      int v = Q1.front();
      Q1.pop();
      for (int w : E[v]){
        if (d1[w] == -1){
          d1[w] = d1[v] + 1;
          Q1.push(w);
        }
      }
    }
    int P = 0;
    for (int j = 0; j < n; j++){
      if (d1[j] > d1[P]){
        P = j;
      }
    }
    vector<int> d2(n, -1);
    d2[P] = 0;
    queue<int> Q2;
    Q2.push(P);
    while (!Q2.empty()){
      int v = Q2.front();
      Q2.pop();
      for (int w : E[v]){
        if (d2[w] == -1){
          d2[w] = d2[v] + 1;
          Q2.push(w);
        }
      }
    }
    vector<int> D(d1[P] + 1, 0);
    for (int j = 0; j < n; j++){
      D[d1[j]] = max(D[d1[j]], d2[j]);
    }
    for (int j = d1[P] - 1; j >= 0; j--){
      D[j] = max(D[j], D[j + 1]);
    }
    vector<int> mn_x(n + 1, n);
    for (int j = 0; j < d1[P]; j++){
      int r = (D[j + 1] + 1) / 2;
      if (r <= j){
        mn_x[j] = j - r;
      } else {
        mn_x[j] = 0;
      }
    }
    vector<int> ans(n);
    for (int j = 0; j < n; j++){
      for (int k = mn_x[j]; k < mn_x[j + 1]; k++){
        ans[k] = j + 1;
      }
    }
    for (int j = 0; j < n; j++){
      cout << ans[j];
      if (j < n - 1){
        cout << ' ';
      }
    }
    cout << endl;
  }
}