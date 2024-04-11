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
    vector<vector<int>> E(n);
    for (int j = 0; j < n; j++){
      E[a[j]].push_back(b[j]);
      E[b[j]].push_back(a[j]);
    }
    long long ans = 1;
    vector<bool> used(n, false);
    for (int j = 0; j < n; j++){
      if (!used[j]){
        used[j] = true;
        ans *= 2;
        ans %= MOD;
        queue<int> Q;
        Q.push(j);
        while (!Q.empty()){
          int v = Q.front();
          Q.pop();
          for (int w : E[v]){
            if (!used[w]){
              used[w] = true;
              Q.push(w);
            }
          }
        }
      }
    }
    cout << ans << endl;
  }
}