#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, k;
    cin >> n >> k;
    vector<int> x(n);
    for (int j = 0; j < n; j++){
      cin >> x[j];
    }
    vector<int> y(n);
    for (int j = 0; j < n; j++){
      cin >> y[j];
    }
    sort(x.begin(), x.end());
    vector<int> dp1(n);
    for (int j = 0; j < n; j++){
      dp1[j] = j + 1 - (lower_bound(x.begin(), x.end(), x[j] - k) - x.begin());
    }
    vector<int> dp2 = dp1;
    for (int j = 0; j < n - 1; j++){
      dp2[j + 1] = max(dp2[j + 1], dp2[j]);
    }
    vector<int> dp3(n);
    for (int j = 0; j < n; j++){
      int p = lower_bound(x.begin(), x.end(), x[j] - k) - x.begin();
      if (p == 0){
        dp3[j] = dp1[j];
      } else {
        dp3[j] = dp1[j] + dp2[p - 1];
      }
    }
    int ans = 0;
    for (int j = 0; j < n; j++){
      ans = max(ans, dp3[j]);
    }
    cout << ans << endl;
  }
}