#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    string S;
    cin >> S;
    if (n % 2 == 0){
      bool b = false;
      for (int j = 1; j < n; j += 2){
        if ((S[j] - '0') % 2 == 0){
          b = true;
        }
      }
      if (b){
        cout << 2 << endl;
      } else {
        cout << 1 << endl;
      }
    } else {
      bool a = false;
      for (int j = 0; j < n; j += 2){
        if ((S[j] - '0') % 2 == 1){
          a = true;
        }
      }
      if (a){
        cout << 1 << endl;
      } else {
        cout << 2 << endl;
      }
    }
  }
}