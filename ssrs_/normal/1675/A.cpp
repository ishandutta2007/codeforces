#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    if (a + c >= x && b + c >= y && a + b + c >= x + y){
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}