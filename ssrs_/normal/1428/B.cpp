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
    bool l = false, r = false;
    for (int j = 0; j < n; j++){
      if (s[j] == '<'){
        l = true;
      }
      if (s[j] == '>'){
        r = true;
      }
    }
    if (!(l && r)){
      cout << n << endl;
    } else {
      int ans = 0;
      for (int j = 0; j < n; j++){
        char c1 = s[j];
        char c2 = s[(j + 1) % n];
        if (c1 == '-' || c2 == '-'){
          ans++;
        }
      }
      cout << ans << endl;
    }
  }
}