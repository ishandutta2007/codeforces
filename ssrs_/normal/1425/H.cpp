#include <bits/stdc++.h>
using namespace std;
int main(){
  int T;
  cin >> T;
  for (int i = 0; i < T; i++){
    int A, B, C, D;
    cin >> A >> B >> C >> D;
    vector<bool> ok(4, false);
    if ((A + B) % 2 == 0){
      if (A == 0 && D == 0){
        ok[2] = true;
      } else if (B == 0 && C == 0){
        ok[3] = true;
      } else {
        ok[2] = true;
        ok[3] = true;
      }
    } else {
      if (A == 0 && D == 0){
        ok[1] = true;
      } else if (B == 0 && C == 0){
        ok[0] = true;
      } else {
        ok[1] = true;
        ok[0] = true;
      }
    }
    for (int j = 0; j < 4; j++){
      if (ok[j]){
        cout << "Ya";
      } else {
        cout << "Tidak";
      }
      if (j < 3){
        cout << ' ';
      }
    }
    cout << endl;
  }
}