#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int x;
    cin >> x;
    int ans = 0;
    bool ok = false;
    for (int j = 1; j <= 9; j++){
      string s;
      for (int k = 1; k <= 4; k++){
        s += '0' + j;
        ans += k;
        if (stoi(s) == x){
          ok = true;
          break;
        }
      }
      if (ok){
        break;
      }
    }
    cout << ans << endl;
  }
}