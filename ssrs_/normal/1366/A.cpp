#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int a, b;
    cin >> a >> b;
    if (a >= b * 2){
      cout << b << endl;
    } else if (b >= a * 2){
      cout << a << endl;
    } else {
      cout << (a + b) / 3 << endl;
    }
  }
}