#include <bits/stdc++.h>
using namespace std;
int main(){
  int T;
  cin >> T;
  for (int i = 0; i < T; i++){
    int n;
    cin >> n;
    string s;
    cin >> s;
    bool ok = false;
    string ans;
    for (int j = 0; j <= n - 7; j++){
      string t = s;
      for (int k = 0; k < 7; k++){
        if (t[j + k] == '?'){
          t[j + k] = "abacaba"[k];
        }
      }
      for (int k = 0; k < n; k++){
        if (t[k] == '?'){
          t[k] = 'z';
        }
      }
      int cnt = 0;
      for (int k = 0; k <= n - 7; k++){
        if (t.substr(k, 7) == "abacaba"){
          cnt++;
        }
      }
      if (cnt == 1){
        ok = true;
        ans = t;
      }
    }
    if (!ok){
      cout << "No" << endl;
    } else {
      cout << "Yes" << endl;
      cout << ans << endl;
    }
  }
}