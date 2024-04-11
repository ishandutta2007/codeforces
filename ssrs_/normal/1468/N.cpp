#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int c1, c2, c3;
    cin >> c1 >> c2 >> c3;
    int a1, a2, a3, a4, a5;
    cin >> a1 >> a2 >> a3 >> a4 >> a5;
    c1 -= a1;
    c2 -= a2;
    c3 -= a3;
    if (c1 < 0 || c2 < 0 || c3 < 0){
      cout << "NO" << endl;
    } else {
      if (c1 < a4){
        c3 -= a4 - c1;
      }
      if (c2 <= a5){
        c3 -= a5 - c2;
      }
      if (c3 >= 0){
        cout << "YES" << endl;
      } else {
        cout << "NO" << endl;
      }
    }
  }
}