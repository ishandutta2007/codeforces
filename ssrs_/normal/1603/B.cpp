#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    long long x, y;
    cin >> x >> y;
    if (x > y){
      cout << x + y << "\n";
    } else {
      cout << (y / x * x + y) / 2 << "\n";
    }
  }
}