#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
int main(){
  int n;
  cin >> n;
  vector<long long> S(n - 1, 0);
  for (int i = 1; i < n - 1; i++){
    for (int j = i; i + j + 1 <= n; j += i){
      int cnt = (n - j - 1) / i;
      S[i] += (long long) (n - j) * cnt - (long long) cnt * (cnt + 1) / 2 * i;
      S[i] %= MOD;
    }
  }
  for (int i = n - 2; i >= 1; i--){
    for (int j = i * 2; j < n - 1; j += i){
      S[i] += MOD - S[j];
      S[i] %= MOD;
    }
  }
  long long ans = 0;
  for (int i = 1; i < n - 1; i++){
    ans += i / gcd(n, i) * S[i];
    ans %= MOD;
  }
  cout << ans << endl;
}