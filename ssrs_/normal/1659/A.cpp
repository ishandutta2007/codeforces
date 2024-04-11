#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, r, b;
    cin >> n >> r >> b;
    for (int j = 0; j <= b; j++){
      for (int k = 0; k < r / (b + 1); k++){
        cout << 'R';
      }
      if (j < r % (b + 1)){
        cout << 'R';
      }
      if (j < b){
        cout << 'B';
      }
    }
    cout << endl;
  }
}