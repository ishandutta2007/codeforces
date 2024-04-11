#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int dp[2000];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  dp[0] = 1;
  for(int i = 1; i < 2000; i++) {
    if(i >= 11)
      dp[i] |= dp[i - 11];
    if(i >= 111)
      dp[i] |= dp[i - 111];  
    if(i >= 1111)
      dp[i] |= dp[i - 1111];  
  }

  int t;
  cin >> t;
  while(t--) {
    int n;
    cin >> n;
    if(n >= 1500)
      cout << "YES\n";
    else
      cout << (dp[n] ? "YES" : "NO") << '\n';  
  }
}