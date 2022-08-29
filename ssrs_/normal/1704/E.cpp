#include <bits/stdc++.h>
using namespace std;
const long long MOD = 998244353;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, m;
    cin >> n >> m;
    vector<long long> a(n);
    for (int j = 0; j < n; j++){
      cin >> a[j];
    }
    vector<vector<int>> E(n);
    for (int j = 0; j < m; j++){
      int x, y;
      cin >> x >> y;
      x--;
      y--;
      E[x].push_back(y);
    }
    if (a == vector<long long>(n, 0)){
      cout << 0 << endl;
    } else {
      vector<int> in(n, 0);
      for (int j = 0; j < n; j++){
        for (int k : E[j]){
          in[k]++;
        }
      }
      queue<int> Q;
      for (int j = 0; j < n; j++){
        if (in[j] == 0){
          Q.push(j);
        }
      }
      vector<int> T;
      while (!Q.empty()){
        int v = Q.front();
        Q.pop();
        T.push_back(v);
        for (int w : E[v]){
          in[w]--;
          if (in[w] == 0){
            Q.push(w);
          }
        }
      }
      bool ok = false;
      vector<long long> b(n);
      for (int j = 0; j < n; j++){
        b[j] = a[j];
      }
      for (int j = 0; j < n; j++){
        a[j] %= MOD;
      }
      for (int j = 0; j < 2000; j++){
        vector<int> S;
        for (int k = 0; k < n; k++){
          if (b[k] > 0){
            S.push_back(k);
          }
        }
        for (int v : S){
          b[v]--;
          a[v] += MOD - 1;
          a[v] %= MOD;
          for (int w : E[v]){
            b[w]++;
            a[w]++;
            a[w] %= MOD;
          }
        }
        for (int k = 0; k < n; k++){
          b[k] = min(b[k], (long long) 1000000000000);
        }
        if (b == vector<long long>(n, 0)){
          cout << j + 1 << endl;
          ok = true;
          break;
        }
      }
      if (!ok){
        for (int j = 0; j < n; j++){
          if (b[j] > 0){
            for (int k : E[j]){
              assert(b[k] > 0);
            }
          }
        }
        vector<long long> dp(n);
        for (int j = 0; j < n; j++){
          dp[j] = a[j];
        }
        for (int j = 0; j < n; j++){
          for (int w : E[T[j]]){
            dp[w] += dp[T[j]];
            dp[w] %= MOD;
          }
        }
        cout << (dp[T[n - 1]] + 2000) % MOD << endl;
      }
    }
  }
}