#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int x, y;
    cin >> x >> y;
    if ((x + y) % 2 == 1){
      cout << -1 << ' ' << -1 << endl;
    } else if (x % 2 == 0 && y % 2 == 0){
      cout << x / 2 << ' ' << y / 2 << endl;
    } else {
      cout << x / 2 << ' ' << y / 2 + 1 << endl;
    }
  }
}