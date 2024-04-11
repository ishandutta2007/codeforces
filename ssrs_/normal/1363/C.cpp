#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, x;
    cin >> n >> x;
    x--;
    vector<vector<int>> E(n);
    for (int j = 0; j < n - 1; j++){
      int u, v;
      cin >> u >> v;
      u--;
      v--;
      E[u].push_back(v);
      E[v].push_back(u);
    }
    vector<int> A;
    vector<bool> used(n, false);
    used[x] = true;
    for (int v : E[x]){
      queue<int> Q;
      Q.push(v);
      int cnt = 1;
      while (!Q.empty()){
        int w = Q.front();
        Q.pop();
        for (int u : E[v]){
          if (!used[u]){
            used[u] = true;
            Q.push(u);
            cnt++;
          }
        }
      }
      A.push_back(cnt);
    }
    int M = A.size();
    /*
    for (int j = 0; j < M; j++){
      cout << A[j] << ' ';
    }
    cout << endl;
    */
    if (E[x].size() <= 1){
      cout << "Ayush" << endl;
    } else if (n % 2 == 0){
      cout << "Ayush" << endl;
    } else {
      cout << "Ashish" << endl;
    }
  }
}