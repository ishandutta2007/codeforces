#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<int> b(n);
    for (int j = 0; j < n; j++){
      cin >> b[j];
    }
    vector<long long> s(n + 1);
    s[0] = 0;
    for (int j = 0; j < n; j++){
      s[j + 1] = s[j] + b[j];
    }
    map<long long, long long> dp;
    dp[0] = 1;
    long long sum = 1;
    for (int j = 1; j < n; j++){
      long long next = sum;
      sum += MOD - dp[s[j]];
      sum += next;
      sum %= MOD;
      dp[s[j]] = next;
    }
    cout << sum << endl;
  }
}