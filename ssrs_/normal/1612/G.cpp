#include <bits/stdc++.h>
using namespace std;
const int MAX = 1000000;
const long long MOD = 1000000007;
const long long HALF = 500000004;
long long ap(long long a, long long b){
  return (b + a) % MOD * ((abs(b - a) + 1) % MOD) % MOD * HALF % MOD;
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int m;
  cin >> m;
  vector<int> c(m);
  for (int i = 0; i < m; i++){
    cin >> c[i];
  }
  vector<int> imos(MAX * 2 + 2, 0);
  for (int i = 0; i < m; i++){
    imos[1 - c[i] + MAX]++;
    imos[c[i] - 1 + 2 + MAX]--;
  }
  for (int i = 2; i < MAX * 2 + 2; i++){
    imos[i] += imos[i - 2];
  }
  long long S = 0;
  for (int i = 0; i < m; i++){
    S += c[i];
  }
  long long mx = 0;
  for (int i = MAX * 2 - 1; i >= 0; i--){
    if (imos[i] > 0){
      mx += ap(S, S - imos[i] + 1) * (i - MAX + MOD) % MOD;
      S -= imos[i];
    }
  }
  mx %= MOD;
  vector<long long> fact(m + 1);
  fact[0] = 1;
  for (int i = 1; i <= m; i++){
    fact[i] = fact[i - 1] * i % MOD;
  }
  long long ans = 1;
  for (int i = 0; i < MAX * 2; i++){
    ans *= fact[imos[i]];
    ans %= MOD;
  }
  cout << mx << ' ' << ans << endl;
}