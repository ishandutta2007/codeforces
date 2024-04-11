#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int a, b, c;
    cin >> a >> b >> c;
    if (b == 0){
      if (a == 0){
        for (int j = 0; j <= c; j++){
          cout << 1;
        }
        cout << endl;
      } else {
        for (int j = 0; j <= a; j++){
          cout << 0;
        }
        cout << endl;
      }
      continue;
    }
    vector<int> r(b + 1);
    for (int j = 0; j <= b - 2; j++){
      r[j] = 1;
    }
    if ((b - 1) % 2 == 0){
      r[b - 1] = a + 1;
      r[b] = c + 1;
    } else {
      r[b - 1] = c + 1;
      r[b] = a + 1;
    }
    for (int j = 0; j <= b; j++){
      if (j % 2 == 0){
        for (int k = 0; k < r[j]; k++){
          cout << 0;
        }
      } else {
        for (int k = 0; k < r[j]; k++){
          cout << 1;
        }
      }
    }
    cout << endl;
  }
}