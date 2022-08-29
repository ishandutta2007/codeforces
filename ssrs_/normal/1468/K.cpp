#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    string s;
    cin >> s;
    int N = s.size();
    vector<int> X(N + 1), Y(N + 1);
    X[0] = 0;
    Y[0] = 0;
    for (int j = 0; j < N; j++){
      X[j + 1] = X[j];
      Y[j + 1] = Y[j];
      if (s[j] == 'L'){
        X[j + 1]--;
      }
      if (s[j] == 'R'){
        X[j + 1]++;
      }
      if (s[j] == 'D'){
        Y[j + 1]--;
      }
      if (s[j] == 'U'){
        Y[j + 1]++;
      }
    }
    int ansx = 0, ansy = 0;
    for (int j = 1; j <= N; j++){
      if (!(X[j] == 0 && Y[j] == 0)){
        int tx = X[j], ty = Y[j];
        int x = 0, y = 0;
        for (int k = 0; k < N; k++){
          int x2 = x, y2 = y;
          if (s[k] == 'L'){
            x2--;
          }
          if (s[k] == 'R'){
            x2++;
          }
          if (s[k] == 'D'){
            y2--;
          }
          if (s[k] == 'U'){
            y2++;
          }
          if (!(x2 == tx && y2 == ty)){
            x = x2;
            y = y2;
          }
        }
        if (x == 0 && y == 0){
          ansx = tx;
          ansy = ty;
        }
      }
    }
    cout << ansx << ' ' << ansy << endl;
  }
}