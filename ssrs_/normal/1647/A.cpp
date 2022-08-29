#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    if (n % 3 == 0){
      for (int j = 0; j < n / 3; j++){
        cout << "21";
      }
    }
    if (n % 3 == 1){
      cout << "1";
      for (int j = 0; j < n / 3; j++){
        cout << "21";
      }
    }
    if (n % 3 == 2){
      for (int j = 0; j < n / 3; j++){
        cout << "21";
      }
      cout << "2";
    }
    cout << endl;
  }
}