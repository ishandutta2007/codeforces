#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    long long x;
    cin >> x;
    bool ok = false;
    for (long long j = 1; j <= 10000; j++){
      long long y = x - j * j * j;
      if (y > 0){
        long long tv = 0, fv = 10000;
        while (fv - tv > 1){
          long long mid = (tv + fv) / 2;
          if (y >= mid * mid * mid){
            tv = mid;
          } else {
            fv = mid;
          }
        }
        if (y == tv * tv * tv){
          ok = true;
        }
      }
    }
    if (ok){
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}