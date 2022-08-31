#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int l, r;
    cin >> l >> r;
    if (r >= 2 * l - 1){
      cout << (r - 1) / 2 << "\n";
    } else {
      cout << r - l << "\n";
    }
  }
}