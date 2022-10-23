#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, x, y;
    cin >> n >> x >> y;
    if (x > y){
      swap(x, y);
    }
    if (x >= 1){
      cout << -1 << endl;
    } else if (y == 0){
      cout << -1 << endl;
    } else if ((n - 1) % y != 0){
      cout << -1 << endl;
    } else {
      for (int j = 0; j < n - 1; j++){
        cout << j / y * y + 2;
        if (j < n - 2){
          cout << ' ';
        }
      }
      cout << endl;
    }
  }
}