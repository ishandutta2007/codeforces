#include <bits/stdc++.h>
using namespace std;
int maximum_independent_set(vector<vector<bool>> &E){
  int N = E.size();
  int A = N / 2, B = N - A;
  vector<bool> ok(1 << A, true);
  vector<int> s(1 << A, (1 << B) - 1);
  for (int i = 0; i < A; i++){
    for (int j = 0; j < A; j++){
      if (E[i][j]){
        ok[(1 << i) | (1 << j)] = false;
      }
    }
    for (int j = 0; j < B; j++){
      if (E[i][A + j]){
        s[1 << i] -= 1 << j;
      }
    }
  }
  for (int i = 0; i < A; i++){
    for (int j = 0; j < (1 << A); j++){
      if ((j >> i & 1) == 1){
        if (!ok[j - (1 << i)]){
          ok[j] = false;
        }
        s[j] = s[j] & s[j - (1 << i)];
      }
    }
  }
  vector<bool> ok2(1 << B, true);
  for (int i = 0; i < B; i++){
    for (int j = 0; j < B; j++){
      if (E[A + i][A + j]){
        ok2[(1 << i) | (1 << j)] = false;
      }
    }
  }
  for (int i = 0; i < B; i++){
    for (int j = 0; j < (1 << B); j++){
      if ((j >> i & 1) == 1){
        if (!ok2[j - (1 << i)]){
          ok2[j] = false;
        }
      }
    }
  }
  vector<int> mx(1 << B, 0);
  for (int i = 0; i < (1 << B); i++){
    if (ok2[i]){
      mx[i] = __builtin_popcount(i);
    }
  }
  for (int i = 0; i < B; i++){
    for (int j = 0; j < (1 << B); j++){
      if ((j >> i & 1) == 1){
        mx[j] = max(mx[j], mx[j - (1 << i)]);
      }
    }
  }
  int ans = 0;
  for (int i = 0; i < (1 << A); i++){
    if (ok[i]){
      ans = max(ans, __builtin_popcount(i) + mx[s[i]]);
    }
  }
  return ans;
}
int main(){
  int n, m;
  cin >> n >> m;
  vector<pair<int, string>> e(n);
  for (int i = 0; i < n; i++){
    int t;
    cin >> t;
    e[i].first = t;
    if (t == 2){
      cin >> e[i].second;
    }
  }
  map<string, int> mp;
  for (int i = 0; i < n; i++){
    if (e[i].first == 2){
      if (mp.count(e[i].second) == 0){
        int id = mp.size();
        mp[e[i].second] = id;
      }
    }
  }
  vector<bool> visit(m, false);
  vector<vector<bool>> E(m, vector<bool>(m, false));
  for (int i = n - 1; i >= 0; i--){
    if (e[i].first == 2){
      visit[mp[e[i].second]] = true;
    }
    if (e[i].first == 1){
      for (int j = 0; j < m; j++){
        if (visit[j]){
          for (int k = j + 1; k < m; k++){
            if (visit[k]){
              E[j][k] = true;
              E[k][j] = true;
            }
          }
          visit[j] = false;
        }
      }
    }
  }
  cout << maximum_independent_set(E) << endl;
}