#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int h, w;
    cin >> h >> w;
    vector<vector<char>> c(h, vector<char>(w, '0'));
    c[0][0] = '1';
    c[0][w - 1] = '1';
    c[h - 1][0] = '1';
    c[h - 1][w - 1] = '1';
    for (int j = 2; j < w - 2; j += 2){
      c[0][j] = '1';
      c[h - 1][j] = '1';
    }
    for (int j = 2; j < h - 2; j += 2){
      c[j][0] = '1';
      c[j][w - 1] = '1';
    }
    for (int j = 0; j < h; j++){
      for (int k = 0; k < w; k++){
        cout << c[j][k];
      }
      cout << endl;
    }
    cout << endl;
  }
}