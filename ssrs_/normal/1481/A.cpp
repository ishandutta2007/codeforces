#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int px, py;
    cin >> px >> py;
    string s;
    cin >> s;
    int N = s.size();
    int U = 0, D = 0, R = 0, L = 0;
    for (int j = 0; j < N; j++){
      if (s[j] == 'U'){
        U++;
      }
      if (s[j] == 'D'){
        D++;
      }
      if (s[j] == 'R'){
        R++;
      }
      if (s[j] == 'L'){
        L++;
      }
    }
    bool ok = true;
    if (py > 0 && py > U){
      ok = false;
    }
    if (py < 0 && -py > D){
      ok = false;
    }
    if (px > 0 && px > R){
      ok = false;
    }
    if (px < 0 && -px > L){
      ok = false;
    }
    if (ok){
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}