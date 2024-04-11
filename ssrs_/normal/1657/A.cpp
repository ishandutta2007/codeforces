#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int x, y;
    cin >> x >> y;
    if (x == 0 && y == 0){
      cout << 0 << endl;
    } else {
      bool ok = false;
      for (int j = 1; j * j <= x * x + y * y; j++){
        if (j * j == x * x + y * y){
          ok = true;
        }
      }
      if (ok){
        cout << 1 << endl;
      } else {
        cout << 2 << endl;
      }
    }
  }
}