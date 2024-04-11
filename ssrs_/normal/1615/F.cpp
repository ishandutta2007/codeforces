#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
int main(){
  vector<vector<long long>> binom(4001, vector<long long>(4001, 0));
  for (int i = 0; i <= 4000; i++){
    binom[i][0] = 1;
    for (int j = 1; j < i; j++){
      binom[i][j] = (binom[i - 1][j - 1] + binom[i - 1][j]) % MOD;
    }
    binom[i][i] = 1;
  }
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    string s;
    cin >> s;
    string t;
    cin >> t;
    for (int j = 1; j < n; j += 2){
      if (s[j] == '0'){
        s[j] = '1';
      } else if (s[j] == '1'){
        s[j] = '0';
      }
      if (t[j] == '0'){
        t[j] = '1';
      } else if (t[j] == '1'){
        t[j] = '0';
      }
    }
    vector<int> L11(n + 1), L1q(n + 1);
    vector<int> L21(n + 1), L2q(n + 1);
    L11[0] = 0;
    L1q[0] = 0;
    L21[0] = 0;
    L2q[0] = 0;
    for (int j = 0; j < n; j++){
      L11[j + 1] = L11[j];
      L1q[j + 1] = L1q[j];
      L21[j + 1] = L21[j];
      L2q[j + 1] = L2q[j];
      if (s[j] == '1'){
        L11[j + 1]++;
      }
      if (s[j] == '?'){
        L1q[j + 1]++;
      }
      if (t[j] == '1'){
        L21[j + 1]++;
      }
      if (t[j] == '?'){
        L2q[j + 1]++;
      }
    }
    vector<int> R11(n + 1), R1q(n + 1);
    vector<int> R21(n + 1), R2q(n + 1);
    R11[n] = 0;
    R1q[n] = 0;
    R21[n] = 0;
    R2q[n] = 0;
    for (int j = n - 1; j >= 0; j--){
      R11[j] = R11[j + 1];
      R1q[j] = R1q[j + 1];
      R21[j] = R21[j + 1];
      R2q[j] = R2q[j + 1];
      if (s[j] == '1'){
        R11[j]++;
      }
      if (s[j] == '?'){
        R1q[j]++;
      }
      if (t[j] == '1'){
        R21[j]++;
      }
      if (t[j] == '?'){
        R2q[j]++;
      }
    }
    long long ans = 0;
    for (int j = 0; j < n; j++){
      for (int k = 0; k < n; k++){
        if (s[j] != '0' && t[k] != '0'){
          long long add = abs(k - j);
          int Lx = L1q[j] + L2q[k];
          int Ly = L21[k] + L2q[k] - L11[j];
          if (Ly < 0 || Ly > Lx){
            add = 0;
          } else {
            add *= binom[Lx][Ly];
            add %= MOD;
          }
          int Rx = R1q[j + 1] + R2q[k + 1];
          int Ry = R21[k + 1] + R2q[k + 1] - R11[j + 1];
          if (Ry < 0 || Ry > Rx){
            add = 0;
          } else {
            add *= binom[Rx][Ry];
            add %= MOD;
          }
          ans += add;
        }
      }
    }
    ans %= MOD;
    cout << ans << "\n";
  }
}