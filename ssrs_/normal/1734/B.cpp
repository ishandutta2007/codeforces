#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    for (int j = 0; j < n; j++){
      for (int k = 0; k <= j; k++){
        if (k == 0 || k == j){
          cout << 1;
        } else {
          cout << 0;
        }
        if (k < j){
          cout << ' ';
        }
      }
      cout << endl;
    }
  }
}