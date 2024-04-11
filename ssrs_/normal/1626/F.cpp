#include <bits/stdc++.h>
using namespace std;
const int LCM = 12252240;
const long long MOD = 998244353;
int main(){
  int n;
  long long a0, x, y;
  int k;
  long long M;
  cin >> n >> a0 >> x >> y >> k >> M;
  vector<long long> a(n);
  a[0] = a0;
  for (int i = 1; i < n; i++){
    a[i] = (a[i - 1] * x + y) % M;
  }
  long long A = k;
  for (int i = 0; i < k - 1; i++){
    A = A * n % MOD;
  }
  vector<long long> dp(LCM, 0);
  long long MUL = 1;
  for (int i = k; i >= 1; i--){
    vector<long long> dp2(LCM, 0);
    for (int j = 0; j < LCM; j++){
      int j2 = j - j % i;
      dp2[j] += dp[j] * (n - 1);
      dp2[j] += dp[j2] + j * MUL;
      dp2[j] %= MOD;
    }
    swap(dp, dp2);
    MUL *= n;
    MUL %= MOD;
  }
  long long ans = 0;
  for (int i = 0; i < n; i++){
    int q = a[i] / LCM;
    int r = a[i] % LCM;
    ans += q * LCM * A + dp[r];
    ans %= MOD;
  }
  cout << ans << endl;
}