#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    string s;
    cin >> s;
    int ans = 10;
    for (int j = 0; j < (1 << 10); j++){
      bool ok = true;
      for (int k = 0; k < 10; k++){
        if (s[k] == '0' && (j >> k & 1) == 1){
          ok = false;
        }
        if (s[k] == '1' && (j >> k & 1) == 0){
          ok = false;
        }
      }
      if (ok){
        int c1 = 0, c2 = 0;
        int r1 = 5, r2 = 5;
        for (int k = 0; k < 10; k++){
          if ((j >> k & 1) == 1){
            if (k % 2 == 0){
              c1++;
            } else {
              c2++;
            }
          }
          if (k % 2 == 0){
            r1--;
          } else {
            r2--;
          }
          if (c1 + r1 < c2 || c2 + r2 < c1){
            ans = min(ans, k + 1);
          }
        }
      }
    }
    cout << ans << endl;
  }
}