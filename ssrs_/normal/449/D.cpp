#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  vector<int> cnt(1 << 20, 0);
  for (int i = 0; i < n; i++){
    cnt[a[i]]++;
  }
  for (int i = 0; i < 20; i++){
    for (int j = 0; j < (1 << 20); j++){
      if (j >> i & 1){
        cnt[j - (1 << i)] += cnt[j];
      }
    }
  }
  vector<long long> P(n + 1);
  P[0] = 1;
  for (int i = 0; i < n; i++){
    P[i + 1] = P[i] * 2 % MOD;
  }
  long long ans = 0;
  for (int i = 0; i < (1 << 20); i++){
    long long add = P[cnt[i]];
    if (__builtin_parity(i) == 0){
      ans += add;
    } else {
      ans += MOD - add;
    }
    ans %= MOD;
  }
  cout << ans << endl;
}