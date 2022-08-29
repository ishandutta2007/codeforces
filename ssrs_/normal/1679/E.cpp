#include <bits/stdc++.h>
using namespace std;
const long long MOD = 998244353;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  string s;
  cin >> s;
  int Q = 0;
  for (int i = 0; i < n; i++){
    if (s[i] == '?'){
      Q++;
    }
  }
  vector<vector<long long>> POW(18, vector<long long>(Q + 1));
  for (int i = 0; i <= 17; i++){
    POW[i][0] = 1;
    for (int j = 0; j < Q; j++){
      POW[i][j + 1] = POW[i][j] * i % MOD;
    }
  }
  vector<vector<long long>> cnt(18, vector<long long>(1 << 17, 0));
  for (int i = 0; i < n; i++){
    int L = i, R = i + 1;
    int t = Q;
    int m = 0;
    for (int j = 0; j <= 17; j++){
      cnt[j][0] += POW[j][t];
      cnt[j][0] %= MOD;
    }
    while (L > 0 && R < n){
      L--;
      R++;
      if (s[L] != s[R - 1] && s[L] != '?' && s[R - 1] != '?'){
        break;
      }
      if (s[L] == '?' && s[R - 1] != '?'){
        t--;
        m |= 1 << (s[R - 1] - 'a');
      }
      if (s[R - 1] == '?' && s[L] != '?'){
        t--;
        m |= 1 << (s[L] - 'a');
      }
      if (s[L] == '?' && s[R - 1] == '?'){
        t--;
      }
      for (int j = 0; j <= 17; j++){
        cnt[j][m] += POW[j][t];
        cnt[j][m] %= MOD;
      }
    }
  }
  for (int i = 0; i < n - 1; i++){
    if (!(s[i] != s[i + 1] && s[i] != '?' && s[i + 1] != '?')){
      int L = i, R = i + 2;
      int t = Q;
      int m = 0;
      if (s[i] == '?' && s[i + 1] != '?'){
        t--;
        m |= 1 << (s[i + 1] - 'a'); 
      }
      if (s[i + 1] == '?' && s[i] != '?'){
        t--;
        m |= 1 << (s[i] - 'a');
      }
      if (s[i] == '?' && s[i + 1] == '?'){
        t--;
      }
      for (int j = 0; j <= 17; j++){
        cnt[j][m] += POW[j][t];
        cnt[j][m] %= MOD;
      }
      while (L > 0 && R < n){
        L--;
        R++;
        if (s[L] != s[R - 1] && s[L] != '?' && s[R - 1] != '?'){
          break;
        }
        if (s[L] == '?' && s[R - 1] != '?'){
          t--;
          m |= 1 << (s[R - 1] - 'a');
        }
        if (s[R - 1] == '?' && s[L] != '?'){
          t--;
          m |= 1 << (s[L] - 'a');
        }
        if (s[L] == '?' && s[R - 1] == '?'){
          t--;
        }
        for (int j = 0; j <= 17; j++){
          cnt[j][m] += POW[j][t];
          cnt[j][m] %= MOD;
        }
      }
    }
  }
  for (int i = 0; i < 18; i++){
    for (int j = 0; j < 17; j++){
      for (int k = 0; k < (1 << 17); k++){
        if ((k >> j & 1) == 1){
          cnt[i][k] += cnt[i][k - (1 << j)];
          cnt[i][k] %= MOD;
        }
      }
    }
  }
  int q;
  cin >> q;
  for (int i = 0; i < q; i++){
    string t;
    cin >> t;
    int L = t.size();
    int m = 0;
    for (int j = 0; j < L; j++){
      m |= 1 << (t[j] - 'a');
    }
    cout << cnt[L][m] << "\n";
  }
}