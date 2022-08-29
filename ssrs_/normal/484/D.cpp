#include <bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  if (n == 1){
    cout << 0 << endl;
    return 0;
  }
  vector<int> b;
  b.push_back(a[0]);
  b.push_back(a[1]);
  for (int i = 2; i < n; i++){
    if (!(a[i - 2] == a[i - 1] && a[i - 1] == a[i])){
      b.push_back(a[i]);
    }
  }
  int m = b.size();
  if (m == 0){
    cout << 0 << endl;
    return 0;
  }
  vector<long long> dp(m + 1, 0);
  vector<int> l;
  l.push_back(0);
  bool up = false, down = false;
  for (int i = 1; i < m; i++){
    if (b[i] > b[i - 1]){
      if (down){
        l.clear();
        l.push_back(i - 1);
        l.push_back(i);
      }
      up = true;
      down = false;
    } else if (b[i] < b[i - 1]){
      if (up){
        l.clear();
        l.push_back(i - 1);
        l.push_back(i);
      }
      down = true;
      up = false;
    }
    dp[i + 1] = dp[i];
    for (int x : l){
      dp[i + 1] = max(dp[i + 1], dp[x] + abs(b[i] - b[x]));
    }
  }
  cout << dp[m] << endl;
}