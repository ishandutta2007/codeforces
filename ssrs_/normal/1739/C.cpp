#include <bits/stdc++.h>
using namespace std;
const long long MOD = 998244353;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<vector<long long>> binom(n + 1, vector<long long>(n + 1, 0));
    for (int j = 0; j <= n; j++){
      binom[j][0] = 1;
      for (int k = 1; k < j; k++){
        binom[j][k] = (binom[j - 1][k - 1] + binom[j - 1][k]) % MOD;
      }
      binom[j][j] = 1;
    }
    long long a = 0, b = 0;
    for (int j = 0; j < n / 2; j++){
      if (j % 2 == 0){
        a += binom[n - j * 2 - 1][n / 2 - j];
        b += binom[n - j * 2 - 2][n / 2 - j];
      } else {
        b += binom[n - j * 2 - 1][n / 2 - j];
        a += binom[n - j * 2 - 2][n / 2 - j];
      }
    }
    a %= MOD;
    b %= MOD;
    cout << a << ' ' << b << ' ' << 1 << endl;
  }
}