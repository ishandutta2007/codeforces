#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    long long x, y, a, b;
    cin >> x >> y >> a >> b;
    if (a > b){
      swap(a, b);
    }
    long long tv = 0, fv = 2100000000;
    while (fv - tv > 1){
      long long mid = (tv + fv) / 2;
      bool ok;
      if (x < a * mid || y < a * mid){
        ok = false;
      } else {
        long long x2 = x - a * mid;
        long long y2 = y - a * mid;
        if (a == b){
          ok = true;
        } else {
          long long s = x2 / (b - a) + y2 / (b - a);
          if (s >= mid){
            ok = true;
          } else {
            ok = false;
          }
        }
      }
      if (ok){
        tv = mid;
      } else {
        fv = mid;
      }
    }
    cout << tv << endl;
  }
}