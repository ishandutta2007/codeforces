#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, k;
    cin >> n >> k;
    if (k == 1){
      cout << "YES" << endl;
      for (int j = 1; j <= n; j++){
        cout << j << endl;
      }
    } else if (k >= 2 && n % 2 == 1){
      cout << "NO" << endl;
    } else {
      cout << "YES" << endl;
      for (int j = 0; j < n / 2; j++){
        for (int l = 0; l < k; l++){
          cout << j * k * 2 + l * 2 + 1;
          if (l < k - 1){
            cout << ' ';
          }
        }
        cout << endl;
      }
      for (int j = 0; j < n / 2; j++){
        for (int l = 0; l < k; l++){
          cout << j * k * 2 + l * 2 + 2;
          if (l < k - 1){
            cout << ' ';
          }
        }
        cout << endl;
      }
    }
  }
}