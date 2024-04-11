#include <bits/stdc++.h>
using namespace std;
const int B = 300;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m, q;
  cin >> n >> m >> q;
  vector<long long> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  vector<vector<int>> S(m);
  for (int i = 0; i < m; i++){
    int k;
    cin >> k;
    S[i] = vector<int>(k);
    for (int j = 0; j < k; j++){
      cin >> S[i][j];
      S[i][j]--;
    }
  }
  vector<long long> sum(m, 0);
  for (int i = 0; i < m; i++){
    int k = S[i].size();
    for (int j = 0; j < k; j++){
      sum[i] += a[S[i][j]];
    }
  }
  vector<vector<int>> T(n);
  for (int i = 0; i < m; i++){
    int k = S[i].size();
    for (int j = 0; j < k; j++){
      T[S[i][j]].push_back(i);
    }
  }
  vector<map<int, int>> mp(m);
  for (int i = 0; i < n; i++){
    int cnt = T[i].size();
    vector<int> T2;
    for (int j = 0; j < cnt; j++){
      if (S[T[i][j]].size() >= B){
        T2.push_back(T[i][j]);
      }
    }
    int cnt2 = T2.size();
    for (int j = 0; j < cnt2; j++){
      for (int k = 0; k < cnt; k++){
        mp[T[i][k]][T2[j]]++;
      }
    }
  }
  vector<vector<pair<int, int>>> E(m);
  for (int i = 0; i < m; i++){
    for (auto P : mp[i]){
      E[i].push_back(P);
    }
  }
  vector<long long> add1(n, 0), add2(m, 0), add3(m, 0);
  for (int i = 0; i < q; i++){
    char c;
    cin >> c;
    if (c == '?'){
      int k;
      cin >> k;
      k--;
      long long ans = sum[k];
      if (S[k].size() < B){
        for (int j : S[k]){
          ans += add1[j];
        }
        for (auto P : E[k]){
          ans += add2[P.first] * P.second;
        }
      } else {
        ans += add3[k];
      }
      cout << ans << "\n";
    }
    if (c == '+'){
      int k;
      long long x;
      cin >> k >> x;
      k--;
      if (S[k].size() < B){
        for (int j : S[k]){
          add1[j] += x;
        }
      } else {
        add2[k] += x;
      }
      for (auto P : E[k]){
        add3[P.first] += P.second * x;
      }
    }
  }
}