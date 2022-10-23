#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    vector<vector<char>> c(8, vector<char>(8));
    for (int j = 0; j < 8; j++){
      for (int k = 0; k < 8; k++){
        cin >> c[j][k];
      }
    }
    bool ok = false;
    for (int j = 0; j < 8; j++){
      if (c[j] == vector<char>(8, 'R')){
        ok = true;
      }
    }
    if (ok){
      cout << 'R' << endl;
    } else {
      cout << 'B' << endl;
    }
  }
}