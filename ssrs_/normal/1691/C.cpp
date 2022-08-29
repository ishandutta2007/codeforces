#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> p;
    for (int j = 0; j < n; j++){
      if (s[j] == '1'){
        p.push_back(j);
      }
    }
    int cnt = p.size();
    int sum = 0;
    for (int j = 0; j < n - 1; j++){
      sum += (s[j] - '0') * 10 + (s[j + 1] - '0');
    }
    int ans = sum;
    if (p.size() == 0){
      cout << sum << endl;
    } else if (p.size() == 1){
      if (n - 1 - p[0] <= k){
        cout << 1 << endl;
      } else if (p[0] <= k){
        cout << 10 << endl;
      } else {
        cout << 11 << endl;
      }
    } else {
      int ans = sum;
      if (p[0] > 0 && p[0] <= k){
        ans = min(ans, sum - 1);
      }
      if (p[cnt - 1] < n - 1 && n - 1 - p[cnt - 1] <= k){
        ans = min(ans, sum - 10);
      }
      if (p[0] > 0 && p[cnt - 1] < n - 1 && p[0] + (n - 1 - p[cnt - 1]) <= k){
        ans = min(ans, sum - 11);
      }
      cout << ans << endl;
    }
  }
}