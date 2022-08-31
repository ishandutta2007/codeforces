#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, m;
  cin >> n >> m;
  vector<vector<int>> E(n);
  for (int i = 0; i < n - 1; i++){
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    E[u].push_back(v);
    E[v].push_back(u);
  }
  vector<int> d(n, -1);
  vector<int> p(n, -1);
  vector<bool> used(n, false);
  queue<int> Q;
  Q.push(0);
  d[0] = 0;
  while (!Q.empty()){
    int v = Q.front();
    Q.pop();
    if (!used[v]){
      used[v] = true;
      for (int u : E[v]){
        if (d[u] == -1){
          p[u] = v;
          d[u] = d[v] + 1;
          Q.push(u);
        }
      }
    }
  }
  /*
  //distance to root
  for (int i = 0; i < n; i++){
    cout << d[i] << ' ';
  }
  cout << endl;
  //parent
  for (int i = 0; i < n; i++){
    cout << p[i] << ' ';
  }
  cout << endl;
  */
  vector<vector<int>> pp(n, vector<int>(20, -1));
  for (int i = 0; i < n; i++){
    pp[i][0] = p[i];
  }
  for (int j = 1; j < 20; j++){
    for (int i = 0; i < n; i++){
      if (pp[i][j - 1] != -1){
        pp[i][j] = pp[pp[i][j - 1]][j - 1];
      }
    }
  }
  /*
  for (int j = 0; j < 5; j++){
    for (int i = 0; i < n; i++){
      cout << pp[i][j] << ' ';
    }
    cout << endl;
  }
  */
  for (int i = 0; i < m; i++){
    int k;
    cin >> k;
    vector<int> v(k);
    int md = -1; //max distance
    int mdv = 0; //max distance vertex
    for (int j = 0; j < k; j++){
      cin >> v[j];
      v[j]--;
      if (v[j] != 0){
        v[j] = p[v[j]];
      }
      if (d[v[j]] > md){
        md = d[v[j]];
        mdv = v[j];
      }
    }
    bool res = true;
    for (int j = 0; j < k; j++){
      int dd = d[mdv] - d[v[j]]; //depth difference
      int cv = mdv; //current vertex
      for (int digit = 0; digit < 20; digit++){
        //bit digit
        if ((dd >> digit) & 1){
          cv = pp[cv][digit];
        }
      }
      if (cv != v[j]){
        res = false;
      }
    }
    if (res){
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}