#include <bits/stdc++.h>
using namespace std;
const long long BASE = 1234567;
const long long MOD = 998244353;
long long modpow(long long a, long long b){
  long long ans = 1;
  while (b > 0){
    if (b % 2 == 1){
      ans *= a;
      ans %= MOD;
    }
    a *= a;
    a %= MOD;
    b /= 2;
  }
  return ans;
}
long long modinv(long long a){
  return modpow(a, MOD - 2);
}
int main(){
  int n, m;
  cin >> n >> m;
  string s;
  cin >> s;
  vector<long long> POW(n + 1);
  POW[0] = 1;
  for (int i = 0; i < n; i++){
    POW[i + 1] = POW[i] * BASE % MOD;
  }
  vector<long long> INV(n + 1);
  INV[0] = 1;
  INV[1] = modinv(BASE);
  for (int i = 2; i <= n; i++){
    INV[i] = INV[i - 1] * INV[1] % MOD;
  }
  vector<vector<long long>> sum(26, vector<long long>(n + 1, 0));
  for (int i = 0; i < n; i++){
    for (int j = 0; j < 26; j++){
      sum[j][i + 1] = sum[j][i];
    }
    int id = s[i] - 'a';
    sum[id][i + 1] += POW[i];
    sum[id][i + 1] %= MOD;
  }
  for (int i = 0; i < m; i++){
    int x, y, len;
    cin >> x >> y >> len;
    x--;
    y--;
    vector<long long> a(26);
    for (int j = 0; j < 26; j++){
      a[j] = sum[j][x + len] - sum[j][x] + MOD;
      a[j] %= MOD;
      a[j] *= INV[x];
      a[j] %= MOD;
    }
    vector<long long> b(26);
    for (int j = 0; j < 26; j++){
      b[j] = sum[j][y + len] - sum[j][y] + MOD;
      b[j] %= MOD;
      b[j] *=INV[y];
      b[j] %= MOD;
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    if (a == b){
      cout << "YES" << "\n";
    } else {
      cout << "NO" << "\n";
    }
  }
}