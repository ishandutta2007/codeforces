#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int a1, b1, a2, b2;
    cin >> a1 >> b1 >> a2 >> b2;
    bool flg = false;
    if (a1 == a2 && b1 + b2 == a1) flg = true;
    if (a1 == b2 && b1 + a2 == a1) flg = true;
    if (b1 == a2 && a1 + b2 == b1) flg = true;
    if (b1 == b2 && a1 + a2 == b1) flg = true;
    if (flg){
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  }
}