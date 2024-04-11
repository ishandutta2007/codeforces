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
    vector<int> cnt(1, 0);
    for (int j = 0; j < n; j++){
      if (s[j] == '0'){
        cnt.back()++;
      } else {
        cnt.push_back(0);
      }
    }
    int M = cnt.size();
    if (M == 1){
      cout << (n + k) / (k + 1) << endl;
    } else {
      int ans = 0;
      ans += cnt.front() / (k + 1);
      ans += cnt.back() / (k + 1);
      for (int j = 1; j < M - 1; j++){
        ans += max((cnt[j] - k) / (k + 1), 0);
      }
      cout << ans << endl;
    }
  }
}