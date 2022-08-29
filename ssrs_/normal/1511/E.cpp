#include <bits/stdc++.h>
using namespace std;
const int MAX = 310000;
const long long MOD = 998244353;
int main(){
  int n, m;
  cin >> n >> m;
  vector<vector<char>> S(n, vector<char>(m, '*'));
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      cin >> S[i][j];
    }
  }
  int w = 0;
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      if (S[i][j] == 'o'){
        w++;
      }
    }
  }
  vector<long long> p1(MAX + 1, 1);
  vector<long long> p2(MAX + 1, 1);
  for (int i = 0; i < MAX; i++){
    p1[i + 1] = p1[i] * 2 % MOD;
    p2[i + 1] = p2[i] * 499122177 % MOD;
  }
  vector<long long> cnt(MAX, 0);
  cnt[0] = p2[2];
  cnt[1] = p2[3];
  for (int i = 2; i < MAX; i++){
    cnt[i] = (cnt[i - 1 - i % 2] + p2[i + 2]) % MOD;
  }
  vector<long long> sum(MAX + 1, 0);
  for (int i = 0; i < MAX; i++){
    sum[i + 1] = sum[i] + cnt[i];
    sum[i + 1] %= MOD;
  }
  vector<long long> t(MAX + 1, 0);
  for (int i = 1; i < MAX; i++){
    t[i] = sum[i - 1] * p1[i] % MOD;
  }
  long long ans = 0;
  for (int i = 0; i < 2; i++){
    for (int j = 0; j < n; j++){
      vector<pair<char, int>> rle;
      rle.push_back(make_pair(S[j][0], 1));
      for (int k = 1; k < m; k++){
        if (S[j][k] == S[j][k - 1]){
          rle.back().second++;
        } else {
          rle.push_back(make_pair(S[j][k], 1));
        }
      }
      int cnt = rle.size();
      for (int k = 0; k < cnt; k++){
        if (rle[k].first == 'o'){
          int l = rle[k].second;
          ans += t[l] * p1[w - l] % MOD;
          ans %= MOD;
        }
      }
    }
    vector<vector<char>> S2(m, vector<char>(n));
    for (int j = 0; j < n; j++){
      for (int k = 0; k < m; k++){
        S2[k][j] = S[j][k];
      }
    }
    swap(S, S2);
    swap(n, m);
  }
  cout << ans << endl;
}