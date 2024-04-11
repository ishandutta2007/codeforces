#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<string> s(n);
    for (int j = 0; j < n; j++){
      cin >> s[j];
    }
    vector<int> X(3, 0), O(3, 0);
    int cnt = 0;
    for (int j = 0; j < n; j++){
      for (int k = 0; k < n; k++){
        if (s[j][k] == 'X'){
          X[(j + k) % 3]++;
          cnt++;
        }
        if (s[j][k] == 'O'){
          O[(j + k) % 3]++;
          cnt++;
        }
      }
    }
    int xm, om;
    for (int j = 0; j < 3; j++){
      for (int k = 0; k < 3; k++){
        if (j != k){
          if (O[j] + X[k] <= cnt / 3){
            xm = j;
            om = k;
          }
        }
      }
    }
    for (int j = 0; j < n; j++){
      for (int k = 0; k < n; k++){
        if ((j + k) % 3 == xm && s[j][k] == 'O'){
          s[j][k] = 'X';
        }
        if ((j + k) % 3 == om && s[j][k] == 'X'){
          s[j][k] = 'O';
        }
      }
    }
    for (int j = 0; j < n; j++){
      cout << s[j] << endl;
    }
  }
}