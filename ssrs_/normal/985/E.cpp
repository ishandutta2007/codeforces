#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, k, d;
  cin >> n >> k >> d;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  vector<bool> dp(n + 1, false);
  dp[0] = true;
  vector<int> dpS(n + 2, 0);
  dpS[1] = 1;
  for (int i = 1; i <= n; i++){
    dpS[i + 1] = dpS[i];
    int L = lower_bound(a.begin(), a.end(), a[i - 1] - d) - a.begin();
    int R = i - k + 1;
    if (R >= 0){
      if (dpS[R] - dpS[L] > 0){
        dp[i] = true;
        dpS[i + 1]++;
      }
    }
  }
  if (dp[n]){
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}