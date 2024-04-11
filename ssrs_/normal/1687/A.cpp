#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int j = 0; j < n; j++){
      cin >> a[j];
    }
    if (k <= n){
      vector<long long> S(n + 1);
      S[0] = 0;
      for (int j = 0; j < n; j++){
        S[j + 1] = S[j] + a[j];
      }
      long long ans = 0;
      for (int j = 0; j <= n - k; j++){
        long long sum = S[j + k] - S[j];
        sum += (long long) k * (k - 1) / 2;
        ans = max(ans, sum);
      }
      cout << ans << endl;
    } else {
      long long ans = 0;
      for (int j = 0; j < n; j++){
        ans += a[j];
        ans += k - j - 1;
      }
      cout << ans << endl;
    }
  }
}