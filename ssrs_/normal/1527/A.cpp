#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    if (n == 1){
      cout << 0 << endl;
    } else {
      int ans = 1;
      while (true){
        int tmp = ans * 2 + 1;
        if (tmp < n){
          ans = tmp;
        } else {
          break;
        }
      }
      cout << ans << endl;
    }
  }
}