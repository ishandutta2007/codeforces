#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int a1, a2, a3;
    cin >> a1 >> a2 >> a3;
    if ((a1 + a2 + a3) % 3 == 0){
      cout << 0 << endl;
    } else {
      cout << 1 << endl;
    }
  }
}