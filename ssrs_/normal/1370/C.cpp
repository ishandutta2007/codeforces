#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    if (n == 1){
      cout << "FastestFinger" << endl;
    } else if (n % 2 == 1){
      cout << "Ashishgup" << endl;
    } else {
      int a = __builtin_ctz(n);
      if (n == (1 << a)){
        if (n == 2){
          cout << "Ashishgup" << endl;
        } else {
          cout << "FastestFinger" << endl;
        }
      } else {
        if (a != 1){
          cout << "Ashishgup" << endl;
        } else {
          int b = n / (1 << a);
          bool prime = true;
          for (int j = 2; j * j <= b; j++){
            if (b % j == 0){
              prime = false;
              break;
            }
          }
          if (prime){
            cout << "FastestFinger" << endl;
          } else {
            cout << "Ashishgup" << endl;
          }
        }
      }
    }
  }
}