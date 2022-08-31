#include <bits/stdc++.h>
using namespace std;
int INF = 100000000;
int main(){
  int n;
  cin >> n;
  vector<pair<int, int>> P(n);
  for (int i = 0; i < n; i++){
    int a, b;
    cin >> a >> b;
    P[i] = make_pair(a, b);
  }
  sort(P.begin(), P.end());
  vector<int> prev(n, -1);
  for (int i = 1; i < n; i++){
    int a = P[i].first;
    int b = P[i].second;
    auto itr = lower_bound(P.begin(), P.end(), make_pair(a - b, -INF));
    if (itr != P.begin()){
      prev[i] = itr - P.begin() - 1;
    }
  }
  vector<int> dp(n);
  for (int i = 0; i < n; i++){
    if (prev[i] == -1){
      dp[i] = 1;
    } else {
      dp[i] = dp[prev[i]] + 1;
    }
  }
  int mx = 0;
  for (int i = 0; i < n; i++){
    mx = max(mx, dp[i]);
  }
  cout << n - mx << endl;
}