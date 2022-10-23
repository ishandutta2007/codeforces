#include <bits/stdc++.h>
using namespace std;
const long long MOD = 998244353;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int j = 0; j < n; j++){
      cin >> a[j];
    }
    vector<long long> inv(n + 1);
    inv[1] = 1;
    for (int j = 2; j <= n; j++){
      inv[j] = MOD - inv[MOD % j] * (MOD / j) % MOD;
    }
    vector<long long> fact(n + 1);
    vector<long long> finv(n + 1);
    fact[0] = 1;
    finv[0] = 1;
    for (int j = 1; j <= n; j++){
      fact[j] = fact[j - 1] * j % MOD;
      finv[j] = finv[j - 1] * inv[j] % MOD;
    }
    vector<long long> S(n + 1);
    S[0] = 0;
    for (int j = 0; j < n; j++){
      S[j + 1] = S[j] + a[j];
    }
    if (S[n] == 0){
      long long ans = 1;
      for (int j = 0; j < n - 1; j++){
        ans *= 2;
        ans %= MOD;
      }
      cout << ans << endl;
    } else {
      int cnt = 0;
      for (int j = 0; j <= n; j++){
        if (S[j] * 2 == S[n]){
          cnt++;
        }
      }
      map<long long, int> mp1, mp2;
      for (int j = 1; j < n; j++){
        if (S[j] * 2 < S[n]){
          mp1[S[j]]++;
        }
        if (S[j] * 2 > S[n]){
          mp2[S[n] - S[j]]++;
        }
      }
      long long ans = 1;
      for (auto P : mp1){
        long long x = P.first;
        int a = P.second;
        if (mp2.count(x) == 1){
          int b = mp2[x];
          long long c = fact[a + b] * finv[a] % MOD * finv[b] % MOD;
          ans *= c;
          ans %= MOD;
        }
      }
      for (int j = 0; j < cnt; j++){
        ans *= 2;
        ans %= MOD;
      }
      cout << ans << endl;
    }
  }
}