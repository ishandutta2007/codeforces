#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    string s;
    cin >> s;
    if (n == 1){
      cout << s[0] << s[0] << endl;
    } else if (s[0] <= s[1]){
      cout << s[0] << s[0] << endl;
    } else {
      int p = 0;
      while (p < n - 1){
        if (s[p] >= s[p + 1]){
          p++;
        } else {
          break;
        }
      }
      string ans;
      for (int j = 0; j <= p; j++){
        ans += s[j];
      }
      for (int j = p; j >= 0; j--){
        ans += s[j];
      }
      cout << ans << endl;
    }
  }
}