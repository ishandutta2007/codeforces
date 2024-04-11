#include <bits/stdc++.h>
using namespace std;
const int MAX = 40000;
const long long MOD = 1000000007;
int main(){
  vector<int> P;
  for (int i = 1; i <= 9; i++){
    P.push_back(i);
  }
  for (int i = 1; i <= 9; i++){
    P.push_back(i * 10 + i);
  }
  for (int i = 1; i <= 9; i++){
    for (int j = 0; j <= 9; j++){
      P.push_back(i * 100 + j * 10 + i);
    }
  }
  for (int i = 1; i <= 9; i++){
    for (int j = 0; j <= 9; j++){
      P.push_back(i * 1000 + j * 100 + j * 10 + i);
    }
  }
  for (int i = 1; i <= 9; i++){
    for (int j = 0; j <= 9; j++){
      for (int k = 0; k <= 9; k++){
        P.push_back(i * 10000 + j * 1000 + k * 100 + j * 10 + i);
      }
    }
  }
  int cnt = P.size();
  vector<long long> dp(MAX + 1, 0);
  dp[0] = 1;
  for (int i = 0; i < cnt; i++){
    for (int j = 0; j <= MAX - P[i]; j++){
      dp[j + P[i]] += dp[j];
      dp[j + P[i]] %= MOD;
    }
  }
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    cout << dp[n] << endl;
  }  
}