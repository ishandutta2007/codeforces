#include <bits/stdc++.h>
using namespace std;
const int MAX = 20000000;
int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  vector<bool> prime(MAX + 1, true);
  for (int i = 2; i <= MAX; i++){
    if (prime[i]){
      for (int j = i * 2; j <= MAX; j += i){
        prime[j] = false;
      }
    }
  }
  vector<int> cnt(MAX + 1, 0);
  for (int i = 0; i < n; i++){
    cnt[a[i]]++;
  }
  for (int i = 2; i <= MAX; i++){
    if (prime[i]){
      for (int j = MAX / i; j >= 1; j--){
        cnt[j] += cnt[j * i];
      }
    }
  }
  vector<int> P;
  for (int i = 2; i <= MAX; i++){
    if (prime[i]){
      P.push_back(i);
    }
  }
  vector<long long> dp(MAX + 1, 0);
  for (int i = MAX; i >= 1; i--){
    dp[i] = (long long) cnt[i] * i;
    for (int j : P){
      if (i * j > MAX){
        break;
      }
      dp[i] = max(dp[i], dp[i * j] + (long long) (cnt[i] - cnt[i * j]) * i);
    }
  }
  cout << dp[1] << endl;
}