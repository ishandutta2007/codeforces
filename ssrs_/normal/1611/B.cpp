#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int a, b;
    cin >> a >> b;
    int tv = 0, fv = min(a, b) + 1;
    while (fv - tv > 1){
      int mid = (tv + fv) / 2;
      int a2 = a - mid;
      int b2 = b - mid;
      if (a2 + b2 >= mid * 2){
        tv = mid;
      } else {
        fv = mid;
      }
    }
    cout << tv << endl;
  }
}