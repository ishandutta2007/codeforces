#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    int tv = 0, fv = 30000;
    while (fv - tv > 1){
      long long mid = (tv + fv) / 2;
      if (mid * mid * 2 + mid * 2 + 1 <= n){
        tv = mid;
      } else {
        fv = mid;
      }
    }
    cout << tv << endl;
  }
}