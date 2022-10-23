#include <bits/stdc++.h>
using namespace std;
const long long MOD = 998244353;
int main(){
  int n;
  long long m;
  cin >> n >> m;
  vector<long long> POW(n + 1);
  POW[0] = 1;
  for (int i = 0; i < n; i++){
    POW[i + 1] = POW[i] * (m % MOD) % MOD;
  }
  vector<bool> pr(n + 1, true);
  for (int i = 2; i <= n; i++){
    if (pr[i]){
      for (int j = i * 2; j <= n; j += i){
        pr[j] = false;
      }
    }
  }
  long long ans = 0;
  for (int i = 1; i <= n; i++){
    ans += POW[i];
  }
  ans %= MOD;
  long long P = 1;
  long long L = 1;
  for (int i = 1; i <= n; i++){
    if (pr[i]){
      L *= i;
      if (L > m){
        break;
      }
    }
    P *= m / L % MOD;
    P %= MOD;
    ans += MOD - P;
  }
  ans %= MOD;
  cout << ans << endl;
}