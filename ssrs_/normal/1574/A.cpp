#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    for (int j = 0; j < n; j++){
      for (int k = 0; k < n - j; k++){
        cout << "(";
      }
      for (int k = 0; k < n - j; k++){
        cout << ")";
      }
      for (int k = 0; k < j; k++){
        cout << "()";
      }
      cout << endl;
    }
  }
}