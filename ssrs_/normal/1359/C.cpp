#include <bits/stdc++.h>
using namespace std;
int main(){
  int T;
  cin >> T;
  for (int i = 0; i < T; i++){
    long long h, c, t;
    cin >> h >> c >> t;
    if (t + t <= h + c){
      cout << 2 << endl;
    } else {
      long long tv = 0;
      long long fv = 1000000;
      bool exact = false;
      while (fv - tv > 1){
        long long mv = (tv + fv) / 2;
        long long L = mv * (h - c);
        long long R = (t - c) * (2 * mv - 1);
        if (L == R){
          cout << mv * 2 - 1 << endl;
          exact = true;
          break;
        } else if (L > R){
          tv = mv;
        } else {
          fv = mv;
        }
      }
      if (!exact){
        long long A = tv * (h - c) * (2 * fv - 1);
        long long C = (t - c) * (2 * tv - 1) * (2 * fv - 1);
        long long B = fv * (h - c) * (2 * tv - 1);
        if (A - C <= C - B){
          cout << 2 * tv - 1 << endl;
        } else {
          cout << 2 * fv - 1 << endl;
        }
      }
    }
  }
}