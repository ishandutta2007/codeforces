#include <bits/stdc++.h>
using namespace std;
const int MAX = 5000000;
int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  vector<int> f(MAX + 1, 0);
  for (int i = 0; i < n; i++){
    f[a[i]]++;
  }
  vector<int> cnt(MAX + 1, 0);
  for (int i = 1; i <= MAX; i++){
    for (int j = i; j <= MAX; j += i){
      cnt[i] += f[j];
    }
  }
  vector<long long> dp(MAX + 1, 0);
  for (int i = MAX; i >= 1; i--){
    dp[i] = (long long) cnt[i] * i;
    for (int j = i * 2; j <= MAX; j += i){
      dp[i] = max(dp[i], dp[j] + (long long) (cnt[i] - cnt[j]) * i);
    }
  }
  cout << dp[1] << endl;
}