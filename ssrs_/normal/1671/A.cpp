#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    string s;
    cin >> s;
    int n = s.size();
    if (n == 1){
      cout << "NO" << endl;
    } else {
      bool ok = true;
      if (s[0] != s[1]){
        ok = false;
      }
      for (int i = 1; i < n - 1; i++){
        if (s[i - 1] != s[i] && s[i] != s[i + 1]){
          ok = false;
        }
      }
      if (s[n - 2] != s[n - 1]){
        ok = false;
      }
      if (ok){
        cout << "YES" << endl;
      } else {
        cout << "NO" << endl;
      }
    }
  }
}