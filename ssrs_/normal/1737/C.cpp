#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    int r1, c1, r2, c2, r3, c3;
    cin >> r1 >> c1 >> r2 >> c2 >> r3 >> c3;
    int x, y;
    cin >> x >> y;
    if (abs(r1 - r2) + abs(c1 - c2) == 2){
      swap(r1, r3);
      swap(c1, c3);
    }
    if (abs(r1 - r3) + abs(c1 - c3) == 2){
      swap(r1, r2);
      swap(c1, c2);
    }
    if ((r1 == 1 || r1 == n) && (c1 == 1 || c1 == n)){
      if (x == r1 || y == c1){
        cout << "YES" << endl;
      } else {
        cout << "NO" << endl;
      }
    } else {
      if (x % 2 == r1 % 2 || y % 2 == c1 % 2){
        cout << "YES" << endl;
      } else {
        cout << "NO" << endl;
      }
    }
  }
}