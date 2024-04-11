#include <bits/stdc++.h>
using namespace std;
const int INF = 10000;
int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  vector<int> dp(1024, INF);
  dp[0] = -1;
  for (int i = 0; i < n; i++){
    for (int j = 0; j < 1024; j++){
      if (dp[j] < a[i]){
        int j2 = j ^ a[i];
        dp[j2] = min(dp[j2], a[i]);
      }
    }
  }
  vector<int> x;
  for (int i = 0; i < 1024; i++){
    if (dp[i] != INF){
      x.push_back(i);
    }
  }
  int k = x.size();
  cout << k << endl;
  for (int i = 0; i < k; i++){
    cout << x[i];
    if (i < k - 1){
      cout << ' ';
    }
  }
  cout << endl;
}