#include <bits/stdc++.h>
using namespace std;
const long long MOD = 998244353;
int main(){
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  vector<vector<long long>> binom(n + 1, vector<long long>(n + 1, 0));
  for (int i = 0; i <= n; i++){
    binom[i][0] = 1;
    for (int j = 1; j < i; j++){
      binom[i][j] = binom[i - 1][j - 1] + binom[i - 1][j];
      if (binom[i][j] >= MOD){
        binom[i][j] -= MOD;
      }
    }
    binom[i][i] = 1;
  }
  int cnt = 0;
  for (int i = 0; i < n; i++){
    if (s[i] == '1'){
      cnt++;
    }
  }
  if (cnt < k){
    cout << 1 << endl;
  } else {
    long long ans = 0;
    for (int i = 0; i < n; i++){
      int cnt0 = 0, cnt1 = 0;
      for (int j = i; j < n; j++){
        if (cnt1 == k && s[j] == '1'){
          break;
        }
        if (s[j] == '0'){
          cnt0++;
        }
        if (s[j] == '1'){
          cnt1++;
        }
      }
      if (s[i] == '0' && cnt1 >= 1){
        ans += binom[cnt0 + cnt1 - 1][cnt0];
      }
      if (s[i] == '1' && cnt0 >= 1){
        ans += binom[cnt0 + cnt1 - 1][cnt1];
      }
    }
    ans++;
    ans %= MOD;
    cout << ans << endl;
  }
}