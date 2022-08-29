#include <bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    string s;
    cin >> s;
    bool ok2 = false;
    for (int j = 0; j <= n - 2; j++){
      if (s.substr(j, 2) == "aa"){
        ok2 = true;
      }
    }
    if (ok2){
      cout << 2 << endl;
    } else {
      bool ok3 = false;
      for (int j = 0; j <= n - 3; j++){
        if (s.substr(j, 3) == "aba" || s.substr(j, 3) == "aca"){
          ok3 = true;
        }
      }
      if (ok3){
        cout << 3 << endl;
      } else {
        bool ok4 = false;
        for (int j = 0; j <= n - 4; j++){
          if (s.substr(j, 4) == "abca" || s.substr(j, 4) == "acba"){
            ok4 = true;
          }
        }
        if (ok4){
          cout << 4 << endl;
        } else {
          bool ok7 = false;
          for (int j = 0; j <= n - 7; j++){
            if (s.substr(j, 7) == "abbacca" || s.substr(j, 7) == "accabba"){
              ok7 = true;
            }
          }
          if (ok7){
            cout << 7 << endl;
          } else {
            cout << -1 << endl;
          }
        }
      }
    }
  }
}