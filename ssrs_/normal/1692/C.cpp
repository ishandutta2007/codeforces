#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    vector<string> S(8);
    for (int j = 0; j < 8; j++){
      cin >> S[j];
    }
    int r, c;
    for (int j = 1; j < 7; j++){
      for (int k = 1; k < 7; k++){
        int cnt = 0;
        for (int x = j - 1; x <= j + 1; x++){
          for (int y = k - 1; y <= k + 1; y++){
            if (S[x][y] == '#'){
              cnt++;
            }
          }
        }
        if (cnt == 5){
          r = j;
          c = k;
        }
      }
    }
    cout << r + 1 << ' ' << c + 1 << endl;
  }
}