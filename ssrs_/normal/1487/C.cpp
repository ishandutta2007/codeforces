#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    for (int j = 0; j < n; j++){
      for (int k = j + 1; k < n; k++){
        int d = k - j;
        if (n % 2 == 1){
          if (d % 2 == 0){
            cout << 1;
          } else {
            cout << -1;
          }
        } else {
          if (d == n / 2){
            cout << 0;
          } else {
            if (d > n / 2){
              d--;
            }
            if (d % 2 == 0){
              cout << 1;
            } else {
              cout << -1;
            }
          }
        }
        if (j < n - 1){
          cout << ' ';
        }
      }
    }
    cout << endl;
  }
}