#include <bits/stdc++.h>
using namespace std;
string mult(char C, int k){
  string ans = "";
  for (int i = 0; i < k; i++){
    ans += C;
  }
  return ans;
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    vector<int> count(26, 0);
    for (int j = 0; j < n; j++){
      count[s[j] - 'a']++;
    }
    int X = 0;
    for (int j = 0; j < 26; j++){
      if (count[j] > 0){
        X++;
      }
    }
    if (X == 1){
      cout << mult(s[0], (n + k - 1) / k) << endl;
    } else if (s[0] != s[k - 1]){
      cout << s[k - 1] << endl;
    } else if (X == 2 && count[s[0] - 'a'] == k){
      string ans;
      ans += s[0];
      ans += mult(s[n - 1], (count[s[n - 1] - 'a'] + k - 1) / k);
      cout << ans << endl;
    } else {
      string ans;
      ans += mult(s[0], count[s[0] - 'a'] - k + 1);
      ans += s.substr(count[s[0] - 'a']);
      cout << ans << endl;
    }
  }
}