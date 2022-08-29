#include <bits/stdc++.h>
using namespace std;
const long long MOD = 998244353;
int main(){
  string n;
  cin >> n;
  int L = n.size();
  vector<vector<long long>> dp(64, vector<long long>(L + 1, 0));
  dp[0][0] = 1;
  for (int i = 0; i < L; i++){
    for (int j = 0; j < 64; j++){
      if (dp[j][i] > 0){
        for (int a = 0; a < 2; a++){
          for (int b = 0; b < 2; b++){
            for (int c = 0; c < 2; c++){
              bool ok = true;
              int j2 = j;
              if ((j & 1) == 0 && n[i] == '0' && a == 1){
                ok = false;
              } else if (n[i] == '1' && a == 0){
                j2 |= 1;
              }
              if ((j & 2) == 0 && n[i] == '0' && b == 1){
                ok = false;
              } else if (n[i] == '1' && b == 0){
                j2 |= 2;
              }
              if ((j & 4) == 0 && n[i] == '0' && c == 1){
                ok = false;
              } else if (n[i] == '1' && c == 0){
                j2 |= 4;
              }
              if ((j & 8) == 0 && (a ^ b) > (b ^ c)){
                ok = false;
              } else if ((a ^ b) < (b ^ c)){
                j2 |= 8;
              }
              if ((j & 16) == 0 && (b ^ c) > (c ^ a)){
                ok = false;
              } else if ((b ^ c) < (c ^ a)){
                j2 |= 16;
              }
              if (a == 0 && b == 1 && c == 0 || a == 1 && b == 0 && c== 1){
                j2 |= 32;
              }
              if (ok){
                dp[j2][i + 1] += dp[j][i];
                dp[j2][i] %= MOD;
              }
            }
          }
        }
      }
    }
  }
  long long ans = 0;
  for (int i = 56; i < 64; i++){
    ans += dp[i][L];
  }
  ans *= 6;
  ans %= MOD;
  cout << ans << endl;
}