#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    long long all;
    cout << "? " << 1 << ' ' << n << endl;
    cin >> all;
    int tv = 0, fv = n;
    while (fv - tv > 1){
      int mid = (tv + fv) / 2;
      cout << "? " << 1 << ' ' << mid << endl;
      long long res;
      cin >> res;
      if (res == 0){
        tv = mid;
      } else {
        fv = mid;
      }
    }
    tv--;
    long long res;
    cout << "? " << tv + 2 << ' ' << n << endl;
    cin >> res;
    long long A = all - res + 1;
    long long R = all - A * (A - 1) / 2;
    int tv2 = 0, fv2 = n;
    while (fv2 - tv2 > 1){
      long long mid = (tv2 + fv2) / 2;
      if (mid * (mid - 1) / 2 <= R){
        tv2 = mid;
      } else {
        fv2 = mid;
      }
    }
    long long B = tv2;
    cout << "! " << tv + 1 << ' ' << tv + A + 1 << ' ' << tv + A + B << endl;
  }
}