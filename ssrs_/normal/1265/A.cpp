#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    string s;
    cin >> s;
    int n = s.size();
    bool ok = true;
    for (int j = 0; j < n - 1; j++){
      if (s[j] == s[j + 1] && s[j] != '?'){
        ok = false;
      }
    }
    if (!ok){
      cout << -1 << endl;
    } else {
      for (int j = 0; j < n; j++){
        if (s[j] == '?'){
          for (int k = 0; k < 3; k++){
            s[j] = 'a' + k;
            bool ok2 = true;
            if (j > 0){
              if (s[j - 1] == s[j]){
                ok2 = false;
              }
            }
            if (j < n - 1){
              if (s[j] == s[j + 1]){
                ok2 = false;
              }
            }
            if (ok2){
              break;
            }
          }
        }
      }
      cout << s << endl;
    }
  }
}