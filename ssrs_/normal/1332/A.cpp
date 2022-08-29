#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int x, y, x1, y1, x2, y2;
    cin >> x >> y >> x1 >> y1 >> x2 >> y2;
    if (x1 == x2 && (a > 0 || b > 0)){
      cout << "NO" << endl;
    } else if (y1 == y2 && (c > 0 || d > 0)){
      cout << "NO" << endl;
    } else if (x - x1 < a - b){
      cout << "NO" << endl;
    } else if (x2 - x < b - a){
      cout << "NO" << endl;
    } else if (y - y1 < c - d){
      cout << "NO" << endl;
    } else if (y2 - y < d - c){
      cout << "NO" << endl;
    } else {
      cout << "YES" << endl;
    }
  }
}