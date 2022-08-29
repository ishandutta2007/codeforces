#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int p;
    cin >> p;
    int n = 1 << p;
    vector<vector<pair<int, int>>> E(n);
    for (int j = 0; j < n - 1; j++){
      int u, v;
      cin >> u >> v;
      u--;
      v--;
      E[u].push_back(make_pair(j, v));
      E[v].push_back(make_pair(j, u));
    }
    vector<int> pr(n, -1);
    vector<int> pe(n, -1);
    vector<int> d(n, -1);
    queue<int> Q;
    Q.push(0);
    while (!Q.empty()){
      int v = Q.front();
      Q.pop();
      for (auto P : E[v]){
        int w = P.second;
        if (w != pr[v]){
          pr[w] = v;
          pe[w] = P.first;
          d[w] = d[v] + 1;
          Q.push(w);
        }
      }
    }
    vector<int> av(n), ae(n - 1);
    av[0] = n;
    int cnt = 1;
    for (int j = 1; j < n; j++){
      if (d[j] % 2 == 0){
        av[j] = cnt;
        ae[pe[j]] = n + cnt;
        cnt++;
      } else {
        av[j] = n + cnt;
        ae[pe[j]] = cnt;
        cnt++;
      }
    }
    cout << 1 << endl;
    for (int j = 0; j < n; j++){
      cout << av[j];
      if (j < n - 1){
        cout << ' ';
      }
    }
    cout << endl;
    for (int j = 0; j < n - 1; j++){
      cout << ae[j];
      if (j < n - 2){
        cout << ' ';
      }
    }
    cout << endl;
  }
}