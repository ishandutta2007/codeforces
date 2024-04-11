#include <bits/stdc++.h>
using namespace std;
const int MAX = 1000000;
const long long MOD = 1000000007;
int main(){
  vector<int> phi(MAX + 1, 0);
  for (int i = 1; i <= MAX; i++){
    phi[i] = i;
  }
  for (int i = 2; i <= MAX; i++){
    if (phi[i] == i){
      for (int j = i; j <= MAX; j += i){
        phi[j] = phi[j] / i * (i - 1);
      }
    }
  }
  vector<long long> g(MAX + 1, 0);
  for (int i = 1; i <= MAX; i++){
    for (int j = i; j <= MAX; j += i){
      g[j] += (long long) (j / i) * phi[i];
      g[j] %= MOD;
    }
  }
  vector<long long> f(MAX + 1, 0);
  for (long long i = 1; i <= MAX; i++){
    f[i] = (i * (i - 1) * (2 * i - 1) / 3 - i * i * (i - 1) % MOD + i * i * (i - 2) + 2 * g[i] + MOD) % MOD;
  }
  vector<long long> sum0(MAX + 1, 0), sum1(MAX + 1, 0), sum2(MAX + 1, 0);
  for (int i = 1; i <= MAX; i++){
    sum0[i] = (sum0[i - 1] + f[i]) % MOD;
    sum1[i] = (sum1[i - 1] + f[i] * i) % MOD;
    sum2[i] = (sum2[i - 1] + f[i] * i % MOD * i) % MOD;
  }
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, m;
    cin >> n >> m;
    int k = min(n, m);
    cout << (sum2[k] - sum1[k] * (n + m + 2) % MOD + sum0[k] * (n + 1) % MOD * (m + 1) % MOD + MOD) % MOD << "\n";
  }
}