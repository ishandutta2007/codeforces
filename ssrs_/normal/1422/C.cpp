#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
int main(){
  string s;
  cin >> s;
  int N = s.size();
  vector<long long> ten(N);
  ten[0] = 1;
  for (int i = 1; i < N; i++){
    ten[i] = ten[i - 1] * 10 % MOD;
  }
  vector<long long> sum(N);
  sum[0] = 0;
  for (int i = 0; i < N - 1; i++){
    sum[i + 1] = (sum[i] + ten[i] * (i + 1)) % MOD;
  }
  long long ans = 0;
  for (int i = 0; i < N; i++){
    int d = s[i] - '0';
    ans += (long long) i * (i + 1) / 2 % MOD * d % MOD * ten[N - 1 - i] % MOD;
    ans += d * sum[N - 1 - i] % MOD;
    ans %= MOD;
  }
  cout << ans << endl;
}