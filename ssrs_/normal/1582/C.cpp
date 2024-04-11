#include <bits/stdc++.h>
using namespace std;
const int INF = 10000000;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = INF;
    for (int j = 0; j < 26; j++){
      char c = 'a' + j;
      string s2;
      vector<int> cnt(1, 0);
      for (int k = 0; k < n; k++){
        if (s[k] == c){
          cnt.back()++;
        } else {
          s2 += s[k];
          cnt.push_back(0);
        }
      }
      string s3 = s2;
      reverse(s3.begin(), s3.end());
      if (s2 == s3){
        int sz = cnt.size();
        int sum = 0;
        for (int k = 0; k < sz / 2; k++){
          sum += abs(cnt[k] - cnt[sz - 1 - k]);
        }
        ans = min(ans, sum);
      }
    }
    if (ans == INF){
      cout << -1 << endl;
    } else {
      cout << ans << endl;
    }
 }
}