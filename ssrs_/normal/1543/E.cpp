#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<vector<int>> E(1 << n);
    for (int j = 0; j < (n << (n - 1)); j++){
      int u, v;
      cin >> u >> v;
      E[u].push_back(v);
      E[v].push_back(u);
    }
    vector<int> P(1 << n);
    vector<bool> used(1 << n, false);
    P[0] = 0;
    used[0] = true;
    for (int j = 0; j < n; j++){
      P[1 << j] = E[0][j];
      used[E[0][j]] = true;
    }
    for (int j = 1; j < (1 << n); j++){
      if (__builtin_popcount(j) >= 2){
        int A = -1, B = -1;
        for (int k = 0; k < n; k++){
          if ((j >> k & 1) == 1){
            if (A == -1){
              A = k;
            } else if (B == -1){
              B = k;
            }
          }
        }
        int x = j - (1 << A), y = j - (1 << B);
        set<int> st;
        for (int v : E[P[x]]){
          if (!used[v]){
            st.insert(v);
          }
        }
        for (int v : E[P[y]]){
          if (st.count(v) == 1){
            P[j] = v;
            used[v] = true;
          }
        }
      }
    }
    for (int j = 0; j < (1 << n); j++){
      cout << P[j];
      if (j < (1 << n) - 1){
        cout << ' ';
      }
    }
    cout << endl;
    if (__builtin_popcount(n) > 1){
      cout << -1 << endl;
    } else {
      vector<int> X(1 << n);
      X[0] = 0;
      for (int j = 1; j < (1 << n); j++){
        int c = __builtin_ctz(j);
        X[j] = X[j - (1 << c)] ^ c;
      }
      vector<int> ans(1 << n);
      for (int j = 0; j < (1 << n); j++){
        ans[P[j]] = X[j];
      }
      for (int j = 0; j < (1 << n); j++){
        cout << ans[j];
        if (j < (1 << n) - 1){
          cout << ' ';
        }
      }
      cout << endl;
    }
  }
}