#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    string s;
    cin >> s;
    int n = s.size();
    bool ok = false;
    for (int j = 0; j < 8; j++){
      int sum = 0;
      bool ok2 = true;
      for (int k = 0; k < n; k++){
        int c = s[k] - 'A';
        if ((j >> c & 1) == 1){
          sum++;
        } else {
          sum--;
          if (sum < 0){
            ok2 = false;
          }
        }
      }
      if (sum != 0){
        ok2 = false;
      }
      if (ok2){
        ok = true;
      }
    }
    if (ok){
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}