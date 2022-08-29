#include <bits/stdc++.h>
using namespace std;
int INF = 1000000000;
int main(){
  int n;
  cin >> n;
  vector<int> t(n + 1);
  t[0] = -INF;
  for (int i = 1; i <= n; i++){
    cin >> t[i];
  }
  vector<long long> dp(n + 1, INF);
  dp[0] = 0;
  for (int i = 1; i <= n; i++){
    dp[i] = min(dp[i], dp[i - 1] + 20);
    auto itr1 = upper_bound(t.begin(), t.end(), t[i] - 90) - 1;
    dp[i] = min(dp[i], dp[itr1 - t.begin()] + 50);
    auto itr2 = upper_bound(t.begin(), t.end(), t[i] - 1440) - 1;
    dp[i] = min(dp[i], dp[itr2 - t.begin()] + 120);
    cout << dp[i] - dp[i - 1] << endl;
  }
}