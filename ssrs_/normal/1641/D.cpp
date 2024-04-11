#include <bits/stdc++.h>
using namespace std;
const int INF = 2000000001;
int main(){
  mt19937_64 mt(chrono::steady_clock::now().time_since_epoch().count());
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> a(n, vector<int>(m));
  vector<int> w(n);
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      cin >> a[i][j];
    }
    cin >> w[i];
  }
  vector<pair<int, vector<int>>> P(n);
  for (int i = 0; i < n; i++){
    P[i] = make_pair(w[i], a[i]);
  }
  sort(P.begin(), P.end());
  for (int i = 0; i < n; i++){
    a[i] = P[i].second;
    w[i] = P[i].first;
    sort(a[i].begin(), a[i].end());
  }
  vector<int> X;
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      X.push_back(a[i][j]);
    }
  }
  sort(X.begin(), X.end());
  X.erase(unique(X.begin(), X.end()), X.end());
  int Xcnt = X.size();
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      a[i][j] = lower_bound(X.begin(), X.end(), a[i][j]) - X.begin();
    }
  }
  vector<unsigned long long> hash(Xcnt);
  for (int i = 0; i < Xcnt; i++){
    hash[i] = mt();
  }
  vector<vector<unsigned long long>> S(1 << m, vector<unsigned long long>(n));
  for (int i = 0; i < n; i++){
    for (int j = 0; j < (1 << m); j++){
      for (int k = 0; k < m; k++){
        if ((j >> k & 1) == 1){
          S[j][i] += hash[a[i][k]];
        }
      }
    }
  }
  vector<unsigned long long> SS;
  for (int i = 0; i < (1 << m); i++){
    for (int j = 0; j < n; j++){
      SS.push_back(S[i][j]);
    }
  }
  sort(SS.begin(), SS.end());
  SS.erase(unique(SS.begin(), SS.end()), SS.end());
  int cnt = SS.size();
  vector<vector<int>> id(1 << m, vector<int>(n));
  for (int i = 0; i < (1 << m); i++){
    for (int j = 0; j < n; j++){
      id[i][j] = lower_bound(SS.begin(), SS.end(), S[i][j]) - SS.begin();
    }
  }
  vector<int> tv(n, n + 1), fv(n, 0);
  while (true){
    vector<vector<int>> c(n + 1);
    bool ok = true;
    for (int i = 0; i < n; i++){
      if (tv[i] - fv[i] > 1){
        int mid = (tv[i] + fv[i]) / 2;
        c[mid].push_back(i);
        ok = false;
      }
    }
    if (ok){
      break;
    }
    vector<int> C(cnt, 0);
    for (int i = 0; i <= n; i++){
      for (int j : c[i]){
        int sum = 0;
        for (int k = 0; k < (1 << m); k++){
          if (__builtin_parity(k) == 0){
            sum += C[id[k][j]];
          } else {
            sum -= C[id[k][j]];
          }
        }
        if (sum > 0){
          tv[j] = i;
        } else {
          fv[j] = i;
        }
      }
      if (i < n){
        for (int j = 0; j < (1 << m); j++){
          C[id[j][i]]++;
        }
      }
    }
  }
  int ans = INF;
  for (int i = 0; i < n; i++){
    if (tv[i] <= n){
      ans = min(ans, w[i] + w[fv[i]]);
    }
  }
  if (ans == INF){
    cout << -1 << endl;
  } else {
    cout << ans << endl;
  }
}