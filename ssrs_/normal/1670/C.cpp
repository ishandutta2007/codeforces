#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int j = 0; j < n; j++){
      cin >> a[j];
      a[j]--;
    }
    vector<int> b(n);
    for (int j = 0; j < n; j++){
      cin >> b[j];
      b[j]--;
    }
    vector<int> d(n);
    for (int j = 0; j < n; j++){
      cin >> d[j];
      d[j]--;
    }
    vector<bool> used(n, false);
    bool ok = true;
    for (int j = 0; j < n; j++){
      if (d[j] != -1){
        if (used[d[j]]){
          ok = false;
        }
        used[d[j]] = true;
      }
    }
    if (!ok){
      cout << 0 << "\n";
    } else {
      vector<vector<int>> E(n);
      for (int j = 0; j < n; j++){
        E[a[j]].push_back(b[j]);
        E[b[j]].push_back(a[j]);
      }
      long long ans = 1;
      vector<bool> used2(n, false);
      for (int j = 0; j < n; j++){
        if (!used2[j]){
          used2[j] = true;
          queue<int> Q;
          Q.push(j);
          int cnt = 0;
          bool ok2 = true;
          while (!Q.empty()){
            int v = Q.front();
            Q.pop();
            cnt++;
            if (used[v]){
              ok2 = false;
            }
            for (int w : E[v]){
              if (!used2[w]){
                used2[w] = true;
                Q.push(w);
              }
            }
          }
          if (ok2 && cnt >= 2){
            ans *= 2;
            ans %= MOD;
          }
        }
      }
      cout << ans << "\n";
    }
  }
}