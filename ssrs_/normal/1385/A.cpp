#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int x, y, z;
    cin >> x >> y >> z;
    if (x == y && x >= z){
      cout << "YES" << endl;
      cout << x << ' ' << z << ' ' << z << endl;
    } else if (y == z && y >= x){
      cout << "YES" << endl;
      cout << x << ' ' << x << ' ' << z << endl;
    } else if (z == x && z >= y){
      cout << "YES" << endl;
      cout << y << ' ' << z << ' ' << y << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}