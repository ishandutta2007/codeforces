#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int a00, a01;
    cin >> a00 >> a01;
    int a10, a11;
    cin >> a10 >> a11;
    if (a00 == 0 && a01 == 0 && a10 == 0 && a11 == 0){
      cout << 0 << endl;
    } else if (a00 == 1 && a01 == 1 && a10 == 1 && a11 == 1){
      cout << 2 << endl;
    } else {
      cout << 1 << endl;
    }
  }
}