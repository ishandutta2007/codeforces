#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    if (n % 3 == 2){
      for (int j = 1; j <= n; j++){
        cout << j;
        if (j < n){
          cout << ' ';
        }
      }
      cout << endl;
    } else if (n % 3 == 1){
      cout << 2 << ' ' << 1 << ' ';
      for (int j = 3; j <= n; j++){
        cout << j;
        if (j < n){
          cout << ' ';
        }
      }
      cout << endl;
    } else {
      cout << 2 << ' ' << 1 << ' ' << 4 << ' ' << 3 << ' ';
      for (int j = 5; j <= n; j++){
        cout << j;
        if (j < n){
          cout << ' ';
        }
      }
      cout << endl;
    }
  }
}