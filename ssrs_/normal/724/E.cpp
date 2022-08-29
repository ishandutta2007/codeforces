#include <bits/stdc++.h>
using namespace std;
const long long INF = 1000000000000000000;
int main(){
  int n;
  long long c;
  cin >> n >> c;
  vector<long long> p(n);
  for (int i = 0; i < n; i++){
    cin >> p[i];
  }
  vector<long long> s(n);
  for (int i = 0; i < n; i++){
    cin >> s[i];
  }
  vector<long long> dp(1, 0);
  for (int i = 0; i < n; i++){
    vector<long long> dp2(i + 2, INF);
    for (int j = 0; j <= i; j++){
      dp2[j] = min(dp2[j], dp[j] + p[i] + c * j);
      dp2[j + 1] = min(dp2[j + 1], dp[j] + s[i]);
    }
    swap(dp, dp2);
  }
  long long ans = INF;
  for (int i = 0; i <= n; i++){
    ans = min(ans, dp[i]);
  }
  cout << ans << endl;
}