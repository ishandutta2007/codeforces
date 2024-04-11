#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int a, b;
    cin >> a >> b;
    if (gcd(a, b) > 1){
      cout << "Infinite" << endl;
    } else {
      cout << "Finite" << endl;
    }
  }
}