#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int ans = 0;
    for (int j = 0; j < 30; j++){
      cout << "? " << (1 << j) - ans << ' ' << (3 << j) - ans << endl;
      int g;
      cin >> g;
      if ((g >> j & 1) == 0){
        ans += 1 << j;
      }
    }
    cout << "! " << ans << endl;
  }
}