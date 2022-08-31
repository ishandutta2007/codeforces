#include <bits/stdc++.h>
using namespace std;
int main(){
  vector<bool> dp(1000001, false);
  dp[0] = true;
  for (int i = 2020; i <= 2021; i++){
    for (int j = i; j <= 1000000; j++){
      if (dp[j - i]){
        dp[j] = true;
      }
    }
  }
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    if (dp[n]){
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}