#include <bits/stdc++.h>
using namespace std;
int main(){
  int q;
  cin >> q;
  for (int i = 0; i < q; i++){
    int u, v;
    cin >> u >> v;
    if (u > v){
      cout << "NO" << "\n";
    } else {
      bool ok = true;
      int cnt = 0;
      for (int j = 0; j < 30; j++){
        if ((u >> j & 1) == 1){
          cnt++;
        }
        if ((v >> j & 1) == 1){
          if (cnt == 0){
            ok = false;
            break;
          } else {
            cnt--;
          }
        }
      }
      if (ok){
        cout << "YES" << "\n";
      } else {
        cout << "NO" << "\n";
      }
    }
  }
}